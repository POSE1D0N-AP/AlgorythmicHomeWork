#include <fstream>
#include <iostream>
#include <iterator> 
#include <string>  
#include <algorithm>  
#include <map> 
#include "textUtils.h"
using namespace std;


class TextUtil {
  string maintainedExtensions [2] = { ".txt", ".doc"};

  string ErrorsController(int errorN){
    switch(errorN){
      case 1:
        return "ERROR #1: Incorrect input data!";
        break;
      case 2:
      return "ERROR #2: File Can't Open or incorrect file name.";
      break;
    }
    return NULL;
  }

  void TextParser(ifstream & file){
    map<string, int> wordsCount;
    map<string, int>::iterator itr; 
    string word;
        
    file >> word;
    formatString(word);
    wordsCount.insert({word, 1});

    while(true){
      file >> word;

      formatString(word);
      bool flag = true;
      for (itr = wordsCount.begin(); itr != wordsCount.end(); ++itr) { 
        if(itr->first == word){
          itr->second++;
          flag = false;
          break;
        }
      } 
      if(flag){
        wordsCount.insert({word, 1});
      }

      if(file.eof()){
        file.close();
        break;
      }
    }
    PrintTextInfo(wordsCount);
  }
      
   void PrintTextInfo(map<string, int> wordsCount){
    map<string, int>::iterator itr;

    ofstream outFile("wordsLog.txt", ios::app);


    

    cout << "All text information: " << endl;
    for (itr = wordsCount.begin(); itr != wordsCount.end(); ++itr) { 
      cout << itr->first << ": " << itr->second << endl;
      outFile << itr->first << ": " << itr->second << endl;
    }

    cout << "---------------------" << endl;
    cout << "The most common word: " << endl;
    outFile << "---------------------" << endl;
    outFile << "The most common word: " << endl;
    pair<string, int> mostCommonWord = maxPair(wordsCount);
    cout << mostCommonWord.first << ": " << mostCommonWord.second << endl;
    outFile << mostCommonWord.first << ": " << mostCommonWord.second << endl;
    outFile << "---------------------" << endl;
    outFile.close();   
  }

  public:

  void ProgramInterface(){
    
    cout << "Word int Text counter WITC ver0.1" << endl;
    while(true){
      int fileExtension;
      string fileName;

      cout << endl << "Please select file file extension:" << endl;
      cout << "1 - .txt" << endl << "2 - .doc" << endl;
      cin >> fileExtension;

      if(fileExtension > sizeof(maintainedExtensions) || fileExtension < 1) {
        cout << ErrorsController(1) << endl;
        continue;
      }

      cout << "Please input File name: ";
      cin >> fileName;

      ifstream fin(fileName+maintainedExtensions[fileExtension-1]); 
  
      if (!fin.is_open()) 
        cout << ErrorsController(2); 
      else{
        TextParser(fin);
      }

      char exitVar;
      cout << "Do you want to continue using?" << endl;
      cout << "Y/n: ";
      cin >> exitVar;

      if(tolower(exitVar) == 'y') continue;
      else if (tolower(exitVar) == 'n') break;
    }

    cout << "Have a nice day!" << endl;
  }
};

int main(){
  TextUtil * tu = new TextUtil();
  tu->ProgramInterface();
  delete tu;
}