#!/usr/bin/env python


import rospy
from geometry_msgs.msg import Twist, TwistWithCovarianceStamped
from sensor_msgs.msg import Imu

twist = TwistWithCovarianceStamped()

def callbackTwist(data):
	global twist
	twist.twist.twist.linear = data.linear

	twist.header.frame_id = "imu"
	twist.twist.covariance = [1e-2, 0000, 0000, 0000, 0000, 0000,
				0000, 1e-2, 0000, 0000, 0000, 0000,
				0000, 0000, 1e-2, 0000, 0000, 0000,
				0000, 0000, 0000, 1e-2, 0000, 0000,
				0000, 0000, 0000, 0000, 1e-2, 0000,
				0000, 0000, 0000, 0000, 0000, 1e-2]				

def callbackImu(data):
	global twist
	twist.twist.twist.angular = data.angular_velocity
	twist.header.stamp = data.header.stamp
	
	twist.header.frame_id = "imu"
	twist.twist.covariance = [1e-2, 0000, 0000, 0000, 0000, 0000,
				0000, 1e-2, 0000, 0000, 0000, 0000,
				0000, 0000, 1e-2, 0000, 0000, 0000,
				0000, 0000, 0000, 1e-2, 0000, 0000,
				0000, 0000, 0000, 0000, 1e-2, 0000,
				0000, 0000, 0000, 0000, 0000, 1e-2]

if __name__ == '__main__':

	rospy.init_node("twist_trans")

	rospy.Subscriber("/an_device/Imu", Imu, callbackImu)
	rospy.Subscriber("/an_device/Twist", Twist, callbackTwist)

	pub = rospy.Publisher("/an_device/Twist_Imu", TwistWithCovarianceStamped, queue_size=10)
	
	rate = rospy.Rate(60)	

	while not rospy.is_shutdown():
		pub.publish(twist)		
		rate.sleep()
