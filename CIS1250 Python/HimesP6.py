# HimesP6
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: demonstrate use of libraries

import HimesP6Library

HimesP6Library.header()

response = 'y'

while response[0].lower() == 'y':
    #Tuples from the coordinate info are returned to point1 and point2.
    #The numbers passed into coordinates() will be used in the function's strings
    #to identify the two points.
    point1 = HimesP6Library.coordinates(1)
    point2 = HimesP6Library.coordinates(2)

    #The tuples are passed to calcDistance to be used for calculation
    HimesP6Library.calcDistance(point1, point2)

    #Prompt the user to make another calculation
    response = raw_input("Calculate the distance between two points again? (y/n): ")

print "\nBye!"
end = raw_input()
