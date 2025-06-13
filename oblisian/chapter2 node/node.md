#node
## 文件格式
> 直接按照文件运行即可。

若c++插件无法加载，将 `c_cpp_properties.json`修改为
```javascipt
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "${AMENT_PREFIX_PATH}/include/**"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c17",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```
> 原因： `AMENT_PERFIX_PATH`作为环境变量，未被插件读取。
## 包格式
```bash
#创建包
ros2 pkg create  --build-type ament_python --license Apache-2.0 demo_python_pkg

# 在<pkg_name/pkg_name>的包含__init__.py的路径下建立你的节点文件.py
# 包含
# 在setup.py的entry_points写入 '<exe_name> = pkg_name.file_name:main'

# package.xml 功能报清单文件 添加依赖
  <depend>rclpy</depend>

colcon build

# 若直接运行的话需要修改增加python的环境变量
export PYTHONPATH=/home/cofallen/Code/ros2/cp2_node/py/install/demo_python_pkg/lib/python3.10/site-packages:$PYTHONPATH
# 或者用给的脚本更改 推荐
source cp2_node/py/install/setup.bash 
# 会修改很多环境变量，如 在其中的lib/xx 作为可执行文件
cofallen@cofallen-NucBox-M6:~/Code/ros2$ printenv | grep -i ament
AMENT_PREFIX_PATH=/home/cofallen/Code/ros2/cp2_node/py/install/demo_python_pkg:/opt/ros/humble

# 启动节点
ros2 run demo_python_pkg python_node 
```

每次运行的代码位于
```bash
/home/cofallen/Code/ros2/cp2_node/py/install/demo_python_pkg/lib/python3.10/site-packages/<pkg_name>

# 因此每次修改代码后需要
colcon build
```