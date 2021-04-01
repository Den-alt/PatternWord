# Pattern Word
A console application for finding words by pattern

### *Task:*
User specifies the path to the file and the pattern word.
The program processes all words in the file and creates 
a new file "pattern_word.txt" in the same 
directory, where places all words that match the template.

**Pattern word consists of:**
1. Letters of English alphabet.
2. Symbol ? denotes 1 arbitrary letter.
3. Symbol * indicates any number of arbitrary letters or their absence.

#### Path to demo file
1. ../test/Template1.txt `*?o**`
2. ../test/Template2.txt `ui*?k*f*`
3. ../test/Template3.txt `ki*??`
4. ../test/Template4.txt `op?*o*?p?`
#### Output file name - test/pattern_word.txt
