# HimesP2
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: provides user capability to view contact info

names = ['Jesse', 'Margaret', 'Thomas']
email = ['spam_collector_j@gmail.com',
         'peggymobile@yahoo.com',
         'slackerTom13675@aol.com']
phone = ['555-9381', '555-1200', '555-3333']

print names
nameChoice = raw_input("Choose one of the names for contact info: ")

#Name's index corresponds to the index of the other lists.
if nameChoice in names: print nameChoice \
    + "'s email: " + email[names.index(nameChoice)] \
    + " phone #: " + phone[names.index(nameChoice)]

#I just wanted to see if this would work.
if nameChoice not in names: print "Invalid choice, please run the program again."

