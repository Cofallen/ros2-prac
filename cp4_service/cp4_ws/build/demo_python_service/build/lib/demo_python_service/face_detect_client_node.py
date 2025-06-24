import rclpy
from rclpy.node import Node
from chap4_interface.srv import FaceDetector
import cv2
from cv_bridge import CvBridge
import time
import os
from ament_index_python.packages import get_package_share_directory
import face_recognition

class FaceDetectClientNode(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
        self.bridge = CvBridge()
        self.default_image_path = os.path.join(get_package_share_directory('demo_python_service'), 'resource/test.jpeg')
        self.get_logger().info(f"人脸检测客户端节点已启动，默认图像路径: {self.default_image_path}")
        self.client = self.create_client(FaceDetector, 'face_detect')
        self.image = cv2.imread(self.default_image_path)
            
    def send_request(self):
        # 1. 判断服务端是否在线
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info(f"等待服务端 {self.client.srv_name} 在线...")
        # 2. 构造Request对象
        request = FaceDetector.Request()
        request.image = self.bridge.cv2_to_imgmsg(self.image)
        # 3. 发送请求并等待处理完成
        future = self.client.call_async(request) # 现在的future 并没有包含响应结果，需要等待服务端处理完成才会把结果放到future中
        # while not future.done():
        #     time.sleep(1.0) # 休眠当前线程，等待服务端处理完成，造成当前线程无法再接受来自服务端的返回，导致永远没有办法完成=》future.done() 永远为False
        
        # 下面选一个可以 <1>
        # rclpy.spin_until_future_complete(self, future) # 等待服务端返回响应
        # response = future.result() # 获取响应结果
        # self.get_logger().info(f"接收到响应：共有{response.number}张人脸，耗时 {response.use_time} 秒")
        # self.show_response(response)
        # <2>
        def result_callback(result_future):
            response = result_future.result()  # 获取响应结果
            self.get_logger().info(f"接收到响应：共有{response.number}张人脸，耗时 {response.use_time} 秒")
            self.show_response(response)  # 显示响应结果
            
        future.add_done_callback(result_callback)  # 添加回调函数，当服务端返回响应时会调用该函数         

    def show_response(self, response):
        for i in range(response.number):
            top = response.top[i]
            right = response.right[i]
            bottom = response.bottom[i]
            left = response.left[i]
             
        cv2.rectangle(self.image, (left, top), (right, bottom), (255, 0, 0), 4)
            
        cv2.imshow("face detection", self.image) 
        cv2.waitKey(0) # 阻塞，会导致程序无法继续执行
        cv2.destroyAllWindows()
        
def main():
    rclpy.init()
    node = FaceDetectClientNode(node_name='face_detect_client_node')
    try:
        node.send_request()  # 发送请求
        rclpy.spin(node=node)
    except KeyboardInterrupt:
        node.get_logger().info("人脸检测客户端节点已停止")
    finally:
        pass
    rclpy.shutdown()