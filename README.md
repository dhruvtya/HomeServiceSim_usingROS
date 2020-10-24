# HomeServiceSim_usingROS
ROS project to practice Navigation in a Home Service Robot Simulation.

### Intro:
In this project, the robot is performing Navigation and AMCL localization as it travels towards a yellow cube (Depicting a virtual Object). 
When the robot reaches the Pick Up Zone of the Cube, the cube disappears and the robot waits 5 seconds to simulate pick up time.
Then the robot travels to the predetermined goal position and drops off the cube there (The cube will appear there instantly to simulate a drop off)

### Staring Position:
![Starting](https://github.com/dhruvtya/HomeServiceSim_usingROS/blob/main/Starting.JPG)

### After Dropping Off Yellow Cube:
![Dropoff](https://github.com/dhruvtya/HomeServiceSim_usingROS/blob/main/Dropoff.JPG)

In the above screenshot, you can see the yellow cube at the robot's position.

### Built on:
ROS Kinetic & Ubuntu 16.04

## Steps to Implement:

#### Have xterm terminal installed (```sudo apt-get install xterm```)

1. Create a Catkin Workspace and clone the individual folders of the repo inside of the 'src' folder.
2. Clone the following packages in the src folder : 
3. http://wiki.ros.org/gmapping
4. http://wiki.ros.org/turtlebot_rviz_launchers
5. http://wiki.ros.org/turtlebot_gazebo
6. Change directory back to the catkin workspace and execute ```catkin_make```
7. On the terminal itself, change to the scripts folder inside src.
8. ```chmod +x home_service.sh```
9. ```./home_service.sh```
10. This command above will start the whole process and the last 2 terminals will inform you which zone the robot has reached.
