#!/bin/sh

xterm  -e  " roslaunch my_robot world.launch" &
sleep 5
xterm  -e  " rosrun gmapping slam_gmapping _base_frame:=robot_footprint" &
sleep 5
xterm  -e  " roslaunch rvizconfig view_navigation.launch" &
sleep 5
xterm  -e  " roslaunch turtlebot_teleop keyboard_teleop.launch"
