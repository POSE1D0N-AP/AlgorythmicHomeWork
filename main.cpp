#include <iostream>
using namespace std;

void radixSort(int arr[], int n){
  int max = arr[0];
  for(int x = 1; x < n; x++) {
    if(arr[x] > max) max = arr[x];
  }

  int rank;

  for (rank = 1; max/rank > 0; rank *= 10){
    int result[n], count[10] = {0};

    for (int i = 0; i < n; i++){
      count[(arr[i] / rank) % 10]++;
    }
    for (int i = 1; i < 10; i++){
      count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--){
      result[count[(arr[i] / rank) % 10] - 1] = arr[i];
      count[(arr[i] / rank) % 10]--;
    }
    for (int i =0; i < n; i++){
      arr[i] = result[i];
    }
  }
}

int main(){
  int a[8] = {50156, 123, 2256, 125, 50, 0, 78, 8999};

  for (int i = 0; i < 8; i++) cout << a[i] << (i < 7 ? " " : ";");
  cout << endl;
  radixSort(a, 8);
  for (int i = 0; i < 8; i++) cout<<a[i] << (i < 7 ? " " : ";");
  return 0;
}