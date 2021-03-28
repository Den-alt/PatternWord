#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/inform.h"

#define SIZE 200

int main(int argc, char* argv[])
{
    //Pointer to the path to file
    char *PathToFile = NULL;
    if (argc > 1)
    {
        printf("File is transferred to the program in following way:\nPath => %s\n", argv[2]);
        PathToFile = strdup(argv[2]);
    }
    else
    {
        char tempSent[SIZE];
        printf("None file are founded. Please write full path to your file:\n");
        gets(tempSent);
        PathToFile = strdup(tempSent);
    }
    printf("Entered path => %s", PathToFile);
    FreeMemory(PathToFile);
    return 0;
}
//Delete dynamic array
void FreeMemory(char *Path)
{
    free(Path);
}