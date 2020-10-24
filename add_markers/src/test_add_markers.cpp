#include <ros/ros.h>
#include <visualization_msgs/Marker.h>


int main( int argc, char** argv )
{
  ros::init(argc, argv, "test_add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  ros::Duration(2.0).sleep();


  uint32_t shape = visualization_msgs::Marker::CUBE;


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

  ROS_INFO("Waiting 5 Seconds");
  ros::Duration(5.0).sleep();
   
  ROS_INFO("Deleting Pick Up Marker");
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);

  ROS_INFO("Waiting 5 Seconds");
  ros::Duration(5.0).sleep();

    marker.pose.position.x = 3;
    marker.pose.position.y = -8;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

  ROS_INFO("Publishing Drop Off Marker");
    marker.action = visualization_msgs::Marker::ADD;
    marker_pub.publish(marker);
   
  ros::spin();
  
}

