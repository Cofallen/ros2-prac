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

# c++

```bash
 ros2 pkg create --build-type ament_cmake --license Apache-2.0 demo_cpp_pkg

 cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node/node/demo_cpp_pkg$ mkdir build && cd build
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node/node/demo_cpp_pkg/build$ cmake ..
```

`cmakelists.txt` 增加如下关系

```bash
# find dependencies
find_package(ament_cmake REQUIRED)

# Find the required ROS 2 packages
find_package(rclcpp REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(cpp_node src/cpp_node.cpp)

# 包含连接
# target_include_directories(cpp_node 
#   PUBLIC ${rclcpp_INCLUDE_DIRS} )
# target_link_libraries(cpp_node 
#   ${rclcpp_LIBRARIES} )
ament_target_dependencies(cpp_node rclcpp) # 等效上面两个

install(TARGETS cpp_node
 DESTINATION lib/${PROJECT_NAME}
)
```

注意，

```bash
ament_package()

# 应位于最后，表示 ament 命令结束，即该命令后面不应该有表达式
```

构建路径 应位于包的同级目录/上一级目录
```bash
colcon build

# 可执行文件目录
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node/node/build/demo_cpp_pkg$ ./cpp_node 

# 查看二进制文件连接情况
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node/node/build/demo_cpp_pkg$ ldd cpp_node 
```

## 一些报错

```bash
# 原因：环境变量未增加
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node$ ros2 run demo_cpp_pkg cpp_node
Package 'demo_cpp_pkg' not found
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node$ printenv | grep -i ament
AMENT_PREFIX_PATH=/opt/ros/humble
# 解决
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node/node$ source install/setup.bash 
# 结果
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node/node$ printenv | grep -i ament
AMENT_PREFIX_PATH=/home/cofallen/Code/ros2/cp2_node/node/install/demo_cpp_pkg:/home/cofallen/Code/ros2/cp2_node/py/install/demo_python_pkg:/opt/ros/humble
```


```bash
# 
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node/node$ ros2 run demo_cpp_pkg cpp_node
No executable found
# 打印包路径
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node/node$ ros2 pkg prefix demo_cpp_pkg
/home/cofallen/Code/ros2/cp2_node/node/install/demo_cpp_pkg
# 发现未把二进制文件拷贝到.../lib下
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node/node/install/demo_cpp_pkg$ ls
share
# 在 cmake中增加
install(TARGETS cpp_node
 DESTINATION lib/${PROJECT_NAME}
)
# 启动
ros2 run demo_cpp_pkg cpp_node 
``` 

ros2启动会从 `install ` 文件夹下查找可执行文件

## workspace

```bash
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node$ mkdir -p cp2_ws/src
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node$ mv node/demo_cpp_pkg/ cp2_ws/src/
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node/node$ rm -rf build/ log/ install/
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node/cp2_ws/src$ cd ..
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node/cp2_ws$ colcon build
```

设置依赖关系/指定构建

```bash
cofallen@cofallen-NucBox-M6:~/Code/ros2/cp2_node/cp2_ws$ colcon build 
--packages-select demo_cpp_pkg

# 若cpp为py的依赖项
# 在 py 下的 package.xml 中增加
  <depend>demo_cpp_pkg</depend>

```

## 多进程

这里我使用shell脚本创建多文件 

```shell
for i in {0..2}; do
  echo "chapter $i: xxx" > "novel$i.txt"
done
# 或者
for ((i=0; i<3; i++)); do
  echo "chapter $i: xxx" > "novel$i.txt"
done
```

```bash
# 在当前目录下，将所有文件上传作为网盘网页
python -m http.server 
```

```bash
# c++ 使用第三方库
git clone https://gitee.com/ohhuo/cpp-httplib.git
# cmakelist 增加
include_directories(include)
```

注意，使用第三方库`cpp-httplib ` 出现的问题。

1. 无法连接服务器。
   这里我加入了错误排查。
  ```c++
  void download(const std::string &host, const std::string &path, const std::function<void(const std::string &, const std::string&)> &callback_word_count) {
        std::cout << "thread id: " << std::this_thread::get_id() << std::endl;

        try
        {
            httplib::Client client(host);
            client.set_connection_timeout(5);
            client.set_read_timeout(5);
            
            auto response = client.Get(path);

            if (response)
            {
                std::cout << "status id: " << response->status << std::endl;
                if (response->status == 200)
                {
                    callback_word_count(path,response->body);
                } else {
                    std::cerr << "http请求错误" <<  response->status <<std::endl;
                }
            } else {
                std::cerr << "无法连接到服务器" << std::endl;
            }
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    };
  ```
实际输出为 `无法连接到服务器`。

原因：当使用 cpp-httplib 库时，主机名应该不包含协议前缀(http://)和尾部斜杠。

解决方案
修改 main 函数中的 start_download 调用方式。

2. 如果没有打开网页，可以查看监听端口。

```bash
netstat -tuln | grep 8000
```