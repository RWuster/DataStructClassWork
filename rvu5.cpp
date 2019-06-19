/* 
  Task: sort
  Write a sort function that takes an array and sorts the values.
*/

#include <iostream>

void swapV(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void printStuff(int *anyArr, int sizeArr){
    for(int i = 0; i < sizeArr;i++){
        std::cout << anyArr[i] << " ";
    }
    std::cout << std::endl;
}
void bubbleSort(int *unsortArr, int sizeOfArr){
    bool isSorted = false;
    while(isSorted == false){
        int k = 0;
            for(int i = 0;i<sizeOfArr;i++){
                if(unsortArr[i] > unsortArr[i+1]){
                    swapV(unsortArr[i], unsortArr[i+1]);
                    k++;
                }
            }
        printStuff(unsortArr, sizeOfArr);
        if(k==0){
            isSorted = true;
        } else {
            k = 0;
        }
    }
}

int main(){
    int hello [] = {10, 1, 100, 24, 19, 4, 200, 30};
    int sizeOfHello = sizeof(hello)/sizeof(hello[0]);
    std::cout << "This is the unsorted array....\n";
    printStuff(hello, sizeOfHello-1);

    std::cout << "Here is the sorted array....." << std::endl;
    bubbleSort(hello, sizeOfHello-1);

}

/*
  Grade: 1.0/1.0
*/
