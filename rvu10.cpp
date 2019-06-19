/*
  Task: Binary Tree Lab Review
  Objectives:
    -Create a binary tree class.
    -Data array field (private)
    -Count field
    -Add method(data)
    -The add method takes a data point, add it to the count position in the array then increases the count.
 
    Preorder(int)
    -Recursive method that prints all the nodes in a VLR pattern.
    (Recall 2i + 1 & 2i + 2)
*/


#include <iostream>
using namespace std;

class BST{
private:
   int count;
   int *arr;
public:
   BST(){
    count = 0;
    arr = new int[count];
   }
   void add(int data){
    arr[count] = data;
    count++;
   }
   void preOrd(int i = 0){
  
        if (arr[i] != 0 && i < count)
        {
            //N
            cout << arr[i] << " ";
            //L
            preOrd((i * 2) + 1);
            //R
            preOrd((i * 2) + 2);
        }
    }
   
   void print(){
       
    for (int i = 0; i < count; i++){
        
        cout << arr[i] << " ";
    
    }
   cout << endl;
   }

};

int main(){
    BST tree;
    int num;
    int n;
    cout<<"Enter num of elements to insert into binary tree:";
    cin>>num;
    cout<<"\nEnter the "<<num<<" values:";
    for (int i = 0; i <num; i++){
    cin>>n;
    tree.add(n);
    }
    tree.print();
    cout << " ----------------------------------------" << endl;
    tree.preOrd();

return 0;
}
