#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Headers/inform.h"

FILE * UserFile;            //Opened file for reading
FILE * ResultFile;          //Created new file

//File Processing
//Parameters: the path to user file
//Return 0 if ERROR 1 if Okay
int OpeningFile(const char * Path)
{
    //Only create another file named "pattern_word.txt"
    char *FileName = "pattern_word.txt";
    //The path to the new file
    char NewFilePath[strlen(Path) + strlen(FileName)], *p;
    UserFile = fopen(Path, "r");                        //Open already existing file
    if (UserFile == NULL)
    {
        printf("File %s is not found\n", Path);
        return 0;
    }
    //Add version #ifdef for windows and linux
    strcpy(NewFilePath, Path);
    p = strrchr(NewFilePath, '/');
    strcpy(p+1, FileName);
    //Check if file with this name has already existed
    if (fopen(NewFilePath, "r") == NULL)
    {
        printf("Created file \"pattern_word.txt\"\n");
        ResultFile = fopen(NewFilePath, "w");               //Create new file with results
    }else
    {
        printf("File with the same name has already existing!\n");
        return 0;
    }
    return 1;
}
//Close all streams and free dynamic memory => finishing work
void FinishWorksWithFiles(char *Path, char * pattern)
{
    free(Path);
    free(pattern);
    printf("Program finished\n");
    fclose(UserFile);
    fclose(ResultFile);
}