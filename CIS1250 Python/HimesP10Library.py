# HimesP10Library
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: Points in a file

#This must be saved to the site-packages folder to work.
#No change since P9.

class GeoPoint(object):
    def __init__(self,x=0,y=0,z=0,description='TBD'):
        self.__X = x
        self.__Y = y
        self.__Z = z
        self.__description = description

    def SetPoint(self,coords):
        self.__X = coords[0]
        self.__Y = coords[1]
        self.__Z = coords[2]

    def GetPoint(self):
        return self.__X,self.__Y,self.__Z

    PointCoords = property(GetPoint, SetPoint)

    def Distance(self,X,Y,Z):
        from math import sqrt

        #Calculates and returns distance between passed value
        #and corresponding object value.
        return sqrt(pow(X - self.__X, 2)\
                    + pow(Y - self.__Y, 2)\
                    + pow(Z - self.__Z, 2))

    def SetDescription(self, description):
        self.__description = description

    def GetDescription(self):
        return self.__description

    PointDescription = property(GetDescription, SetDescription)
