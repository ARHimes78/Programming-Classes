# HimesP13Library
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: final project - Mad libs

class Window(object):
    def Display(self,title,story,showSaveWidgets):
        import wx
        app = wx.App()
        gui = wx.Frame(None,title=title,size=(600,400))
        gui.Center()
        self.storyText = wx.TextCtrl(gui,pos=(40,40),size=(520,210),style=wx.TE_MULTILINE)
        self.storyText.SetEditable(False)
        self.storyText.SetValue(story)
        fileLabel = wx.StaticText(gui,pos=(100,290),size=(100,20),label="Filename:")
        self.fileText = wx.TextCtrl(gui,pos=(225,290),size=(150,20))
        saveButton = wx.Button(gui,pos=(400,290),size=(100,20),label="Save")
        saveButton.Bind(wx.EVT_BUTTON, self.SaveFile)

        #This display window will also open when a mad lib file is opened.
        #In that case, the file save-related widgets will not show.
        if not showSaveWidgets:
            fileLabel.Hide()
            self.fileText.Hide()
            saveButton.Hide()
        gui.Show()
        app.MainLoop()

    #Will save to local folder.
    def SaveFile(self, event):
        f = open(self.fileText.GetValue(), 'w')
        f.write("MAD LIB")
        f.write("\n\n")
        f.write(self.storyText.GetValue())
        f.close()

    def ErrorWindow(self,title,text):
        import wx
        app = wx.App()
        gui = wx.Frame(None,title=title,size=(400,100))
        gui.Center()
        message = wx.StaticText(gui,label=text)
        gui.Show()
        app.MainLoop()

class StoryA(Window):
    def GetStory(self):
        return "Once upon a time there was an empire of "+self.__noun1+" people, \
and it was a(n) "+self.__adj1+" and "+self.__adj2+" civilization. People from all \
around would gather and "+self.__verb1+" upon the aesthetic "+self.__nounPl1+" of this \
flourishing "+self.__noun3+". One day, a very "+self.__adj3+" "+self.__noun4+" warlord with a(n) \
"+self.__adj4+" "+self.__noun5+" arrived with his "+self.__nounPl2+", and they \
"+self.__adverb+" decimated the "+self.__noun1+" kingdoms, "+self.__number+" at a time. \
All that remained after the mayhem of the invasions were discarded \
"+self.__noun1+" "+self.__nounPl3+"."

    Story = property(GetStory)
    
    def Gui(self,event):
        import wx
        app = wx.App()
        gui = wx.Frame(None,title="The Empire",size=(300,700))
        gui.Center()
        self.__text = [wx.StaticText(gui,pos=(20,40),size=(100,20),label="Noun:"),
        wx.StaticText(gui,pos=(20,80),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,120),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,160),size=(100,20),label="Verb:"),
        wx.StaticText(gui,pos=(20,200),size=(100,20),label="Plural noun:"),
        wx.StaticText(gui,pos=(20,240),size=(100,20),label="Noun:"),
        wx.StaticText(gui,pos=(20,280),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,320),size=(100,20),label="Noun:"),
        wx.StaticText(gui,pos=(20,360),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,400),size=(100,20),label="Noun:"),
        wx.StaticText(gui,pos=(20,440),size=(100,20),label="Plural noun:"),
        wx.StaticText(gui,pos=(20,480),size=(100,20),label="Adverb:"),
        wx.StaticText(gui,pos=(20,520),size=(100,20),label="Number:"),
        wx.StaticText(gui,pos=(20,560),size=(100,20),label="Plural noun:")]
        self.__inputText = [wx.TextCtrl(gui,pos=(150,40),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,80),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,120),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,160),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,200),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,240),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,280),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,320),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,360),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,400),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,440),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,480),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,520),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,560),size=(100,20))]
        
        storyButton = wx.Button(gui,pos=(60,600),size=(100,40),label="Generate\nMad Lib!")
        storyButton.Bind(wx.EVT_BUTTON,self.__Generate)
        gui.Show()
        app.MainLoop()    

    def __Generate(self,event):
        for tc in self.__inputText:            
            if tc.GetValue() == "":
                self.ErrorWindow("Input field left blank!", "All input fields must be filled.")
                return

        self.__noun1 = self.__inputText[0].GetValue()
        self.__adj1 = self.__inputText[1].GetValue()
        self.__adj2 = self.__inputText[2].GetValue()
        self.__verb1 = self.__inputText[3].GetValue()
        self.__nounPl1 = self.__inputText[4].GetValue()
        self.__noun3 = self.__inputText[5].GetValue()
        self.__adj3 = self.__inputText[6].GetValue()
        self.__noun4 = self.__inputText[7].GetValue()
        self.__adj4 = self.__inputText[8].GetValue()
        self.__noun5 = self.__inputText[9].GetValue()
        self.__nounPl2 = self.__inputText[10].GetValue()
        self.__adverb = self.__inputText[11].GetValue()
        self.__number = self.__inputText[12].GetValue()
        self.__nounPl3 = self.__inputText[13].GetValue()

        self.Display("The Empire", self.Story, True)#from base class  

