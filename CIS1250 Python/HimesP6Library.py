# HimesP6Library
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: demonstrate use of libraries

#This must be saved to the site-packages folder to work.

#Functions
from math import sqrt

def header():
    print "Programmer: Alan Himes"
    print "email: ahimes1@cnm.edu"
    print "Purpose of program: demonstrate use of functions...FROM A LIBRARY!!"

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
