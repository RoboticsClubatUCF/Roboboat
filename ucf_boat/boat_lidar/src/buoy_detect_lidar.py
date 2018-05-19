#!/usr/bin/env python

# Heather Connors
# Jade Zsiros
# EGN4060C Final Project
# Cylinder detection by random sample vote

import rospy, math, random
import numpy as np
import sensor_msgs.point_cloud2 as pc2
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
from sensor_msgs.msg import PointCloud2

class Lidar:
   
	def __init__(self, scan_topic="velodyne_points"):
		# Subscribe to the laser scan topic
		self.scan_sub = rospy.Subscriber(scan_topic, PointCloud2, self.on_scan)
		self.skip = 1
		self.docka = 0
		self.dockb = 0
		self.dockmaxvotes = 0		

	def on_scan(self, cloud):
		# Take in our x, y, z, values and store them in the generator
		self.xyz_generator = pc2.read_points(cloud, skip_nans=True, field_names=("x", "y", "z"))
		# Create an iterable array out of the generator
		iterable = [np.array([i[0], i[1], i[2]]) for i in self.xyz_generator]
		# Create a numpy array out of the iterable
		self.points = np.array(iterable)
		# Redisplay the window
		glutPostRedisplay()
		
	def initFun(self):
		# Define clear color
		glClearColor(1.0,1.0,1.0,0.0)
		# Define point color
		glColor3f(0.0,0.0, 0.0)
		# Define point size
		glPointSize(1.0)
		# Define display mode and values
		glMatrixMode(GL_MODELVIEW)
		glLoadIdentity()
		gluLookAt(0, 0, 3, 0, 0, 0, 1, 0, 0)
		# Define view mode and values
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()
		glOrtho(-5,5,-5,5,0,5)  
		
	def displayFun(self):
		# Clear color buffer
		glClear(GL_COLOR_BUFFER_BIT)
		# Set point size back to 1
		glPointSize(1.0)
		# Initialize display function
		glBegin(GL_POINTS)		
	
		# check if we want to skip this cycle
		if self.skip == 1:

			# sort points from lidar into viable1 array with all points in a horizontal slice about 0 z value
			viable1 = self.points[np.absolute(self.points[:,2])<=.07,:][:,:]
			# shuffle the points in viable1 so that each line has an equal chance of being found
			np.random.shuffle(viable1)

			# draw all points that are in the viable1 array
			for i in viable1:
				glColor3f(0,255,0)
				glVertex3f(i[0], i[1],i[2])

			# create iter int var that is 1 tenth the length of viable1's length 
			iter = viable1.size / 30
			# subtract 1 from iter to prevent accessing pass the end of the array
			iter = iter - 1
			# create temp array to store 10 points for a linear regression algorithm in order to find dock line
			temp = np.full((10,3), 0)
			# votes array stores the choices for possible dock line, more votes is more points that fall close to the line
			votes = np.full((iter,3),0)
			# viable is viable1 minus the points that lie on the dock line
			viable = np.empty([(viable1.size + 10) / 3, 3])
			l = 0
			
			# Run linear regression algorithm on each set of ten points in viable1
			for i in range(iter):
				sumy = 0
				sumx2 = 0
				sumx = 0
				sumxy = 0
				sum2x = 0
				for j in range(10):
					temp[j] = viable1[(10 * i) + j]
					sumy += temp[j][1]
					sumx2 += temp[j][0] * temp[j][0]
					sumx += temp[j][0]
					sumxy += temp[j][0] * temp[j][1]
				sum2x = sumx2 * sumx2
				
				# store each a and b value for each line in votes array
				votes[i][1] = ((sumy * sumx) - (sumx * sumxy)) / ((10 * sumx2) - sum2x)
				votes[i][2] = ((10 * sumxy) - (sumx * sumy)) / ((10 * sumx2) - sum2x)

				# run through all points in viable1 to see if they fall on each line in votes
				for k in range(viable1.size / 3):
					# line is y = a - bx
					y = votes[i][1] + (votes[i][2] * viable1[k][0])
					
					# if point lies on line, add a vote to that line
					if abs(y - viable1[k][1]) < 0.05:
						votes[i][0] += 1
						# if a line has more points than the dock line, make it the dock line
						if votes[i][0] > self.dockmaxvotes:
							self.dockmaxvotes = votes[i][0]
							self.docka = votes[i][1]
							self.dockb = votes[i][2]
					# skip three points in viable in order to speed up the process
					k += 6

			# draw the dock line points to the screen
			for i in viable1:
				# check if point lies on the dock line, and draw it if it does
				y2 = self.docka + (self.dockb * i[0])	
				if abs(y2 - i[1]) < 0.05:
					glColor3f(255,0,0)
					glVertex3f(i[0],i[1],0)	
				else:
					# if point not on dock line, assign it to viable array, which is used to find buoys
					viable[l] = i
					l += 1		

			# print the number of votes for the biggest dock line
			print("Maximum is:")			
			print(self.dockmaxvotes)



			iter = viable.size/3

			print(iter)

			# Create empty array to count votes for each point
			votes = [0] * iter
				
			iter -= 2
	
		
			# Iterate through viable points (stored randomly)
			# Generate a circle through 3 points at a time
			# If the circle is of radius similar to buoy,
			# Count points that may lie on that circle.	 
			for i in range(iter):
				# Set 3 points to be checked
				A = viable[i]
				B = viable[i+1]
				C = viable[i+2]	
			 
				# Algorithm for calculating circle modified from:
				# https://stackoverflow.com/questions/20314306/find-arc-circle-equation-given-three-points-in-space-3d
			 
				# Take normalized length of line between each two points	 
				a = np.linalg.norm(C - B)
				b = np.linalg.norm(C - A)
				c = np.linalg.norm(B - A)
					   
				# Find radius of circle with these points   
				radius = (a*b*c) / np.sqrt(2.0 * a**2 * b**2 + 2.0 * b**2 * c**2 + 2.0 * a**2 * c**2 - a**4 - b**4 - c**4)
		
				# Find barcyntric coordinates of center
				b1 = a*a * (b*b + c*c - a*a)
				b2 = b*b * (a*a + c*c - b*b)
				b3 = c*c * (a*a + b*b - c*c)
			
				# Create a center point as three values	 
				p = np.column_stack((A, B, C)).dot(np.hstack((b1,b2,b3)))
				p /= b1 + b2 + b3
				'''
				# Alter point size for blue points
				glEnd()
				glPointSize(3.0)
				glBegin(GL_POINTS)
				'''	
				# If radius is within range, check for votes from other points	
				if radius > .1372 and radius < .1422:
					# Count votes from all viable points
					for j in viable:
						# Check distance from center
						distance = np.sqrt((p[0] - j[0])**2 + (p[1] - j[1])**2)
						# If distance from center is similar to radius, cast a vote
						if distance <= .15:
							votes[i] += 1
							if votes[i] >= 25:
								glColor3f(0,0,255)
								glVertex3f(j[0],j[1],0)
				
						

		
# End display function	
		glEnd()
		glFlush()

class Map:

	def __init__(self):
		self.worldmap = 0

class Camera:

	def __init__(self):
		self.color = 0

if __name__ == '__main__':
	rospy.init_node("display", anonymous = False)	
	lidar = Lidar()
	occmap = Map()
	glutInit()   
	glutInitWindowSize(1000,1000)
	glutCreateWindow("Points")
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
	glutDisplayFunc(lidar.displayFun)
	lidar.initFun()
	glutMainLoop()
	
	
	# Math notes:	
	# Within one plane, sample three points and calculate the circle that they occupy
	# Check the radius of this circle, and if it is within acceptable bounds, it is viable
	# In order to find the circle, draw a triangle between the three points
	# The perpendicular bisectors of the three sides of the triangle intersect at the center
	# The radius is the distance between this center and one of the points
	

