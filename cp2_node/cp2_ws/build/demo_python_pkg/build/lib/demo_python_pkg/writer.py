import rclpy
from rclpy.node import Node

from demo_python_pkg.person_node import PersonNode

class writer(PersonNode,Node): 
    def __init__(self,node_name:str,name:str,age:int, book: str):
        super().__init__(node_name ,name, age) # 调用父类
        self.book = book
        self.node_name = node_name
        
    def write(self, content):
        print(f"{self.name} is writting {content}")
        self.get_logger().info(f"{self.node_name} is writting {content}")
        
def main():
    rclpy.init()
    node = writer('wroter_node','Python Programming', 30, 'book1')
    node.write('Hello, World!')
    node.eat('banana')
    
    rclpy.spin(node)
    rclpy.shutdown()