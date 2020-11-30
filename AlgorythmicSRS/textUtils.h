#ifndef TEXTUTILS_H
#define TEXTUTILS_H


bool DeleteSymbols(char ch);
void ToLower(char& ch);
void formatString(std::string &s);
std::pair<std::string, int> maxPair(std::map<std::string, int> dict);

#endif