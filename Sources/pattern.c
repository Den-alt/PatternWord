#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../Headers/inform.h"

#define SIZE 50
//Check if word is equal to pattern
//Parameters: pattern word and word for checking
//Return 1 => is found 0 => is not equal
int ComparingWordByPattern(char *pattern, const char *word)
{
    if (isalpha(*pattern))                                      //If meet the symbol
    {
        if (*pattern != *word)                                  //return 0 if symbol is not equal to pattern symbol in line
            return 0;
        else
            return ComparingWordByPattern(pattern+1,word+1);        //Keep on comparing
    }
    if (*pattern == '?')                                                        //If find '?' - pass this step
        return ComparingWordByPattern(pattern+1,word+1);
    if (*pattern == '*')                                                        //Find '*'
    {
        if ( *(pattern+1) == '\0' )                                             //If it is the end of the pattern it doesn't need to continue checking -> return 1
            return 1;
        if ( isalpha(*(pattern+1)))                                  //If meet the symbol find where in word is placed this character
        {
            if ( (word = strchr(word, *(pattern+1)) ) == NULL)
                return 0;
            else return ComparingWordByPattern(pattern+2,word+1);
        }
        if ( *(pattern+1) == '?')                        //If find '?' check is it the end of word otherwise if it isn't the end of pattern keep on comparing
        {
            if (*word == '\0')
                return 0;
            if (*(pattern+1) != '\0')
                swap(pattern, (pattern+1));
            return ComparingWordByPattern(pattern+1,word+1);
        }
        else
            return ComparingWordByPattern(pattern+1,word);
    }
    if (*pattern == '\0')                   //Pattern ended in any case word coincides
        return 1;
    if (*word == '\0')                      //Word ended earlier
        return 0;
    return 1;                               //Default return value
}
//Swap symbol * and ?
void swap(char *p1, char *p2)
{
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
//Search for all words in user file
//Parameters: pattern word
void SearchWords(const char * pattern)
{
    extern FILE * UserFile;
    extern FILE * ResultFile;
    int tempSent[SIZE];
    int check = 1, index = 0;
    while (check != 0)
    {
        do {
            tempSent[index] = fgetc(UserFile);
            if (tempSent[index] == EOF)
            {
                check = 0;
                index++;
                break;
            }
            index++;
        } while (isalpha(tempSent[index-1]) );                  //Gets word from file
        char word[index];
        for (int i = 0; i < index; ++i)                           //Prepare word to comparing
            word[i] = (char)tempSent[i];
        word[index-1] = '\0';
        index = 0;
        if (ComparingWordByPattern(pattern, word) == 1)                 //Compare word and if get 1, write word in file
        {
            printf("Word \"%s\" is equal to pattern!\n", word);
            fputs(word, ResultFile);
            fputc(' ', ResultFile);
        }
    }
}