class StoryB(Window):
    def GetStory(self):
        return "Several "+self.__timeUnit+"s before \
the "+self.__noun1+" of "+self.__adj1+" computing technology, a group \
of "+self.__adj2+", uniquely qualified scientists studying "+self.__nounPl1+" \
pondered enormously "+self.__adj3+" concepts and heated "+self.__nounPl2+" \
ensued. Unfortunately, they were the only researchers \
of "+self.__nounPl3+" "+self.__adj4+" enough to formulate \
their "+self.__nounPl4+", and no official counter-"+self.__nounPl5+" were \
available. So, on and on they bickered, with no "+self.__adj5+", \
"+self.__adj6+" consensus ever agreed upon."
    
    Story = property(GetStory)
    
    def Gui(self,event):
        import wx
        app = wx.App()
        gui = wx.Frame(None,title="Debates",size=(300,660))
        gui.Center()
        self.__text = [wx.StaticText(gui,pos=(20,40),size=(100,20),label="Time unit:"),
        wx.StaticText(gui,pos=(20,80),size=(100,20),label="Noun:"),
        wx.StaticText(gui,pos=(20,120),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,160),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,200),size=(100,20),label="Plural noun:"),
        wx.StaticText(gui,pos=(20,240),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,280),size=(100,20),label="Plural noun:"),
        wx.StaticText(gui,pos=(20,320),size=(100,20),label="Plural noun:"),
        wx.StaticText(gui,pos=(20,360),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,400),size=(100,20),label="Plural noun:"),
        wx.StaticText(gui,pos=(20,440),size=(100,20),label="Plural noun:"),
        wx.StaticText(gui,pos=(20,480),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,520),size=(100,20),label="Adjective:")]
        self.__inputText = [wx.TextCtrl(gui,pos=(150,40),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,80),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,120),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,160),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,200),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,240),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,280),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,320),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,360),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,400),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,440),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,480),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,520),size=(100,20))]
        
        storyButton = wx.Button(gui,pos=(60,560),size=(100,40),label="Generate\nMad Lib!")
        storyButton.Bind(wx.EVT_BUTTON,self.__Generate)
        gui.Show()
        app.MainLoop()    

    def __Generate(self,event):
        for tc in self.__inputText:            
            if tc.GetValue() == "":
                self.ErrorWindow("Input field left blank!", "All input fields must be filled.")
                return
            
        self.__timeUnit = self.__inputText[0].GetValue()
        self.__noun1 = self.__inputText[1].GetValue()
        self.__adj1 = self.__inputText[2].GetValue()
        self.__adj2 = self.__inputText[3].GetValue()
        self.__nounPl1 = self.__inputText[4].GetValue()
        self.__adj3 = self.__inputText[5].GetValue()
        self.__nounPl2 = self.__inputText[6].GetValue()
        self.__nounPl3 = self.__inputText[7].GetValue()
        self.__adj4 = self.__inputText[8].GetValue()
        self.__nounPl4 = self.__inputText[9].GetValue()
        self.__nounPl5 = self.__inputText[10].GetValue()
        self.__adj5 = self.__inputText[11].GetValue()
        self.__adj6 = self.__inputText[12].GetValue()

        self.Display("Debates", self.Story, True)
    
    
