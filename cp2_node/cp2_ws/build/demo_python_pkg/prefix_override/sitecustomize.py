import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/cofallen/Code/ros2/cp2_node/cp2_ws/install/demo_python_pkg'
