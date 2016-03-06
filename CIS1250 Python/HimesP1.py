#HimesP1
#Programmer: Alan Himes
#Email: ahimes1@cnm.edu
#Purpose: provides user capability to calculate
#surface area and volume of a pyramid.

from __future__ import division #for accurate division
from math import sqrt

print "Pyramid surface area and volume calculator"

height = input("Enter the pyramid's height (in inches): ")
baseLength = input("Enter the length of the pyramid's base (in inches): ")
print ""

baseArea = pow(baseLength,2)
slant = sqrt((pow((baseLength / 2),2)) + pow(height,2))
pyramidFace = (slant * baseLength) / 2
surfaceArea = baseArea + (4 * pyramidFace)
volume = (baseArea * height) / 3

print "Height:"
print height
print ""

print "Base length:"
print baseLength
print ""

print "Surface area:"
print surfaceArea
print ""

print "Volume:"
print volume
print ""

end = input("")




