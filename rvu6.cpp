/*
  Task: Array Based Queue
 
*/

#include <iostream>

class ArrayQueue{
    const static int maxSize = 10;
private:
    int arr[maxSize];
    int counter;
    int _front;
    int _back;

public:
    ArrayQueue(){
    _front = -1;
    _back = -1;
    }
    bool isEmpty(){
        return (_front == -1 && _back == -1);
    }
    void enqueue(int data){
        //first check if its empty
        if(_back == maxSize - 1){
            std::cout << "Cant add to full" << std::endl;
            return;
        }
        if(isEmpty()){
            arr[++_front] = data;
            _back++;
            counter = 0;
        } else{
          arr[++_back] = data;
          counter++;
        }
    }


    void dequeue(){
        if(isEmpty()){
            std::cout << "nothing to delete" << std::endl;
        }
        if(_front == _back){
            _front = _back = -1;
        } else {
            _front++;
            counter--;
        }
    }

    void printStuff(){
        if(isEmpty()){
            std::cout << "nothing to see " << std::endl;
            return;
        } else {
            for(int i = _front; i<= _back; i++){
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    void printCount(){
        if(isEmpty()){
            std::cout << "no items in the queue! " << std::endl;
        }
        else {
        std::cout << "There are .... " << counter + 1 << " in the queue!" << std::endl;
        }
    }

};

int main(){
    ArrayQueue q1;

    q1.dequeue();
    q1.printStuff();

    q1.enqueue(20);
    q1.printStuff();

    q1.enqueue(40);
    q1.printStuff();
    q1.printCount();

    q1.enqueue(50);
    q1.printStuff();

    q1.enqueue(60);
    q1.printStuff();

    q1.dequeue();
    q1.printStuff();
    q1.printCount();

    q1.enqueue(100);
    q1.printStuff();
    q1.printCount();

    q1.dequeue();
    q1.printStuff();
    q1.printCount();

    q1.dequeue();
    q1.dequeue();
    q1.printStuff();
    q1.printCount();

    q1.dequeue();
    q1.printStuff();
    q1.printCount();
}


/* 
  Grade: 0.8/1
  Comments: Doesn't handle circular logic. 

*/
