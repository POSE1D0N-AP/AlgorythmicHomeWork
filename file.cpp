#include <iostream>
#include <iterator> 
#include <map> 
using namespace std;

void dropElement(map<string, int> &dict, int ceiling){
  map<string, int> :: iterator it;
  for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
    if(iter->second > ceiling){
      dict.erase(iter->first);
    }
  }
}

map<int, string> swapElement(map<string, int> dict){
  map<int, string> swappedMap;

  map<string, int> :: iterator it;
  for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
    swappedMap.insert({iter->second, iter->first});
  }

  return swappedMap;
}

void printMap(map<string, int> dict){
  map<string, int> :: iterator it;
  for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
    cout << iter->first << ": " << iter-> second << endl;
  }
}

int main() {
  map<string, int> *dict = new map<string, int>();
  dict->insert({"RAM", 50000});
  dict->insert({"HDD", 80000});
  dict->insert({"CPU", 100000});
  dict->insert({"GPU", 150000});
  dict->insert({"Mother Board", 40000});

  printMap(*dict);
  dropElement(*dict, 70000);
  cout << "Drop Element --------------" << endl;
  printMap(*dict);
  cout << "Swap Element --------------" << endl;
  map<int, string> swapped = swapElement(*dict);
  map<int, string> :: iterator it;
  for (auto iter = swapped.begin(); iter != swapped.end(); ++iter) {
    cout << iter->first << ": " << iter-> second << endl;
  }
}
