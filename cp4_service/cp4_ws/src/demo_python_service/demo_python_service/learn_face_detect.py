import face_recognition
import cv2
from sensor_msgs.msg import Image
from ament_index_python.packages import get_package_share_directory # 获取功能包绝对路径
import os

def main():
    # 获取图片的真实路径 /home/cofallen/Code/ros2/cp4_service/cp4_ws/install/demo_python_service/share/demo_python_service
    default_image_path = os.path.join(get_package_share_directory("demo_python_service"), 'resource/default.jpeg')
    print(f"图片的真实路径：{default_image_path}")
    
    # 使用 cv2 加载图片
    image = cv2.imread(default_image_path)
    
    # 检测人脸
    face_locations = face_recognition.face_locations(image, number_of_times_to_upsample=1, model='hog')
    
    # 绘制人脸框
    for top, right, bottom, left in face_locations:
        cv2.rectangle(image, (left, top), (right, bottom), (255, 0, 0), 4)
        
    # 显示图片
    cv2.imshow("Face Detection", image)
    cv2.waitKey(0)