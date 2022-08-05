#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMUM 510

int wordCounter(const char *str); // count number of words in entered string
int charCounter(const char *str); // count number of chars in entered string
int spaceRemover(char *str); // remove spaces from the beginning and the end of the string and checks if it's equal to history

int main()
{
    char *str = (char *)malloc(sizeof(char) * MAXIMUM); // allocate memory for the string
    if (str == NULL)                                       // check if we manged to allocate memory
    {
        printf("allocation failed"); // if not then we print allocation failed
        return -1;                            // exit
    }
    int i;
    FILE *fp;
    while (1)               // infinite loop
    {
        printf("Enter String, or \"exit\" to end program:\n"); // telling the user what to do
        scanf(" %[^\n]%*c", str); // read the string
        // %[^\n]%*c , will help you to get an entire sentence until the next line isn’t encountered “\n” or enter is pressed
        if (spaceRemover(str) == 1)                       // if the string is history
        {
            fp = fopen("file.txt", "r"); // open the history file
            if (fp == NULL)                 // if the file is not found
            {
                printf("no history\n");
            }
            else // if we find the file
            {
                char strArr[MAXIMUM]; // Character
                i = 0; // counter back to 0
                while (fscanf(fp, "%[^\n]%*c", strArr) != EOF) //  read from the file
                    // %[^\n]%*c , will help you to get an entire sentence until the next line isn’t encountered “\n” or enter is pressed
                {
                    printf("%d: %s\n", i, strArr); // print char
                    i++;
                }
                fclose(fp); // close file
            }
        }
        else if (strcmp(str,"exit")== 0)// if the string is exited
        {
            break; // exit the loop
        }
        else // if the string is other than history or exit
        {
            fp = fopen("file.txt", "a"); // open file , and the file is created if it does not exist
            fprintf(fp, "%s\n", str);              // write entered string to the file
            fclose(fp);                             // close file
            printf("%d words\n", wordCounter(str)); //  print num of word
            printf("%d chars\n", charCounter(str)); // print num of chars
        }
    }
    free(str); // free the allocated memory
}

int wordCounter(const char *str){
    int counter =0; // word counter
    int i = 0;
    while (str[i] != '\0') // till we reach the end of the string
    {
        if (str[i+1]!=' '&& str[i] == ' ') //  if we have a space ,and after it is not a space we increase the counter
        {
            counter++;
        }

        if (str[i + 1] == '\0' && str[i] == ' ') // if we reach the end of the string, and we have one or more spaces at the end we return the counter
        {
            return counter;
        }
        i++;
    }
    return counter + 1;
}

int charCounter( const char *str){
    int counter =0; // char counter
    int i =0;
    while(str[i]!='\0') // till we reach the end of the string
    {
        if(str[i]!=' ')  // if we are not at a space then increase the counter
        {
            counter++;
        }
        i++;
    }
    return counter;
}
int spaceRemover(char *str)
{
    int i,j;
    for(i=0;str[i]==' ';i++); // skipping white spaces
    for(j=0;str[i];i++) // when we find a letter we change its place to the beginning of the string
    {
        str[j++]=str[i];
    }
    str[j]='\0';
    for(i=0;str[i]!='\0';i++)// run on the string and change the indexes of every char except the space
    {
        if(str[i]!=' ')
            j=i;
    }
    str[j+1]='\0'; // add a /0 at the end of the string
    if(strcmp(str,"history")==0){ // if the new string is equal to history change bool to 1
        return 1;
    }

    return 0; // else return 0
}
