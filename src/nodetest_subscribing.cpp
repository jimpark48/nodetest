#include "ros/ros.h"
#include "nodetest/msgnodetest.h"

void msgCallbacking(const nodetest::msgnodetest::ConstPtr& msg) {
	ROS_INFO("zzzz");
	std::cout << msg << std::endl;
	ROS_INFO("receive~ msg : %d", msg->data);
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "node_subscriber");
	ros::NodeHandle nh;

	ros::Subscriber node_testing_sub = nh.subscribe("nodetesting", 1000, msgCallbacking);

	ros::spin();
	return 0;
}
