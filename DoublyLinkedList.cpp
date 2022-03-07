#include <iostream>

using namespace std;

//Author : Asu Simla Ayduran
//260822715

//Question 1
class Node{ 

public:
Node();
~Node(){} //We don't have to delete anything
Node(int data,Node* next,Node* previous);
// Adding setters and getters for my values
int getData();
void setData(int);
Node *getNext();
void setNext(Node*);
Node *getPrev();
void setPrev(Node*);

int data;
Node *next;
Node *previous;
};
Node::Node() {
    this -> data =0;
    this -> next = NULL;
    this -> previous =NULL;
}
Node::Node(int data,Node *next,Node *previous){
    this -> data = data;
    this -> next = next; //New Node   
    this -> previous = previous; //New Node
}
int Node::getData() {
    return data;
}
void Node::setData(int d) {
    data =d;
}
Node* Node::getNext() {
    return next; 
}
void Node::setNext(Node *n){
    next =n;
}
Node* Node::getPrev() {
    return previous;
}
void Node::setPrev(Node *p){
    previous =p;
}

//Question 2 
class DLLStructure {
 public : 
    DLLStructure();
    DLLStructure(int array[], int size);
    ~DLLStructure();
    // Question 3
    void printDLL();
    // Question 4
    void insertAfter(int valueToInsertAfter, int valueToBeInserted);
    void insertAtEnd(Node *end);
    // Question 5
    void insertBefore( int valueToInsertBefore, int valueToBeInserted);
    // Question 6
    void Delete(int value);
    // Question 7
    void sort();
    // Question 8
    bool isEmpty();
    // Question 9
    int getHead();
    int getTail();
    // Question 10
    int getSize();
    // Question 11
    int getMax();
    int getMin();
    //Question 12
     DLLStructure(DLLStructure& dlls);

private: 
Node *first;
Node *last;
 };

DLLStructure::DLLStructure() {
    this -> first = NULL;
    this -> last =  NULL;
}
DLLStructure::~DLLStructure(){ 
 	for(Node* current = first;current != NULL;current = first)
      {
        first = first->next;
        delete current;
      } 
}
DLLStructure::DLLStructure(int array[], int size) {
   this -> first = new Node(array[0], NULL, NULL); 
   this -> last = first; 
  Node* previous = first;
    for (int i = 1; i < size; i++)
    {
        Node* current = new Node(array[i], NULL, last);
        previous->setNext(current);
        previous = current;
    } 

}
void DLLStructure::printDLL(){
     //Set element (current) as the beginning of the list.Go through the list while it's not the last value
    //Output the value.Move one value along in the list
   Node* element= first; 
  while(element != NULL) {
    cout << element -> data << " " ;
   element = element->next;
  } 
  cout << endl;
}
void DLLStructure::insertAfter(int valueToInsertAfter,int valueToBeInserted){ 
     Node* node = new Node;
     node -> data = valueToBeInserted;
     node -> next = NULL;

     Node* current = first;
     while (current != NULL && current -> getData() != valueToInsertAfter ) {
         current = current -> next; 
     }
    if (current == NULL) {
        // If the value to insert after is not in DLL put the value at the end
       node->next = NULL;
       while (last->next != NULL)
        last = last->next;
         last->next = node;
         node->previous = last;
     } else if (current -> next == NULL) {
         // If the value will be placed after the last node of the list
            current->next = node;
            node->previous = current;
            last = node;
        }else {
         // else but if the value to insert after is in the list, insert value to be inserted 
            Node* nextPointer = current->next;
            current->next = node;
            node->previous = current;
            node->next = nextPointer;
            nextPointer->previous = node;
        }
        
}

void DLLStructure::insertBefore(int valueToInsertBefore,int valueToBeInserted) { 
    Node* nod = new Node;

    for (Node* current = first; current != NULL; current = current->next){
        if (current->getData() == valueToInsertBefore)
        {
            nod = current->previous;
            nod = nod->next;
            insertAfter(nod->data, valueToBeInserted);
            return;
        } 
    }
    Node* prevv = new Node;
    prevv->data = valueToBeInserted;
    prevv->next = first;
    first = prevv;
     }
