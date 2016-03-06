# HimesP13
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: final project - Mad libs

import HimesP13Library
storyA = HimesP13Library.StoryA()
storyB = HimesP13Library.StoryB()
storyC = HimesP13Library.StoryC()
storyD = HimesP13Library.StoryD()
storyE = HimesP13Library.StoryE()

import wx

def OpenFile(event):
    window = HimesP13Library.Window()

    try:
        f = open(fileText.GetValue(), 'r')
        header = f.readline()
        #checking to see if the file was created by this program
        if "MAD LIB" not in header:        
            window.ErrorWindow("Invalid file","Please open a file that contains a generated mad lib!")
        else:
            window.Display(header,f.read(),False)
        f.close()
    except IOError, e:
        window.ErrorWindow("File not found!",str(e))

app = wx.App()
gui = wx.Frame(None, title="P13: Mad libs",size=(440,400))
gui.Center()
titleLabel = wx.StaticText(gui,pos=(40,40),size=(200,20),label="Choose a story!")
radioButtons = [wx.RadioButton(gui,pos=(20,80)),
wx.RadioButton(gui,pos=(20,120)),
wx.RadioButton(gui,pos=(20,160)),
wx.RadioButton(gui,pos=(20,200)),
wx.RadioButton(gui,pos=(20,240)),
wx.RadioButton(gui,pos=(20,280))]
radioButtons[1].Bind(wx.EVT_RADIOBUTTON,storyA.Gui)
radioButtons[2].Bind(wx.EVT_RADIOBUTTON,storyB.Gui)
radioButtons[3].Bind(wx.EVT_RADIOBUTTON,storyC.Gui)
radioButtons[4].Bind(wx.EVT_RADIOBUTTON,storyD.Gui)
radioButtons[5].Bind(wx.EVT_RADIOBUTTON,storyE.Gui)

textChoices = [wx.StaticText(gui,pos=(60,80),size=(200,20),label="None"),
wx.StaticText(gui,pos=(60,120),size=(200,20),label="Empire"),
wx.StaticText(gui,pos=(60,160),size=(200,20),label="Debates"),
wx.StaticText(gui,pos=(60,200),size=(200,20),label="Inspiration"),
wx.StaticText(gui,pos=(60,240),size=(200,20),label="Stranger"),
wx.StaticText(gui,pos=(60,280),size=(200,20),label="Intrusions")]

fileLabel = wx.StaticText(gui,pos=(20,320),size=(100,20),label="Filename:")
fileText = wx.TextCtrl(gui,pos=(145,320),size=(150,20))
openButton = wx.Button(gui,pos=(320,320),size=(100,20),label="Open")
openButton.Bind(wx.EVT_BUTTON,OpenFile)

gui.Show()
app.MainLoop()
