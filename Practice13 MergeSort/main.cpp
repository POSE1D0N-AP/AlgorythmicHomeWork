#include <iostream>
using namespace std;

void merge(int *arr, int left, int right, int mid){
  int leftSize, rightSize;

  leftSize = mid - left + 1; 
  rightSize = right - mid;

  int leftArr[leftSize];
  int rightArr[rightSize];

  for(int i = 0; i < leftSize; i++){
    leftArr[i] = arr[left + i];
  }
  for(int i = 0; i < rightSize; i++){
    rightArr[i] = arr[mid + 1 + i];
  }
  // 2 3 2 3   7 1 0
  // 15 5    X X
  int i = 0; 
  int j = 0; 
  int k = left;

  while(i < leftSize && j < rightSize) {
    if(leftArr[i] <= rightArr[j]) {
      arr[k] = leftArr[i];
      i++;
    }
    else{
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }
  
  while(i < leftSize) {       
    arr[k] = leftArr[i];
    i++; 
    k++;
  }
  while(j < rightSize) {
    arr[k] = rightArr[j];
    j++; 
    k++;
  }
}

void mergeSort(int *arr, int left, int right){
  int mid;
  if (left >= right){
    return;
  }

  mid = (left + right) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
        
  merge(arr, left, right, mid);
}

void printArray(int *arr, int len){
  for (int i = 0; i < len; i++)
  {
    cout << arr[i]<<" ";
  }
  cout << endl;
}

int main()
{
  int arr[20];

  for (int i = 0; i < 20; i++) { 
    arr[i] = rand() % 100 + 1; 
  }
  cout << "Generated array:" << endl;
  printArray(arr, 20);
  mergeSort(arr, 0, 19);
  cout << "Sorted array:" << endl;
  printArray(arr, 20);
}