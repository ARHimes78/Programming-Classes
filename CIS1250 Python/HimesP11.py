# HimesP11
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: demonstrate how to use a GUI

#GeoPoint class in HimesP11Library, in site-packages folder.
from HimesP11Library import GeoPoint
import wx

#Everything from the previous program is in calc().
def calc(event):
    try:
        f = open(fileText.GetValue(),'r')
        
        allFields = []
        while True:
            line = f.readline()
            if not line:
                break
            fields = line.split(',')
            allFields.append(fields)

        pointList = []
        row = 0
        while True:
            try:
                pointList.append(GeoPoint((int)(allFields[row][0]),\
                                          (int)(allFields[row][1]),\
                                          (int)(allFields[row][2]),\
                                          allFields[row][3]))
                row += 1
            except IndexError:
                break
        
        f.close()

        try:
            UserX = (int)(xText.GetValue())
            UserY = (int)(yText.GetValue())
            UserZ = (int)(zText.GetValue())              
            
            pointUser = GeoPoint(UserX,UserY,UserZ,'User Location')              
            
            #using this tuple to save space
            userXYZ = pointUser.PointCoords

            closest = GeoPoint()
            
            for point in pointList:
                if point.Distance(userXYZ[0],userXYZ[1],userXYZ[2]) \
                    < closest.Distance(userXYZ[0],userXYZ[1],userXYZ[2]):
                    closest = point

            result = "You are closer to \n" + str(closest.PointDescription) + \
                     "which is located at \n" + str(closest.PointCoords) + "."
            closestText.SetValue(result)

        #In case of invalid input
        except ValueError, e:
            errWindow("Incorrect input!",e)

    except IOError, e:
        errWindow("File not found!",e)

#Creates a "pop-up" according to the error
def errWindow(msg, e):
    app = wx.App()
    err = wx.Frame(None,title=str(e),size=(400,300))
    errorText = wx.StaticText(err,label=msg)
    err.Show()
    app.MainLoop()

app = wx.App()
gui = wx.Frame(None,title="P11: XYZ Coordinates Graphical User Interface",size=(230,455))
fileLabel = wx.StaticText(gui,pos=(5,5),size=(200,25),label="Filename")
fileText = wx.TextCtrl(gui,pos=(5,30),size=(200,25))
xLabel = wx.StaticText(gui,pos=(5,80),size=(100,25),label="X coordinate:")
xText = wx.TextCtrl(gui,pos=(105,80),size=(100,25))
yLabel = wx.StaticText(gui,pos =(5,130),size=(100,25),label="Y coordinate:")
yText = wx.TextCtrl(gui,pos=(105,130),size=(100,25))
zLabel = wx.StaticText(gui,pos=(5,180),size=(100,25),label="Z coordinate:")
zText = wx.TextCtrl(gui,pos=(105,180),size=(100,25))
calcButton = wx.Button(gui,label="Calculate\ndistance",pos=(50,230),size=(100,50))
calcButton.Bind(wx.EVT_BUTTON,calc)
closestText = wx.TextCtrl(gui,pos=(5,305),size=(200,100),style=wx.TE_MULTILINE|wx.HSCROLL)
gui.Show()
app.MainLoop()
