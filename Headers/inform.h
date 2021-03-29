#ifndef PATTERNWORD_INFORM_H
#define PATTERNWORD_INFORM_H

//path to demo file
//  ../test/Template4.txt op?*o*?p?
//  ../test/Template3.txt ki*??
//  ../test/Template2.txt ui*?k*f*
//  ../test/Template1.txt *?o**
//Output file name - test/pattern_word.txt

//files.c
int OpeningFile(const char *);
void FinishWorksWithFiles(char *, char *);

//pattern.c
int ComparingWordByPattern(char *, const char *);
void swap(char *, char *);
void SearchWords(const char *);

#endif //PATTERNWORD_INFORM_H
