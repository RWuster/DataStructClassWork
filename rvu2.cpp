/* 
  Task: Linear Search
  Search an un-ordered array an integers for a value, 
  if the value is found return the index of its position in the array, 
  if not found, return -1.
*/

#include <iostream>
#include <string>
using namespace std;


int l_search(int arr[], int arrSize, int value){
    int p = -1;
    int k;
    for(k = 0;k < arrSize; k++){
        if(arr[k] == value){
            p =  k;
        }
    }
    return p;
}

int main()
{
    int arr [] = {23, 1, 15, 4, 17, 19, 2, 100};
    int size = sizeof(arr)/sizeof(arr[0]);
    int value = 100;

    cout <<"Position: "  << l_search(arr, size, value) << endl;
    return 0;
}

