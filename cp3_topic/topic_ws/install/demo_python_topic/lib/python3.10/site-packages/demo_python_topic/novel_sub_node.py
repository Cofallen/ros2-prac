import espeakng
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String
from queue import Queue
import threading
import time


class NovelSubNode(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
        self.get_logger().info(f"{node_name} is running !!")
        self.novels_queue_ =  Queue()
        self.novel_subscriber_ = self.create_subscription(String, 'novel', self.novel_callback, 10)
        self.speech_thread_ = threading.Thread(target=self.speaker_thread)
        self.speech_thread_.start() # 手动启动
        
    def novel_callback(self, msg:String):
        self.novels_queue_.put(msg.data)
        
    def speaker_thread(self):
        speaker = espeakng.Speaker()
        speaker.voice = 'en'
        
        while rclpy.ok(): # 检查当前上下文ROS 是否 OK
            if self.novels_queue_.qsize() > 0:
                text = self.novels_queue_.get()
                self.get_logger().info(f"read: {text}")
                speaker.say(text)   # 说
                speaker.wait()      # 等待说完
                
            else:
                # 当前线程休眠1s
                time.sleep(1)
                
def main():
    rclpy.init()
    node = NovelSubNode('novel_sub')
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info(f"interrupt!!")
    finally:
        rclpy.shutdown()