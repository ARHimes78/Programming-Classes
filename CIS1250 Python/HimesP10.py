# HimesP10
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: Points in a file

#GeoPoint class in HimesP10Library, in site-packages folder.
from HimesP10Library import GeoPoint

pointList = []

try:
    f = open('cnm_locations.csv','r')

    #Using a multi-dimensional list to append anonymous GeoPoint objects to pointList.
    allFields = []
    while True:
        line = f.readline()
        if not line:
            break
        fields = line.split(',')
        allFields.append(fields)

    f.close()
    
    row = 0
    while True:
        try:
            #The first 3 arguments for GeoPoint's constructor from the file
            #need to be casted to ints, otherwise they'll be considered to be
            #strings and used in the Distance method's calculation.
            pointList.append(GeoPoint((int)(allFields[row][0]),\
                                      (int)(allFields[row][1]),\
                                      (int)(allFields[row][2]),\
                                      allFields[row][3]))
            row += 1
        except IndexError:
            break

    response = 'y'
    while response[0].lower() == 'y':
        #Repeats until valid input has been entered.
        while True:
            try:
                UserX = input("\nEnter the X coordinate: ")
                UserY = input("\nEnter the Y coordinate: ")
                UserZ = input("\nEnter the Z coordinate: ")                

                pointUser = GeoPoint(UserX,UserY,UserZ,'User Location')              
                
                #using this tuple to save space
                userXYZ = pointUser.PointCoords

                closest = GeoPoint()
                
                for point in pointList:
                    if point.Distance(userXYZ[0],userXYZ[1],userXYZ[2]) \
                        < closest.Distance(userXYZ[0],userXYZ[1],userXYZ[2]):
                        closest = point
                                                
                print "You are closer to", closest.PointDescription, \
                      "which is located at", closest.PointCoords, "."
                
            except TypeError:
                print "Wrong data type!"
            except NameError:
                print "Please enter a number!"
            except Exception, e:
                print "Incorrect input!", e
            else:
                break        
            
        response = raw_input("\nDo another? (y/n): ")

    print "\nBye!"
    end = raw_input()
except IOError:
    print 'File not found!'
