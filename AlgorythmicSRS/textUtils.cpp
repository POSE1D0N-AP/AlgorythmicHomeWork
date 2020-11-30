#include <iostream>
#include <iterator> 
#include <string>  
#include <algorithm>  
#include <map> 
using namespace std;

void ToLower(char& ch){
   ch = tolower(ch);
}

bool DeleteSymbols(char ch){
  return (int(ch) < 97 || int(ch) > 122);
}

void formatString(string &s){
  for_each(s.begin(), s.end(), ToLower);
  s.erase(remove_if(s.begin(), s.end(), DeleteSymbols), s.end());
}

pair<string, int> maxPair(map<string, int> dict){
  int max = 0;
  string wordMax;
  map<string, int>::iterator itr; 
  for (itr = dict.begin(); itr != dict.end(); ++itr) { 
    if(itr->second > max){
      max = itr->second;
      wordMax = itr->first;
    }
  }
  return {wordMax, max};
}