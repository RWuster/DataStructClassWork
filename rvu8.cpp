/* 
  Task: Sorted Linked List
  
  Objective:  Create a sorted singly linked list of numbers based upon user input.
  
  Program logic:
  Ask for a number, add that number to the list in sorted position, print the list.
  Repeat until they enter -1 for the number.
*/

#include <iostream>
struct node {
	int data;
	node* next;

	node(int d, node* n = 0){

		data = d;
		next = n;
	}
};

class SinglyList{
private:
	node* head;
	node* tail;
	//int counter;
public:
	SinglyList(){
		head = tail = 0;
		//counter = 0;
	}
	~SinglyList(){
		node* n = head;
		node* t = 0;
		while(n != 0){
			t = n;
			n = n->next;
			delete t;
		}
		std::cout << "Done" << std::endl;
	}

	bool isEmpty(){
		return head == 0;
	}

	void add(int x){
		node* n = new node(x);
		if(isEmpty()){
			head = tail = n;
			//counter++;
		} else {
			tail->next = n;
			tail = n;

			//counter++;
		}
	}
	void sort_list(){
        node *i, *j;
        int temp;

        for(i = head; i != 0; i = i->next){

            for(j = i->next; j!= 0;j = j->next){

                if(i->data > j->data){
                        temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                }
            }
        }
	}

	void print(){
		for(node* n = head; n != 0; n = n->next){
			std::cout << n->data << " ";
		}
		std::cout << std::endl;
	}
};

int main(){
	SinglyList l1;
	int input;
	int k = 0;
    while(k != 1){
        std::cout << "Enter in numbers, or -1 to quit\n";
        std::cin >> input;
        if(input == -1){
            ++k;
            break;
        }
        l1.add(input);
        l1.sort_list();
        l1.print();
	}
	l1.print();
}
