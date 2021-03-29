#include <stdio.h>
#include <string.h>
#include "Headers/inform.h"

#define SIZE 200

int main(int argc, char* argv[])
{
    //Pointer to the path to file
    char *PathToFile;
    //Pattern word
    char *pattern;
    char tempSent[SIZE];
    if (argc > 1)                           //Command line
    {
        printf("File is transferred to the program in following way:\nPath => %s\n", argv[1]);
        PathToFile = strdup(argv[1]);
    }
    else                                    //User have to set value
    {
        printf("None file are founded. Please write full path to your file:\n");
        gets(tempSent);
        PathToFile = strdup(tempSent);
    }
    printf("Enter pattern word (? - one any letter, * - any number of characters or their absence)\n");
    gets(tempSent);
    pattern = strdup(tempSent);                                           //Init pattern word
    printf("Entered path => %s\n", PathToFile);
    if (OpeningFile(PathToFile) == 0)                                    //Check if files init correctly
    {
        FinishWorksWithFiles(PathToFile,pattern);
    }
    SearchWords(pattern);                           //Compare all words with pattern word
    FinishWorksWithFiles(PathToFile,pattern);       //Finish work: free memory and close files
    return 0;
}