class StoryC(Window):
    def GetStory(self):
        return "Every day, "+self.__nounPl1+". It's endless. \
Well, no more! This time, I'm going to "+self.__verb1+" the \
most amazing "+self.__noun1+" ever served! \
First, I shall "+self.__verb2+" my "+self.__adj1+" frying pan. \
I suspect it is in the "+self.__noun2+" somewhere, \
buried underneath mountains of "+self.__noun3+" and \
pointless "+self.__nounPl2+", and I fear I may never find it. \
If I do, though, it will be a "+self.__noun4+" for the ages!"

    Story = property(GetStory)

    def Gui(self,event):
        import wx
        app = wx.App()
        gui = wx.Frame(None,title="Inspiration",size=(300,500))
        gui.Center()
        self.__text = [wx.StaticText(gui,pos=(20,40),size=(100,20),label="Plural noun:"),
        wx.StaticText(gui,pos=(20,80),size=(100,20),label="Verb:"),
        wx.StaticText(gui,pos=(20,120),size=(100,20),label="Noun:"),
        wx.StaticText(gui,pos=(20,160),size=(100,20),label="Verb:"),
        wx.StaticText(gui,pos=(20,200),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,240),size=(100,20),label="Noun:"),
        wx.StaticText(gui,pos=(20,280),size=(100,20),label="Noun:"),
        wx.StaticText(gui,pos=(20,320),size=(100,20),label="Plural noun:"),
        wx.StaticText(gui,pos=(20,360),size=(100,20),label="Noun:")]
        self.__inputText = [wx.TextCtrl(gui,pos=(150,40),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,80),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,120),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,160),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,200),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,240),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,280),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,320),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,360),size=(100,20))]
        
        storyButton = wx.Button(gui,pos=(60,400),size=(100,40),label="Generate\nMad Lib!")
        storyButton.Bind(wx.EVT_BUTTON,self.__Generate)
        gui.Show()
        app.MainLoop()    

    def __Generate(self,event):
        for tc in self.__inputText:            
            if tc.GetValue() == "":
                self.ErrorWindow("Input field left blank!", "All input fields must be filled.")
                return
            
        self.__nounPl1 = self.__inputText[0].GetValue()
        self.__verb1 = self.__inputText[1].GetValue()
        self.__noun1 = self.__inputText[2].GetValue()
        self.__verb2 = self.__inputText[3].GetValue()
        self.__adj1 = self.__inputText[4].GetValue()
        self.__noun2 = self.__inputText[5].GetValue()
        self.__noun3 = self.__inputText[6].GetValue()
        self.__nounPl2 = self.__inputText[7].GetValue()
        self.__noun4 = self.__inputText[8].GetValue()

        self.Display("Inspiration", self.Story, True)

