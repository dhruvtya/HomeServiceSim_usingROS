#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <std_msgs/Int16.h>


typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){

  ros::init(argc, argv, "pick_objects");

//Initializing the nodehandle

  ros::NodeHandle n;

//Publisher for confirming that the robot has reached the goal

  ros::Publisher pub_confirm=n.advertise<std_msgs::Int16>("/reachconfirm", 10);
// Let it sleep to initialise

//  ros::Duration(2.0).sleep();

// Confirmation message
    std_msgs::Int16 confirmmsg;
    confirmmsg.data = 1;
//

  MoveBaseClient ac("move_base", true);


  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;


  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();


  goal.target_pose.pose.position.x = 0.0;
  goal.target_pose.pose.position.y = -4.0;
  goal.target_pose.pose.orientation.w = 0.1;


  ROS_INFO("Sending Pick Up goal");
  ac.sendGoal(goal);


  ac.waitForResult();


  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Reached Pick Up Zone");

//Publish to confirm reaching pick up zone
    pub_confirm.publish(confirmmsg);

    ros::spinOnce();
  }
  else
    ROS_INFO("The base failed to reach the Pick Up");

  ROS_INFO("Sleeping for 5");

  ros::Duration(5.0).sleep();

  move_base_msgs::MoveBaseGoal dropgoal;

  dropgoal.target_pose.header.frame_id = "map";
  dropgoal.target_pose.header.stamp = ros::Time::now();

  dropgoal.target_pose.pose.position.x = 3.2;
  dropgoal.target_pose.pose.position.y = -8.0;
  dropgoal.target_pose.pose.orientation.w = 1.5707;

// Add confirm publisher message for drop off
  confirmmsg.data = 2;


  ROS_INFO("Sending Drop Off goal");
  ac.sendGoal(dropgoal);


  ac.waitForResult();


  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Reached Drop Off Zone");
//Publish to confirm reaching drop off zone
    pub_confirm.publish(confirmmsg);

  }
  else
    ROS_INFO("The base failed to reach the Drop Off");


  ros::spin();

  return 0;
}
