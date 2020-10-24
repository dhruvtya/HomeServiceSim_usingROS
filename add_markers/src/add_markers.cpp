#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <std_msgs/Int16.h>

//Publisher declared globally to be used in callback function
ros::Publisher marker_pub;


//Callback function for the subscriber

void reachCallback(const std_msgs::Int16::ConstPtr& msgconfirm)
{
  ROS_INFO("Received message : [%i]", msgconfirm->data);

  uint32_t shape = visualization_msgs::Marker::CUBE;
  visualization_msgs::Marker marker;

  marker.header.frame_id = "/map";
  marker.header.stamp = ros::Time::now();

  marker.ns = "basic_shapes";
  marker.id = 0;
  marker.type = shape;

  if(msgconfirm->data==1){
    ROS_INFO("Deleting Pick Up Marker");
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);
  }
  else if(msgconfirm->data==2){
  
    marker.scale.x = 0.2;
    marker.scale.y = 0.2;
    marker.scale.z = 0.2;

    marker.color.r = 1.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.action = visualization_msgs::Marker::ADD;

    marker.pose.position.x = 3;
    marker.pose.position.y = -8;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
   
    ROS_INFO("Publishing Drop Off Marker");
 
    marker_pub.publish(marker);

  }
}




int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);


//Subscriber definition to the pub_confirm publisher topic reachconfirm

  ros::Subscriber reach_sub = n.subscribe("/reachconfirm",10,reachCallback);


  uint32_t shape = visualization_msgs::Marker::CUBE;

  ros::Duration(2.0).sleep();


    visualization_msgs::Marker marker;

    marker.header.frame_id = "/map";
    marker.header.stamp = ros::Time::now();

    marker.ns = "basic_shapes";
    marker.id = 0;

    marker.type = shape;

    marker.action = visualization_msgs::Marker::ADD;

    marker.pose.position.x = 0;
    marker.pose.position.y = -4;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    marker.scale.x = 0.2;
    marker.scale.y = 0.2;
    marker.scale.z = 0.2;

    marker.color.r = 1.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    ROS_INFO("Publishing Pick Up Marker");
    marker_pub.publish(marker);
    
    ros::spin();


}

