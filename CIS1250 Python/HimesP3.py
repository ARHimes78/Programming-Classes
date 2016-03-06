# HimesP3
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: provides user capability to find fruit in a string

fruits = ['apple', 'orange', 'banana', 'pineapple', 'watermelon', 'grape', 'lemon']
sentence = raw_input("Please enter a sentence with a fruit in it: ")

#Changing the string into a list.
sentence = sentence.split()

#Creating a list of the words from the sentence that match
#words from the fruits list.
commonWords = list(set(fruits).intersection(set(sentence)))

if len(commonWords) == 0:
    print "No fruits detected in this sentence."
else:
    print "I found " + str(len(commonWords)) + " fruits in your sentence!"
    print "Your fruits are: " + str(commonWords)

    #Replacing the word in the sentence that is the same as the last
    #element of commonWords(list of fruits in the sentence)
    #with "Brussels sprouts".
    sentence[sentence.index(commonWords[-1])] = 'Brussels sprouts'

    #Changing the list of the sentence back to a string.
    sentence = ' '.join(sentence)
    print "Your sentence with Brussels sprouts: " + sentence
    
