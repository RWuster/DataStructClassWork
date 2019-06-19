/*
    Task: I/O Review:
      1. Read a sentence from the console.
      2. Break the sentence into words using the space character as a delimiter.
      3. Iterate over each word, if the word is a numeric value then print its value doubled, otherwise print out the word, with each output on its own line.
    
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string sentence, word;
    float value = 0.0;
    getline(cin, sentence);

    stringstream s1;
    s1.str(sentence);

    while(s1 >> word){
        value = atof(word.c_str());
        if(value == 0){
                cout << word << endl;
        } else {
            value *= 2;
            cout << value << endl;
        }
    }
    return 0;
}

 /*Sample output: 
Sentence: Hello RWuster, are you 18.5 years old?

 
Output:
Hello
RWuster,
are
you
37
years
old?

 */
