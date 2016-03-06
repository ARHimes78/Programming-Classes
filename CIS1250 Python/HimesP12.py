# HimesP12
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: points in a database

#GeoPoint class in HimesP12Library, in site-packages folder.
from HimesP12Library import GeoPoint
import wx
import sqlite3

#Everything from the previous program is in calc().
def calc(event):
    try:
        conn = sqlite3.connect('pointsDB.db')
        curs = conn.cursor()
        curs.execute('SELECT * FROM geoPointDB;')
        
        allFields = curs.fetchall()

        conn.commit()
        conn.close()    

        pointList = []
        row = 0
        while True:
            try:
                pointList.append(GeoPoint(allFields[row][0],\
                                          allFields[row][1],\
                                          allFields[row][2],\
                                          allFields[row][3]))
                row += 1
            except IndexError:
                break

        try:
            UserX = (int)(xText.GetValue())
            UserY = (int)(yText.GetValue())
            UserZ = (int)(zText.GetValue())              
            
            pointUser = GeoPoint(UserX,UserY,UserZ,'User Location')              
            
            #using this tuple to save space
            userXYZ = pointUser.PointCoords

            closest = GeoPoint()
            closest = pointList[0] #some results were showing the default points as closest.
            
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

    except sqlite3.OperationalError, e:
        errWindow("Table not found.",e)

#Creates a "pop-up" according to the error
def errWindow(msg, e):
    app = wx.App()
    err = wx.Frame(None,title=str(e),size=(400,300))
    errorText = wx.StaticText(err,label=msg)
    err.Show()
    app.MainLoop()

app = wx.App()
gui = wx.Frame(None,title="P11: XYZ Coordinates Graphical User Interface",size=(230,380))
xLabel = wx.StaticText(gui,pos=(5,5),size=(100,25),label="X coordinate:")
xText = wx.TextCtrl(gui,pos=(105,5),size=(100,25))
yLabel = wx.StaticText(gui,pos =(5,55),size=(100,25),label="Y coordinate:")
yText = wx.TextCtrl(gui,pos=(105,55),size=(100,25))
zLabel = wx.StaticText(gui,pos=(5,105),size=(100,25),label="Z coordinate:")
zText = wx.TextCtrl(gui,pos=(105,105),size=(100,25))
calcButton = wx.Button(gui,label="Calculate\ndistance",pos=(50,155),size=(100,50))
calcButton.Bind(wx.EVT_BUTTON,calc)
closestText = wx.TextCtrl(gui,pos=(5,230),size=(200,100),style=wx.TE_MULTILINE|wx.HSCROLL)
gui.Show()
app.MainLoop()