void DLLStructure::Delete(int value) { 
        // Find the value in the list 
        Node* current=first;
        while(current -> getData() != value) {
            current=current->next;
        }
        if (current == NULL) {
            cout<<"The value is not in the list"<<endl;
        }
        // if value is not last node value
        if(current->next!=NULL) {
            current->previous->next=current->next;
            current->next->previous=current->previous;
            current->previous=NULL;
            current->next=NULL;
        }
}
void DLLStructure::sort(){
   int swapped, i;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    /* Checking for empty list */
    if (first == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = first;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1->data, ptr1->next->data);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }     while (swapped);
}
bool DLLStructure::isEmpty() { 
    
 if ((first == NULL)&& (last == NULL) ) {
        return true;
    } else {
        return false;
    }
}
int DLLStructure::getHead() {
  // Return the first element in the list
  return first->data;
}
int DLLStructure::getTail() {
  // Return the last element in the list
    if (first->next == NULL) {
            return first->data;
        } else {
            Node* current = first;
            while (current->next != NULL) {
                current = current->next;
            }
            return current->data;
        }
        return last -> data;
    }
int DLLStructure::getSize() {
  int size = 0;
    Node* current = this->first;
    while(current != NULL) {
      current = current->getNext(); 
      size++;
      }
    return size;
}
int DLLStructure::getMax(){
//Node current will point to head  
    Node *current = first;  
    int maximum = this->getHead();
        while(current != NULL) {  
            if(current ->data > maximum)   
                maximum = current -> data;  
            current = current -> next;  
        }  
        return maximum;  
    }  

int DLLStructure::getMin() {
    //Node current will point to head  
    Node *current = first;
    int minimum = this->getHead();
        while(current != NULL) {  
            if(minimum > current->data)  
                minimum = current->data;  
            current = current->next;  
        }  
    return minimum;
}
DLLStructure::DLLStructure(DLLStructure& dlls) {
  // We need to write our own constructor
}

// Given main function to test the code
// Try not to modify it unless you really have to
int main() {
int array[5] ={11,2,7,22,4};
DLLStructure dll(array,5);
dll.printDLL();
// Q 4
dll.insertAfter(7, 13); // To insert 13 after the first occurence of 7
dll.printDLL(); // the output should be: 11, 2, 7, 13, 22, 4
dll.insertAfter(25,7); // To insert 7 after the first occurence of 25
dll.printDLL(); // the output should be: 11, 2, 7, 13, 22, 4, 7
// Q 5 
dll.insertBefore(7,26); // To insert 26 before the first occurence of 7
dll.printDLL(); // the output should be: 11, 2, 26, 7, 13, 22, 4, 7
dll.insertBefore(19,12); // To insert 12 before the first occurence of 19
dll.printDLL(); // the output should be: 12, 11, 2, 26, 7, 13, 22, 4, 7
// Q 6
dll.Delete(22);
dll.printDLL(); // the output should be: 12, 11, 2, 26, 7, 13, 4, 7
// Q 7 
dll.sort();
dll.printDLL(); // the output should be: 2, 4, 7, 7, 11, 12, 13, 26
// Q 8
if (dll.isEmpty()) {
cout << "The list is empty" << endl;
}
// Q 9 
cout << "Head element is: " << dll.getHead() << endl;
cout << "Tail element is: " << dll.getTail() << endl;
// Q 10 
cout << "Number of elements in the list is: " << dll.getSize() << endl; 
// Q 11 
cout << "Max element is: " << dll.getMax() << endl;
cout << "Min element is: " << dll.getMin() << endl;
// Q 11 theory question 
cout << "Question 11 theory question: " << endl;
cout << "Best implementation of getMax and getMin would be making a sorted list from the start" << endl;
cout << "Inserting and deleting a value in a doubly linked list would cost O(1),and when we check" << endl;
cout << "what is the maximum and minimum value everytime after an insertion and deletion by comparing" << endl;
cout << "the added or deleted value with our latest getMax and getMin values.A good implementetion for sorted " << endl;
cout << "list would be bubblesort or mergesort " << endl;
// Q 12 
DLLStructure dll2 (dll);
dll2.printDLL(); // the output should be: 2, 4, 7, 7, 11, 12, 13, 26
// Q 12 theory question 
cout << "Question 12 theory question: " << endl;
cout << "If I rely on a default constructor I would only get a shallow copy instead of a deep copy." << endl;
cout << "The shallow copy only will copy the class data memebers and not copy any pointed-to data " << endl;
cout << "while a deep copy copies not only the class data members, but also makes separately stored" << endl;
cout << "copies of any pointed-to data. Also,a shallow copy shares the pointed to data with the original " << endl;
cout << "class object.So, we can easily say that a default constructor isn't the ideal way when a data member" << endl;
cout << "pointer points to dynamic data.Therefore,we should write out own copy constructor which makes a deep " << endl;
cout << "copy of the dynamic data" << endl;
return 0;
}

