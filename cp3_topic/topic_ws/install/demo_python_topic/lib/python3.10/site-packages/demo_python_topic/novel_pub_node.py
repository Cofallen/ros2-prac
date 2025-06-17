import rclpy
from rclpy.node import Node
import requests
from example_interfaces.msg import String
from queue import Queue


class NovelPubNode(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
        self.get_logger().info(f"{node_name} 启动！")
        self.novels_queue_ = Queue() # 创建队列  放到最前面
        self.novel_publisher_ = self.create_publisher(String, 'novel', 10)
        self.create_timer(3, self.timer_callback)
    
    def timer_callback(self):
        # self.novel_publisher_.publish()
        if self.novels_queue_.qsize() > 0: 
            line = self.novels_queue_.get()
            msg = String()  # 组装
            msg.data = line
            self.novel_publisher_.publish(msg)
            self.get_logger().info(f"发布： {msg}")
    
    def download(self, url):
        response = requests.get(url)
        response.encoding = 'utf-8'
        text = response.text
        # text.splitlines()
        for line in text.splitlines():
            self.novels_queue_.put(line)
            
        self.get_logger().info(f"download from {url}=> {len(response.text)}")

def main():
    rclpy.init()
    node = NovelPubNode('novel_pub')
    node.download("http://127.0.0.1:8000/novel1.txt")
    
    try :
        rclpy.spin(node)
    except(KeyboardInterrupt):
        node.get_logger().info(f"interrupt!")
    finally :
        node.destroy_node()
        rclpy.shutdown()    