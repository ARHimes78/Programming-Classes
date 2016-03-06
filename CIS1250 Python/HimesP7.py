# HimesP7
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: demonstrate how to define a class

#GeoPoint class in HimesP7Library, in site-packages folder.
from HimesP7Library import GeoPoint

#Setting two objects with their own points and descriptions.
point1 = GeoPoint()
point1.SetPoint(10,-4,23)
point1.SetDescription('Point A')

point2 = GeoPoint()
point2.SetPoint(-3,15,9)
point2.SetDescription('Point B')

response = 'y'
while response[0].lower() == 'y':
    UserX = input("\nEnter the X coordinate: ")
    UserY = input("\nEnter the Y coordinate: ")
    UserZ = input("\nEnter the Z coordinate: ")

    DistanceToPoint1 = point1.Distance(UserX, UserY, UserZ)
    DistanceToPoint2 = point2.Distance(UserX, UserY, UserZ)

    print DistanceToPoint1
    print DistanceToPoint2

    if DistanceToPoint1 < DistanceToPoint2:
        print "You are closer to", point1.GetDescription(), \
              "which is located at", point1.GetPoint(), "."
    elif DistanceToPoint1 > DistanceToPoint2:
        print "You are closer to", point2.GetDescription(), \
              "which is located at", point2.GetPoint(), "."
    else:
        #If the halfway point 3.5, 5.5, and 16 is entered
        print "You are equally close to", point1.GetDescription(), \
              "and", point2.GetDescription(), \
              "which are located at", point1.GetPoint(), \
              "and", point2.GetPoint(), "."
    
    response = raw_input("Do another? (y/n): ")

print "\nBye!"
end = raw_input()
