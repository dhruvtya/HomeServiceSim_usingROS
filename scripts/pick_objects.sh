#!/bin/sh

xterm  -e  " roslaunch my_robot world.launch" &
sleep 5
xterm  -e  " roslaunch my_robot amcl_demo.launch" &
sleep 5
xterm  -e  " roslaunch rvizconfig view_navigation.launch" &
sleep 5
xterm  -e  " rosrun pick_objects pick_objects"
