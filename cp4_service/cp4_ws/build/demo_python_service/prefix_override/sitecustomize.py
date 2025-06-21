import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/cofallen/Code/ros2/cp4_service/cp4_ws/install/demo_python_service'