class StoryD(Window):
    def GetStory(self):
        return "He was "+self.__adj1+", and people stayed away \
from him. It was difficult to "+self.__verb1+", but there was a \
very "+self.__adj2+" essence about him. "+self.__adverb.title()+", the \
more "+self.__adj3+" he made a person "+self.__verb2+", the \
more "+self.__adj4+" his presence became, yet he was unaware of any \
conscious "+self.__noun1+" in accomplishing this. Every night, \
though, he would "+self.__verb3+" the saxophone with a(n) "+self.__adj5+" \
level of quality that few have ever witnessed within their lifetimes."

    Story = property(GetStory)

    def Gui(self,event):
        import wx
        app = wx.App()
        gui = wx.Frame(None,title="Stranger",size=(300,540))
        gui.Center()
        self.__text = [wx.StaticText(gui,pos=(20,40),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,80),size=(100,20),label="Verb:"),
        wx.StaticText(gui,pos=(20,120),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,160),size=(100,20),label="Adverb:"),
        wx.StaticText(gui,pos=(20,200),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,240),size=(100,20),label="Verb:"),
        wx.StaticText(gui,pos=(20,280),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,320),size=(100,20),label="Noun:"),
        wx.StaticText(gui,pos=(20,360),size=(100,20),label="Verb:"),
        wx.StaticText(gui,pos=(20,400),size=(100,20),label="Adjective:"),]
        self.__inputText = [wx.TextCtrl(gui,pos=(150,40),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,80),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,120),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,160),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,200),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,240),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,280),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,320),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,360),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,400),size=(100,20))]
        
        storyButton = wx.Button(gui,pos=(60,440),size=(100,40),label="Generate\nMad Lib!")
        storyButton.Bind(wx.EVT_BUTTON,self.__Generate)
        gui.Show()
        app.MainLoop()    

    def __Generate(self,event):
        for tc in self.__inputText:            
            if tc.GetValue() == "":
                self.ErrorWindow("Input field left blank!", "All input fields must be filled.")
                return
            
        self.__adj1 = self.__inputText[0].GetValue()
        self.__verb1 = self.__inputText[1].GetValue()
        self.__adj2 = self.__inputText[2].GetValue()
        self.__adverb = self.__inputText[3].GetValue()
        self.__adj3 = self.__inputText[4].GetValue()
        self.__verb2 = self.__inputText[5].GetValue()
        self.__adj4 = self.__inputText[6].GetValue()
        self.__noun1 = self.__inputText[7].GetValue()
        self.__verb3 = self.__inputText[8].GetValue()
        self.__adj5 = self.__inputText[9].GetValue()

        self.Display("Stranger", self.Story, True)


