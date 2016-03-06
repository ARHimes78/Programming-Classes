# HimesP4
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: Game menu that opens games in web browser, based on the movie Wargames.

import webbrowser

response = 'yes'

while response.lower() == 'yes':
    response = raw_input("\nWould you like to play a game(yes/no)? ")

    if response.lower() == 'yes':
        print "CHESS\nTIC TAC TOE\nTETRIS\nCOUNT\n\nGLOBAL THERMONUCLEAR WAR\n"
        game = raw_input('>')
        
        #Action will be taken depending on user response.
        if game.lower() in 'chess':
            webbrowser.open_new("http://www.pygame.org/tags/chess")
        elif game.lower() in 'tic tac toe':
            webbrowser.open_new("http://www.pygame.org/tags/tictactoe")
        elif game.lower() in 'tetris':
            webbrowser.open_new("http://www.pygame.org/project-Clone+of+Tetris-2125-.html")
        elif game.lower() in 'count':
            maxNumber = input('How high? ')
            print range(1, maxNumber+1)
        elif game.lower() in 'global thermonuclear war':
            print "Wouldn't you prefer a good game of chess?"
        else:
            print "I did not understand that!"
            
