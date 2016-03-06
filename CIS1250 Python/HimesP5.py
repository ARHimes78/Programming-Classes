# HimesP5
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: demonstrate use of functions

#Functions
from math import sqrt

def header():
    print "Programmer: Alan Himes"
    print "email: ahimes1@cnm.edu"
    print "Purpose of program: demonstrate use of functions"

def coordinates(pointNum):
    x = input("\nEnter the x coordinate of point #" + str(pointNum) + ": ")
    y = input("Enter the y coordinate of point #" + str(pointNum) + ": ")
    z = input("Enter the z coordinate of point #" + str(pointNum) + ": ")

    return x, y, z

def calcDistance(point1, point2):
    #The tuples' elements represent the planes of the coordinates.
    #It doesn't matter if subtracting two numbers creates a negative number
    #because squaring that number will always result in a positive number.
    distance = sqrt(pow(point2[0] - point1[0], 2)\
                    + pow(point2[1] - point1[1], 2)\
                    + pow(point2[2] - point1[2], 2))
    
    print "\nThe distance between the two points is %.1f" % distance + "."

#"Main" part of program
header()

response = 'y'

while response[0].lower() == 'y':
    #Tuples from the coordinate info are returned to point1 and point2.
    #The numbers passed into coordinates() will be used in the function's strings
    #to identify the two points.
    point1 = coordinates(1)
    point2 = coordinates(2)

    #The tuples are passed to calcDistance to be used for calculation
    calcDistance(point1, point2)

    #Prompt the user to make another calculation
    response = raw_input("Calculate the distance between two points again? (y/n): ")

print "\nBye!"
end = raw_input()
