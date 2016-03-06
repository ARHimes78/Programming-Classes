# HimesP7Library
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: demonstrate how to define a class

#This must be saved to the site-packages folder to work.

class GeoPoint:
    def __init__(self):
        self.__X = 0
        self.__Y = 0
        self.__Z = 0
        self.__description = ""

    def SetPoint(self,X,Y,Z):
        self.__X = X
        self.__Y = Y
        self.__Z = Z

    def GetPoint(self):
        return self.__X,self.__Y,self.__Z

    def Distance(self,X,Y,Z):
        #math.sqrt() doesn't seem to work
        #unless I put the from/import line in this method.
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
