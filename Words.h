#pragma once
#ifndef _WORD_
#define _WORD_
#include <string>
#include <iostream>

using namespace std;

class Word
{

private:
    string keyword;
    int frequency;

public:
    // Constructor
    Word();
    Word(string w, int f);
    // Destructor
    ~Word();

    // Other methods
    void setWords(string kw);
    void setFrequency(int f);

    string getWords();
    int getFrequency();

    // operator overloads
    bool operator==(Word w);
    bool operator!=(Word w);
    bool operator>(Word w);
    bool operator<(Word w);
    bool operator>=(Word w);
    bool operator<=(Word w);
    friend ostream& operator<<(ostream& os, Word w);
};

#endif