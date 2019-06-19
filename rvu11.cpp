/* 
  Task: 
  -calculate the results of Reverse Polish expressions that are provided by the user. 
  -You must use a linked list to maintain the stack for this program (array implementations of the stack will not receive full credit).

   -You must handle the following situations (errors):
    -Too many operators (+ - / *)
    -Too many operands (doubles)
    -Division by zero
*/

#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;

    node(int d, node* n = 0){
        data = d;
        next = n;
    }
};

class StackList{
private:
    node* top;
    int counter;

public:
    StackList(){
        top = 0;
        counter = 0;
    }
    ~StackList(){
        node* n = top;
        node* t = 0;
        while( n != 0){
            t = n;
            n = n->next;
            delete t;
        }
    }
    bool isEmpty(){
        return top == 0;
    }
    void push(int x){
        node* n = new node(x);
        if(isEmpty()){
            top = n;
            counter++;
        } else {
            n->next = top;
            top = n;
            counter++;
        }
    }
    int pop(){
        int k;
        if(isEmpty()){
            return -11;
        }
        node* n = top;
        k = n->data;
        top = top->next;
        delete n;
        counter--;
        return k;
    }
    void print(){
        for(node* n = top; n != 0; n = n->next){
            cout << n->data << " ";
        }
        cout << endl;

    }


};


int main(){


    int num = 0;
    int operands, operators = 0;
    char exp[50];

    StackList s1;

    cout << "*************** Reverse Polish Notation Calculator ***************" << endl;
    cout << "Enter your expression now: " << endl;

    cin.getline(exp, 50,'\n');

    for(int i = 0; i < 50 && exp[i] != '\0'; i++){

        if(exp[i] >= '0' && exp[i] <= '9'){

            do {
                num = num * 10;

                num += (exp[i] - '0');
                i++;
            } while(exp[i] != ' ');


            s1.push(num);
            operands++;
            num = 0;
        }
        else {

            if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
                operands++;
                int a = s1.pop();
                int b = s1.pop();
                int result = 0;

                switch(exp[i]){
                     case '+':
                            result = a + b;
                            break;
                        case '-':
                            result = a - b;
                            break;
                        case '*':
                            result = a * b;
                            break;
                        case '/':
                            if(b == 0){
                                cout << "Canot divide by zero" << endl;
                                break;
                            }
                            result = a / b;
                            break;
                }
                s1.push(result);
            }
        }
    }
    if(operands < operators){
        cout << "Need more operands (doubles)" << endl;
    } else if (operands == operators) {
        cout << "To many operators (+ ,- ,* ,/)" << endl;
    } else {
        cout << endl;
    }
    cout << "= " << s1.pop() << endl;
    s1.print();

    return 0;

}


/*
Sample output:
10 15 + = 25
10 15 - = 5
2.5 3.5 + = 470
10 0 / = 0
*/

/* 
  Grading: 8/10
  Comment:
    - Does not accept multiple expressions

*/
