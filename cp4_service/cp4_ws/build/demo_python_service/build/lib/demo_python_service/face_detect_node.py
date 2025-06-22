import rclpy
from rclpy.node import Node
from chap4_interface.srv import FaceDetector
import cv2
import face_recognition
import os
from ament_index_python.packages import get_package_share_directory
from cv_bridge import CvBridge
import time

class FaceDetectNode(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
        self.service_ = self.create_service(FaceDetector, 'face_detect', self.detect_face_callback)
        self.bridge = CvBridge()
        self.number_of_times_to_upsample = 1
        self.model = 'hog'
        self.default_image_path = os.path.join(get_package_share_directory('demo_python_service'), 'resource/default.jpeg')
        
    def detect_face_callback(self, request:FaceDetector, response):
        if request.image.data:
            cv_image = self.bridge.imgmsg_to_cv2(request.image)
        else:
            cv_image = cv2.imread(self.default_image_path)
            self.get_logger().info(f'没有接收到图像数据，使用默认图像: {self.default_image_path}')
        
        # 这里的cv_image是一个OpenCV格式的图像
        start_time = time.time()
        self.get_logger().info(f'开始检测人脸...')
        face_locations = face_recognition.face_locations(cv_image, self.number_of_times_to_upsample, self.model)
        
        response.use_time = time.time() - start_time
        response.number = len(face_locations)
        for top, right, bottom, left in face_locations:
            response.top.append(top)
            response.right.append(right)
            response.bottom.append(bottom)
            response.left.append(left)
        self.get_logger().info(f'检测到 {len(face_locations)} 张人脸，耗时 {response.use_time:.2f} 秒')
        return response # 必须返回response
        
        
def main():
    rclpy.init()
    node = FaceDetectNode('face_detect_node')
    rclpy.spin(node)
    rclpy.shutdown()
