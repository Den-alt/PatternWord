#ifndef PATTERNWORD_INFORM_H
#define PATTERNWORD_INFORM_H

//path to demo file
//  /home/den/Documents/Template4.txt op?*o*?p?
//  /home/den/Documents/Template3.txt ki*??
//  /home/den/Documents/Template2.txt ui*?k*f*
//  /home/den/Documents/Template.txt *?o**
//Output file name - pattern_word.txt

//files.c
int OpeningFile(const char *);
void FinishWorksWithFiles(char *, char *);

//pattern.c
int ComparingWordByPattern(char *, const char *);
void swap(char *, char *);
void SearchWords(const char *);

#endif //PATTERNWORD_INFORM_H
