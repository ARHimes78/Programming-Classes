# HimesP9
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: Create a better class

#GeoPoint class in HimesP7Library, in site-packages folder.
from HimesP9Library import GeoPoint

#Setting object fields with construtor
point1 = GeoPoint(10,-4,23,'Point A')

#Setting object fields with class's properties
point2 = GeoPoint()
point2.PointCoords = -3,15,9
point2.PointDescription = 'Point B'

response = 'y'
while response[0].lower() == 'y':
    #Repeats until valid input has been entered.
    while True:
        try:
            UserX = input("\nEnter the X coordinate: ")
            UserY = input("\nEnter the Y coordinate: ")
            UserZ = input("\nEnter the Z coordinate: ")

            pointUser = GeoPoint(UserX,UserY,UserZ,'User Location')

            #Individual tuple elements are passed as arguments for Distance()
            DistanceToPoint1 = point1.Distance(pointUser.PointCoords[0],\
                pointUser.PointCoords[1],pointUser.PointCoords[2])
            DistanceToPoint2 = point2.Distance(pointUser.PointCoords[0],\
                pointUser.PointCoords[1],pointUser.PointCoords[2])

            if DistanceToPoint1 < DistanceToPoint2:
                print "You are closer to", point1.PointDescription, \
                      "which is located at", point1.PointCoords, "."
            elif DistanceToPoint1 > DistanceToPoint2:
                print "You are closer to", point2.PointDescription, \
                      "which is located at", point2.PointCoords, "."
            else:
                #If the halfway point 3.5, 5.5, and 16 is entered
                print "You are equally close to", point1.PointDescription, \
                      "and", point2.PointDescription, \
                      "which are located at", point1.PointCoords, \
                      "and", point2.PointCoords, "."
        #If a string, tuple, etc is entered
        except TypeError:
            print "Wrong data type!"
        #If a non-number is entered (doesn't have to be in quotes)
        except NameError:
            print "Please enter a number!"
        #Any other type of incorrect input.
        #For example, just pressing Enter causes a SyntaxError.
        except Exception, e:
            print "Incorrect input!", e
        else:
            break        
        
    response = raw_input("Do another? (y/n): ")

print "\nBye!"
end = raw_input()
