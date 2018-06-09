#! /usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
import serial
import struct
import slip

class BoatController:
    MCUPING = 0x0D
    MCUSETMOTOROUTPUT = 0x0F
    
    MCUPONG = 0x84
    MCUREPORTANALOGINPUTS = 0x83
    
    MOTORFL = 1
    MOTORFR = 2
    MOTORBL = 3
    MOTORBR = 4
    
    def __init__(self):
        self.serialPortName = rospy.get_param("controller_serial_port", "/dev/ttyUSB1")
        self.ser = serial.Serial(port = self.serialPortName, baudrate = 57600, write_timeout = 1.0)
        self.slip = slip.slip()
    
    def velocityCallback(self, msg):
        motors = [0, 0, 0, 0]
        #Map twist to motors
        motors[0] = int((-msg.linear.x - msg.linear.y - msg.angular.z)*32767)
        motors[1] = int((-msg.linear.x + msg.linear.y + msg.angular.z)*32767)
        motors[2] = int((msg.linear.x - msg.linear.y + msg.angular.z)*32767)
        motors[3] = int((msg.linear.x + msg.linear.y - msg.angular.z)*32767)
        
        motors = [max(min(32767, motor), -32768) for motor in motors] #limit motor power
        
        #build message packet
        packet = bytearray()
        packet.append(15) #Length of motor data
        packet.append(self.MCUSETMOTOROUTPUT)
        packet.append(self.MOTORFL)
        packet.extend(struct.pack("h",motors[0]))
        packet.append(self.MOTORFR)
        packet.extend(struct.pack("h",motors[1]))
        packet.append(self.MOTORBL)
        packet.extend(struct.pack("h",motors[2]))
        packet.append(self.MOTORBR)
        packet.extend(struct.pack("h",motors[3]))
        
        checksum = 0
        for byte in packet:
            checksum += byte
        
        checksum = checksum % 256
        
        packet.append(checksum)
        
        print(self.slip.encode(bytes(packet)).encode("string-escape"))
        self.ser.write(self.slip.encode(bytes(packet)))
	

    def run(self):
        rospy.Subscriber("cmd_vel", Twist, self.velocityCallback)
        
        rate = rospy.Rate(10)
        while not rospy.is_shutdown():
            rate.sleep()
            
if __name__ == "__main__":
    rospy.init_node("boat_controller_interface")
    node = BoatController()
    node.run()
