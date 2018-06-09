#!/usr/bin/env python

#Mutlithreaded, new and improved version of location code

import rospy, math, random
import numpy as np
import sensor_msgs.point_cloud2 as pc2
#import nav_msgs/OccupancyGrid as occgrid
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
from sensor_msgs.msg import PointCloud2
from joblib import Parallel, delayed
from multiprocessing import Pool
#how do for occupancy grid?

class Lidar:
	
	def __init__(self, scan_topic="velodyne_points"):
		self.scan_sub = rospy.Subscriber(scan_topic, PointCloud2, self.on_scan)
	
	def on_scan(self, cloud):
		# Take in our x, y, z, values and store them in the generator
		self.xyz_generator = pc2.read_points(cloud, skip_nans=True, field_names=("x", "y", "z"))
		# Create an iterable array out of the generator
		iterable = [np.array([i[0], i[1], i[2]]) for i in self.xyz_generator]
		# Create a numpy array out of the iterable
		self.points = np.array(iterable)
		# sort points from lidar into viable1 array with all points in a horizontal slice about 0 z value
		viable1 = self.points[np.absolute(self.points[:,2])<=.07,:][:,:]

		# shuffle the points in viable1 so that each line has an equal chance of being found
		np.random.shuffle(viable1)

		#MULTITHREADED
		self.populate_dock(viable1)
		self.populate_buoys()

	def populate_dock(self, viable1):
		# create iter int var that is 1 tenth the length of viable1's length 
		iter = viable1.size / 30
		# subtract 1 from iter to prevent accessing pass the end of the array
		iter = iter - 1
		
		# viable is viable1 minus the points that lie on the dock line
		self.viable = np.empty([(viable1.size + 10) / 3, 3])
		l = 0
		
		with Parallel(n_jobs=iter) as parallel:
			parallel(delayed(line_votes(i) for i in list(range(iter)))) 
	
	def line_votes(self, i): 
	
		# create temp array to store 10 points for a linear regression algorithm in order to find dock line
		temp = np.full((10,3), 0)
		# votes array stores the choices for possible dock line, more votes is more points that fall close to the line
		votes = np.full((10,3),0)
		# Run linear regression algorithm on each set of ten points in viable1

		sumy = 0
		sumx2 = 0
		sumx = 0
		sumxy = 0
		sum2x = 0
		for j in range(10):
			temp[j] = self.viable[(10 * i) + j]
			sumy += temp[j][1]
			sumx2 += temp[j][0] * temp[j][0]
			sumx += temp[j][0]
			sumxy += temp[j][0] * temp[j][1]
		sum2x = sumx2 * sumx2
			
		# store each a and b value for each line in votes array
		votes[i][1] = ((sumy * sumx) - (sumx * sumxy)) / ((10 * sumx2) - sum2x)
		votes[i][2] = ((10 * sumxy) - (sumx * sumy)) / ((10 * sumx2) - sum2x)

		# run through all points in viable1 to see if they fall on each line in votes
		for k in range(self.viable.size / 3):
			# line is y = a - bx
			y = votes[i][1] + (votes[i][2] * self.viable[k][0])
				
			# if point lies on line, add a vote to that line
			if abs(y - self.viable[k][1]) < 0.05:
				votes[i][0] += 1
				# if a line has more points than the dock line, make it the dock line
				if votes[i][0] > self.dockmaxvotes:
					waypoints.dockmaxvotes = votes[i][0]
					waypoints.docka = votes[i][1]
					waypoints.dockb = votes[i][2]
			# skip three points in viable in order to speed up the process
			k += 6

	def populate_buoys(self):
		i = 0
	
	def make_dock_viable(self):
		i = 0

	def make_buoys_viable(self):
		i = 0	

class Waypoints:

	def __init__(self, map_topic="map"):
		self.dockm = 0
		self.dockb = 0
		self.dockmaxvotes = 0

		#Buoys are from left to right. Points are x, y, votes.
		self.buoy1 = [0,0,0]
		self.buoy2 = [0,0,0]
		self.buoy3 = [0,0,0]
		self.buoy4 = [0,0,0]

		#How to translate from x/y to occmap?

	def calc_bay1(self):
		i = 0
	
	def calc_bay2(self):
		i = 0

	def calc_bay3(self):
		i = 0

	def sort_buoys(self):
		i = 0 

	def publish_docks(self):
		i = 0

if __name__ == '__main__':

	rospy.init_node("display", anonymous = False)
	waypoints = Waypoints()
	lidar = Lidar()
	rospy.spin()


