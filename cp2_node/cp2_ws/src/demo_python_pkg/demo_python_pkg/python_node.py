import rclpy
from rclpy.node import Node

def main():
    rclpy.init()
    node = Node('py_node')
    node.get_logger().info('CP2 Node has been started.')
    # node.get_logger().warn('CP2 Node has been started.')
    
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        print('Node has been stopped by user.')
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
