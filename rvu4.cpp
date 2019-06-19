/*
  Task: Link Based Stack
  Create a class/struct for a node.
  Create a class/struct for a list.

  Members:
  Top - a node that tracks the top of the stack
  Count - indicates how many items are on the stack.

  Methods:
  Push
    - Accepts a number and adds to the top of the stack.
  Pop
    - Returns a number from the top of the stack.
    - If the stack is empty, emit an error indicating the stack is empty.
  IsEmpty
    - Returns a boolean indicating if the stack is empty.
*/

#include <iostream>

struct nodez{
        int data;
        nodez* next;

        nodez(int d, nodez* n = 0){
            data = d;
            next = n;
        }
};
class NewStackList {

private:
    nodez* top;

public:
    NewStackList(){
        top = 0;
    }
    bool isEmpty() {
        return top == 0;
    }
    void push(int x){
        //create a new node
        nodez* nn = new nodez(x);

        //check if stack there is anything in the stack
        if(isEmpty()){
            top = nn;
        } else {
            nn->next = top;
            top = nn;
        }
    }
    bool pop(){
     if(isEmpty()){
        std::cout << "Nothing to pop" << std::endl;
        return false;
        }
        //else
        nodez* n2;
        n2 = top;
        top = top->next;
        delete n2;
        return true;
    }

    void print(){
        for(nodez* n = top; n != 0; n=n->next){
        std::cout << n->data << " ";
    }
    std::cout << std::endl;
    }
};

int main(){
    
    NewStackList l1;
    l1.push(100);
    l1.push(200);
    l1.push(300);

    l1.print();

    l1.pop();
    l1.pop();
    l1.print();

    l1.push(3000);
    l1.push(400);
    l1.push(10);

    l1.print();
    l1.pop();
    l1.print();

}   


/* 
  Grade: 0.6/1
  Comments:
  Missing count. Also pop should return what was on the top of the stack. 
*/
