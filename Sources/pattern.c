#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../Headers/inform.h"

#define SIZE 50
//Check if word is equal to pattern
//Parameters: pattern word and word for checking
//Return 1 => is found 0 => is not equal
int ComparingWordByPattern(const char *pattern, const char *word)
{
    const char * checkPattern = pattern;
    int index;
    const char *current = word-1;
    /*for (index = 0; checkPattern < pattern + strlen(pattern); checkPattern++)
    {
        if (isalpha(*checkPattern))
        {
            current = strchr(current+1, *checkPattern);
            if (current == NULL || *current == '\0')
                return 0;
            index++;
        }
        if((*checkPattern == '?'))
        {
            index++;
        }
    }
    printf("%d\n",index);
    if (strlen(word) < index)
        return 0;*/
    return 1;
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
        } while (isalpha(tempSent[index-1]) );
        char word[index];
        for (int i = 0; i < index; ++i)
            word[i] = (char)tempSent[i];
        word[index-1] = '\0';
        index = 0;
        if (ComparingWordByPattern(pattern, word) == 1)
        {
            printf("%s\n", word);                       //TEST
            printf("Word is equal to pattern!\n");
        }
    }
}