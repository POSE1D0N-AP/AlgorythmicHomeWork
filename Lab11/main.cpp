#include <iostream>
#include <fstream>
#include <iterator> 
#include <algorithm> 
#include <list>
#include <map>
#include <string>  
using namespace std;

void ToLower(char& ch){
  ch = tolower(ch);
}

class Dictionary{
  private:
    map<char, list<string>> dictionary;

    bool formatString(string &s){
      for_each(s.begin(), s.end(), ToLower);

      bool flag = true;
      for(char c: s){
        if(int(c) < 97 || int(c) > 122) flag = false;
      } 
      s[0] = toupper(s[0]);
      return flag;
    }
  public: 
    Dictionary(){
      for(int i = 65; i <= 90; i++){
        dictionary.insert({char(i), {}});
      }
    }

    void ReadFile(string fileName){
      ifstream fin(fileName); 

      if (!fin.is_open()) 
        cout << "Cant open the File!" << endl;
      else{
        while(true){
          string word;
          fin >> word;
          AddWord(word);

          if(fin.eof()){
            fin.close();
            break;
          }
        }
        SortDictionary();
      }
    }

    list<string> SearchWord(string word){
      map<char, list<string>>::iterator iter;
      list<string> results;
      if(formatString(word)){
        for(string s: dictionary[word[0]]){
          if(s.substr(0, word.size()) == word) results.push_back(s);
        }
      }
      return results;
    }

    void PrintAllDictionary(){
      map<char, list<string>>::iterator iter;
      for(iter = dictionary.begin(); iter != dictionary.end(); ++iter){
        cout << iter->first << ": ";
        for(string s: iter->second){
          cout << "\t" << s << endl;
        }
        cout << endl;
      }
    }

    void PrintOneDictionary(char ch){
      for(string s: dictionary[ch]){
        cout << "\t" << s << endl;
      }
      cout << endl;
    }

    void SortDictionary(){
      map<char, list<string>>::iterator iter;
      for(iter = dictionary.begin(); iter != dictionary.end(); ++iter){
        iter->second.sort();
      }
    }
    void AddWord(string word){
      if(formatString(word)){
        bool flag = true;
        for(string s: dictionary[word[0]]){
          if(s == word){
            flag = false;
            break;
          }
        }
        if(flag) dictionary[word[0]].push_back(word);
        SortDictionary();
      }
    }
    void RemoveWord(string word){
      if(formatString(word)){
        dictionary[word[0]].remove(word);
      }
    }

    void ReplaceWord(string oldWord, string newWord){
      if(formatString(oldWord) && formatString(newWord)){
        if(oldWord[0] == newWord[0]){
          replace(dictionary[oldWord[0]].begin(), dictionary[oldWord[0]].end(), oldWord, newWord);
          SortDictionary();
        }
      }
    }

    void SaveToFile(string fileName = "log.txt"){
      ofstream outFile(fileName);
      map<char, list<string>>::iterator iter;

      for(iter = dictionary.begin(); iter != dictionary.end(); ++iter){
        outFile << iter->first << ": ";
        for(string s: iter->second){
          outFile << "\t" << s << endl;
        }
        outFile << endl;
      }
    }

};

int main() {
  Dictionary dict;
  dict.ReadFile("words.txt");
  dict.PrintAllDictionary();

  cout << "------------------" << endl;
  for(string s: dict.SearchWord("se"))
    cout << s << endl;
  
  cout << "------------------" << endl;

  dict.AddWord("monomakh");
  dict.PrintOneDictionary('M');
  cout << "------------------" << endl;
  dict.RemoveWord("Mus");
  dict.PrintOneDictionary('M');
  cout << "------------------" << endl;
  dict.ReplaceWord("Metus", "Mytus");
  dict.PrintOneDictionary('M');
  dict.SaveToFile();
}