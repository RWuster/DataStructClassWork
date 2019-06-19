/* 
  Task: Dynamic Arrays
  Objective:  Create an array of numbers based upon user input.
  
  Program logic:
  Ask the user for how big to size the array.
  Create an array based upon that size.
  Ask for a number, add that number to the array.
  Repeat adding to the end until all numbers have been entered or until they enter -1 for the number.
  Print the list.
*/


#include <iostream>

void getStuff(int *arr, int size1){
    int k;
    std::cout << "Enter in number for array, or -1 to quit." << std::endl;
    int w;
    for(k = 0;k < size1; k++){
     std::cin >> w;
     if(w == -1){
        return;
     }
     arr[k] = w;
    }
}

void printStuff(int *arr, int size1){
    int k;
    for(k = 0;k < size1; k++){
        std::cout << arr[k] << " ";
    }
    std::cout << std::endl;

}
int main()
{
  int size1;
  std::cout << "Enter in size of array: " << std::endl;
  std::cin >> size1;

  int *arr;
  arr = new int [size1];

  getStuff(arr, size1);
  printStuff(arr, size1);

  delete [] arr;
  arr = NULL;
  return 0;
}
