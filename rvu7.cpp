/*
  Task: Link Based Queue 
*/

#include <iostream>

class LinkQueue{

    struct node {
        int data;
        node* next;

        node(int d, node* n = 0){
            data = d;
            next = n;
        }
    };

private:
    node* _front;
    node* _rear;
    int counter;

public:
    LinkQueue(){
        _front = 0;
        _rear = 0;
        counter = 0;
    }
    bool isEmpty(){
        return _front == 0;
    }
    void enqueue(int x){
        //if queue is empty
        node* temp = new node(x);
        /*
        creates a node that initializes and points to nothing.
         must point to some other thing..
        */
        if(isEmpty()){
            _front = temp;
            _rear = temp;
            counter++;
        } else{
            _rear->next = temp;
            _rear = temp;
            counter++;
        }
    }
    void dequeue(){
        if(isEmpty()){
            std::cout << "Nothing to delete from queue list ..." << std::endl;
        }
        node* temp = _front;
        std::cout << "de-queuing " << temp->data << " now!\n";
        _front = _front->next;
        delete temp;
        counter--;
    }

    void printCount(){
        if(isEmpty()){
            std::cout << "no elements in queue" << std::endl;
        }
        std::cout << "There are " << counter  << " in the queue list. " << std::endl;
    }

    void printStuff(){
        if(isEmpty()){
            std::cout << "nothing to print out" << std::endl;
        } else {
        for(node* temp = _front; temp != 0; temp = temp->next){
            std::cout << temp->data << " ";
        }
        std::cout << std::endl;
        }
    }

};

int main(){

    LinkQueue q1;

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

    return 0;

}
