Ex1
Authored by Mohammad Ulayan

==Description==
The program asks the user to enter a string as an input, if the string was anything other than (history or exit) then the program returns the number of words and chars in that string as an output,
at the same time each string entered will be saved in a file working as a history, if the user entered the string (history) then all the previous strings will be printed as output,
if the user entered (exit) as a string then the program will stop and be exited.

Program DATABASE:
History: it contains the strings which were entered by the user before, and we can get to them just by entering the string (history).
Array of chars:  it’s used to store all the characters of each string, it must be less than 510 chars, it’s also used to read the strings from the history file.
Functions:
3 main functions
    1) wordCounter: this method receives a string and counts the number of words the string has
    2) charCounter: this method receives a string and counts the number of chars the string has, skipping spaces.
    3) spaceRemover: this method will remove the beginning and ending spaces (I used it in order if the user entered “     history       “  so it counts as  “history”

==Program Files==
StringParser.c       contains the main and the functions

==How to compile==
Run: StringParser.c

==Input==
A string

==Output==
If the string is not the word history or exit the output will be, Number of words in the string
, Number of chars in the string
But if the string is the word history or exit, If its history the output will be All the strings that were entered before numbered in order
If the string was exit It will exit the program and there will be no output
