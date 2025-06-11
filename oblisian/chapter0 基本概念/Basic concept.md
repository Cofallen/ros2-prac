#turtlesim

> 我们将介绍ROS2中控制海龟模拟器的基本命令。这些命令包括启动海龟模拟器、控制海龟移动、查看海龟信息等。
 注意：以下命令在ROS2 Foxy或更高版本中测试。


以下是ROS2中控制海龟模拟器（turtlesim）的**基本命令全集**，涵盖节点、话题、服务、参数、动作等核心操作：

---

### 1. **启动海龟模拟器**
```bash
# 启动模拟器节点
ros2 run turtlesim turtlesim_node

# 启动键盘控制节点（新终端）
ros2 run turtlesim turtle_teleop_key
```
> **键盘控制**：运行`teleop`后，用方向键移动海龟。

---

### 2. **节点管理**
```bash
# 查看所有活跃节点
ros2 node list

# 查看节点详细信息（如/turtlesim）
ros2 node info /turtlesim
```

---

### 3. **话题（Topic）操作**
```bash
# 列出所有话题
ros2 topic list

# 实时查看海龟位姿
ros2 topic echo /turtle1/pose

# 查看话题消息类型
ros2 topic info /turtle1/cmd_vel

# 手动发布移动指令（线速度2.0，角速度1.0）
ros2 topic pub -r 1 /turtle1/cmd_vel geometry_msgs/msg/Twist \
  "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.0}}"
```

---

### 4. **服务（Service）操作**
```bash
# 列出所有服务
ros2 service list

# 生成新海龟（名为turtle2，位置(5.5, 5.5)）
ros2 service call /spawn turtlesim/srv/Spawn "{x: 5.5, y: 5.5, theta: 0.0, name: 'turtle2'}"

# 清除轨迹
ros2 service call /clear std_srvs/srv/Empty
```

---

### 5. **参数（Parameter）管理**
```bash
# 查看所有参数
ros2 param list

# 获取背景颜色参数
ros2 param get /turtlesim background_r

# 修改背景颜色（RGB设为100,100,100）
ros2 param set /turtlesim background_r 100
ros2 param set /turtlesim background_g 100
ros2 param set /turtlesim background_b 100
```

---

### 6. **动作（Action）控制**
```bash
# 列出所有动作
ros2 action list

# 让海龟旋转到绝对角度（如90度=1.57弧度）
ros2 action send_goal /turtle1/rotate_absolute turtlesim/action/RotateAbsolute \
  "{theta: 1.57}"

# 带反馈和结果的目标
ros2 action send_goal --feedback /turtle1/rotate_absolute ... 
```

---

### 7. **高级工具**
```bash
# 记录话题数据（保存到当前目录）
ros2 bag record /turtle1/cmd_vel /turtle1/pose

# 重放数据
ros2 bag play rosbag2_YYYY_MM_DD...

# 查看消息结构
ros2 interface show geometry_msgs/msg/Twist
```

---

### 关键说明：
1. **命名空间**：多海龟时使用`/turtle2/cmd_vel`等区分目标。
2. **实时控制**：`teleop`节点默认控制`turtle1`，新海龟需单独发布指令。
3. **动作反馈**：`rotate_absolute`动作用于精确转向，支持进度反馈。

> 通过组合这些命令，可完成海龟的移动、转向、多机控制、环境交互等完整实验！