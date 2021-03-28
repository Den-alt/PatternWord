#ifndef PATTERNWORD_INFORM_H
#define PATTERNWORD_INFORM_H

//path to demo file
// /home/den/Documents/Template.txt
//Output file name - pattern_word.txt

//files.c
int OpeningFile(const char *);
void FinishWorksWithFiles(char *, char *);

//pattern.c
int ComparingWordByPattern(const char *, const char *);
void SearchWords(const char *);

#endif //PATTERNWORD_INFORM_H
