#pragma once
#include "Words.h"
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

Word::Word() {
    keyword = "";
    frequency = 0;
}

Word::Word(string w, int f) {
    keyword = w;
    frequency = f;
}

Word::~Word()
{

}

void Word::setFrequency(int f) {
    frequency = f;
}

void Word::setWords(string kw) {
    keyword = kw;
}

string Word::getWords() {
    return keyword;
}

int Word::getFrequency() {
    return frequency;
}

bool Word::operator==(Word w) {
    return(keyword == w.keyword);
}

bool Word::operator!=(Word w) {
    return(keyword != w.keyword);
}

bool Word::operator>(Word w) {
    return(keyword > w.keyword);
}

bool Word::operator<(Word w) {
    return(keyword < w.keyword);
}

bool Word::operator>=(Word w) {
    return(keyword >= w.keyword);
}

bool Word::operator<=(Word w) {
    return(keyword <= w.keyword);
}

ostream& operator<<(ostream& os, Word w)
{
    os << w.getWords() << " " << w.getFrequency();
    return os;
}