class StoryE(Window):
    def GetStory(self):
        return "She just wanted to "+self.__adverb1+" \
"+self.__verb1+" her "+self.__noun1+" and escape into her own \
"+self.__noun2+" and "+self.__verb2+", but the "+self.__nounPl1+" \
around her seemed to "+self.__adverb2+" demand her "+self.__noun3+" \
on a "+self.__adj1+" basis. The person seated at the "+self.__noun4+" \
next to her kept making snorting "+self.__nounPl2+" that would \
"+self.__verb3+" her mental "+self.__nounPl3+" and replace them with \
an "+self.__adj2+" sense of revulsion. As soon as the unpleasant \
"+self.__nounPl4+" subsided, the couple seated at the "+self.__noun4+" \
behind her kept "+self.__adverb3+" repeating the same "+self.__adj3+" \
"+self.__number1+" sentences repeatedly, each time followed by \
inappropriately "+self.__adj4+" laughter. Meanwhile, the waiter's \
"+self.__adj5+", "+self.__adj6+" ringtone would "+self.__adverb4+" \
"+self.__verb4+" every "+self.__adj7+" moment of silence, and each \
time he seemed to take at least "+self.__number2+" "+self.__timeUnit+"s \
to acknowledge it. In spite of the repeated, "+self.__adj8+" violations \
upon her peace of mind, she reminded herself of the "+self.__adj9+" \
importance of not letting her "+self.__adj10+" annoyance manifest \
in her behavior in any way whatsoever."

    Story = property(GetStory)
    
    def Gui(self,event):
        import wx
        app = wx.App()
        gui = wx.Frame(None,title="Intrusions",size=(560,740))
        gui.Center()
        self.__text = [wx.StaticText(gui,pos=(20,40),size=(100,20),label="Adverb:"),
        wx.StaticText(gui,pos=(20,80),size=(100,20),label="Verb:"),
        wx.StaticText(gui,pos=(20,120),size=(100,20),label="Noun:"),
        wx.StaticText(gui,pos=(20,160),size=(100,20),label="Noun:"),
        wx.StaticText(gui,pos=(20,200),size=(100,20),label="Verb:"),
        wx.StaticText(gui,pos=(20,240),size=(100,20),label="Plural noun:"),
        wx.StaticText(gui,pos=(20,280),size=(100,20),label="Adverb:"),
        wx.StaticText(gui,pos=(20,320),size=(100,20),label="Noun:"),
        wx.StaticText(gui,pos=(20,360),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,400),size=(100,20),label="Noun:"),
        wx.StaticText(gui,pos=(20,440),size=(100,20),label="Plural noun:"),
        wx.StaticText(gui,pos=(20,480),size=(100,20),label="Verb:"),
        wx.StaticText(gui,pos=(20,520),size=(100,20),label="Plural noun:"),
        wx.StaticText(gui,pos=(20,560),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(20,600),size=(100,20),label="Plural noun:"),
        wx.StaticText(gui,pos=(280,40),size=(100,20),label="Adverb:"),
        wx.StaticText(gui,pos=(280,80),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(280,120),size=(100,20),label="Number:"),
        wx.StaticText(gui,pos=(280,160),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(280,200),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(280,240),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(280,280),size=(100,20),label="Adverb:"),
        wx.StaticText(gui,pos=(280,320),size=(100,20),label="Verb:"),
        wx.StaticText(gui,pos=(280,360),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(280,400),size=(100,20),label="Number:"),
        wx.StaticText(gui,pos=(280,440),size=(100,20),label="Time unit:"),
        wx.StaticText(gui,pos=(280,480),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(280,520),size=(100,20),label="Adjective:"),
        wx.StaticText(gui,pos=(280,560),size=(100,20),label="Adjective:")]
        self.__inputText = [wx.TextCtrl(gui,pos=(150,40),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,80),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,120),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,160),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,200),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,240),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,280),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,320),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,360),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,400),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,440),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,480),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,520),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,560),size=(100,20)),
        wx.TextCtrl(gui,pos=(150,600),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,40),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,80),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,120),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,160),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,200),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,240),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,280),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,320),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,360),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,400),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,440),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,480),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,520),size=(100,20)),
        wx.TextCtrl(gui,pos=(410,560),size=(100,20))]

        storyButton = wx.Button(gui,pos=(60,640),size=(100,40),label="Generate\nMad Lib!")
        storyButton.Bind(wx.EVT_BUTTON,self.__Generate)
        gui.Show()
        app.MainLoop()    

    def __Generate(self,event):
        for tc in self.__inputText:
            if tc.GetValue() == "":
                self.ErrorWindow("Input field left blank!", "All input fields must be filled.")
                return

        self.__adverb1 = self.__inputText[0].GetValue()
        self.__verb1 = self.__inputText[1].GetValue()
        self.__noun1 = self.__inputText[2].GetValue()
        self.__noun2 = self.__inputText[3].GetValue()
        self.__verb2 = self.__inputText[4].GetValue()
        self.__nounPl1 = self.__inputText[5].GetValue()
        self.__adverb2 = self.__inputText[6].GetValue()
        self.__noun3 = self.__inputText[7].GetValue()
        self.__adj1 = self.__inputText[8].GetValue()
        self.__noun4 = self.__inputText[9].GetValue()
        self.__nounPl2 = self.__inputText[10].GetValue()
        self.__verb3 = self.__inputText[11].GetValue()
        self.__nounPl3 = self.__inputText[12].GetValue()
        self.__adj2 = self.__inputText[13].GetValue()
        self.__nounPl4 = self.__inputText[14].GetValue()
        self.__adverb3 = self.__inputText[15].GetValue()
        self.__adj3 = self.__inputText[16].GetValue()
        self.__number1 = self.__inputText[17].GetValue()
        self.__adj4 = self.__inputText[18].GetValue()
        self.__adj5 = self.__inputText[19].GetValue()
        self.__adj6 = self.__inputText[20].GetValue()
        self.__adverb4 = self.__inputText[21].GetValue()
        self.__verb4 = self.__inputText[22].GetValue()
        self.__adj7 = self.__inputText[23].GetValue()
        self.__number2 = self.__inputText[24].GetValue()
        self.__timeUnit = self.__inputText[25].GetValue()
        self.__adj8 = self.__inputText[26].GetValue()
        self.__adj9 = self.__inputText[27].GetValue()
        self.__adj10 = self.__inputText[28].GetValue()

        self.Display("Intrusions", self.Story, True)
