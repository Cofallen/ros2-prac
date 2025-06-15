import rclpy
from rclpy.node import Node

class PersonNode(Node):
    def __init__(self,node_name:str, name_value: str, age: int) -> None:
        super().__init__(node_name)
        self.name = name_value
        self.age = age
        
    def eat(self, food_name: str): 
        """_summary_

        Args:
            food_name (str): _description_
        """
        # print(f"{self.name} is {self.age} years old, eating {food_name}.")
        self.get_logger().info(f"{self.name} is {self.age} years old, eating {food_name}.")
    
class People(PersonNode):
    def __init__(self, name_value: str, age: int) -> None:
        super().__init__(name_value, age)
    
    def sleep(self):
        print(f"{self.name} is sleeping.")
    
    def work(self):
        print(f"{self.name} is working.")
        
        
def main():
    rclpy.init()
    node = PersonNode('rcl_name','aaa', 18)
    node.eat('apple')
    
    peopleNode = People('bbb', 20)
    peopleNode.sleep()
    
    rclpy.spin(node)
    rclpy.shutdown()