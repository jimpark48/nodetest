#include "ros/ros.h"
#include "nodetest/msgnodetest.h"
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main(int argc, char **argv) {
	ros::init(argc, argv, "node_publisher");
	ros::NodeHandle nh;

	ros::Publisher node_testing_pub = nh.advertise<nodetest::msgnodetest>("nodetesting", 1000);
	
	ros::Rate loop_rate(1);
	
	int count = 0;
	while(ros::ok()) {
		nodetest::msgnodetest msg;
		msg.data = count;
		
		ROS_INFO("send~ msg : %d", count);
		node_testing_pub.publish(msg);
        //nodetesting_pub.publish(msg);

		loop_rate.sleep();
		++count;
	}
	return 0;
/*	int count = 0;
	while(ros::ok()) {
		Eigen::MatrixXd A(3, 2);
		A << 1, 2, 2, 3, 3, 4;
		Eigen::MatrixXd B=A.transpose();
		std::cout << "Matrix A:\n" << A << std::endl;	
		ROS_INFO("count : %d", count);

		loop_rate.sleep();	
		++count;		
	}*/
	return 0;

}
