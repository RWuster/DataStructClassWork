/*
  Task: Binary Search Tree
*/

#include <iostream>
struct node{
    int data;
    node* left;
    node* right;

    node(int d, node* l = 0, node* r = 0){
        data = d;
        left = l;
        right = r;
    }
};

class Tree{
public:
    node* root;
    Tree(){
        root = 0;
    }
    bool isEmpty(){
        return root == 0;
    }
    bool _insert(int x){

        //first search for node left or right
        node* temp = root;
        node* prev = 0;
        while(temp != 0){
            prev = temp; //oarent node

            if(x < temp->data){
                temp = temp->left;
                //Assuming this line is for breaking out of the while loop?
            } else {
                temp = temp->right;
                //Assuming this line is for breaking out of the while loop?
            }
        }
        /*
        interesting block of code:
        Assuming that what i assumed on line 35, 38: temp is really a temp variable 
        
        prev will point to the node before it points to null? 
        
        1) the first case of root is empty, temp = root = 0; would skip while loop, fall into 
        first if block and be executed. 
        insert vs add:
            a) with insert, you dont check if prev->left/right is empty before setting value 
            you check with the intial while loop. 
            b) with add, 
        */
        if(isEmpty()){
            root = new node(x);
        } else if ( x < prev->data){
            prev->left = new node(x);
        } else if ( x > prev->data){
            prev->right = new node(x);
        } else {
            return false;
        }
        return true;
    }

    bool _add(int x){
        node* n = new node(x);
        if(isEmpty()){
            root = n;
            return true;
        }
        node* temp = root;
        while(true){
            if(x < temp->data){

                if(temp->left == 0){
                    /*
                    also the condition before: temp->left != 0;
                    is basically saying that if a value exist, change the value and break.
                    must change to temp->left == 0 - which would be if its empty, change the value
                    compare to stay at the same value and keep changing it.

                    */

                    temp->left = n;
                    break;
                } else {

                    temp = temp->left;
                }
            } else if (x > temp->data){

                if(temp->right == 0){

                    /*temp->right = x;
                    gets an error with this line because im trying to set a reference of node->right to an integer
                    i should be setting the reference of temp->right to node i created at the top of the function
                    */
                    temp->right = n;
                    break;
                } else {

                    temp = temp->right;
                }
            } else if ( x == temp->data){

                return false;
            }

        }
       return true;
    }


    void print_inOrder(node* n){
        if(n != 0){
            print_inOrder(n->left);
            std::cout << n->data << " ";
            print_inOrder(n->right);
        }
    }
};

int main(){

  Tree t1;

  t1._add(1);
  t1.print_inOrder(t1.root);
  std::cout << std::endl;

  t1._add(10);
  t1.print_inOrder(t1.root);
  std::cout << std::endl;

  t1._add(5);
  t1.print_inOrder(t1.root);
  std::cout << std::endl;

  t1._add(20);
  t1.print_inOrder(t1.root);
  std::cout << std::endl;

  t1._add(19);
  t1.print_inOrder(t1.root);
  std::cout << std::endl;

  t1._add(100);
  t1.print_inOrder(t1.root);
  std::cout << std::endl;

  t1._add(110);
  t1.print_inOrder(t1.root);
  std::cout << std::endl;

  t1._add(4);
  t1.print_inOrder(t1.root);
  std::cout << std::endl;
    
}
