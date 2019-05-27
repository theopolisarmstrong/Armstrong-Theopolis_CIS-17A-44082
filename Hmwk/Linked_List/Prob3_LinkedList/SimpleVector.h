// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
    struct List{
        T val;
        List *next;
    };
    List *head = nullptr;
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0; }
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   //Push element
   void push(T);
   //Pull element
   T pull();
   
   //Linked List function declarations
   //Append
   void append(T);
   void insert(T);
   bool remove(T);
   void display();
};

template <class T>
void SimpleVector<T>::push(T e){
    //Allocate larger array
    T *temp = nullptr;
    try{
        temp = new T[arraySize+1];
    } catch (bad_alloc){
        memError();
    }
    //Copy old array values to new array
    for (int i = 0; i < arraySize; i++)
        *(temp + i) = *(aptr + i);
    *(temp + arraySize) = e; //Add new element
    arraySize++;
    delete [] aptr; //Delete old array
    aptr = temp; //Set SimpleVector array to larger array 
}
template <class T>
T SimpleVector<T>::pull(){
    int tempSize = arraySize - 1;
    T pulled = *(aptr + arraySize-1); //Save the last element
    //Allocate smaller array
    T *temp = nullptr;
    try{
        temp = new T[tempSize];
    } catch (bad_alloc){
        memError();
    }
    //Copy old array values to new array
    for (int i = 0; i < tempSize; i++)
        *(temp + i) = *(aptr + i);
    arraySize = tempSize;
    //Set SimpleVector array to smaller array 
    delete [] aptr;
    aptr = temp;
    return pulled;
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
void SimpleVector<T>::display(){
    List *ptr = head;
    while(ptr){
        cout << ptr->val << ' ';
        ptr = ptr->next;
    }
}
template <class T>
void SimpleVector<T>::append(T val){
    List *ptr = nullptr; //Iterator
    //New list node
    List *node = new List; 
    node->val = val;
    node->next = nullptr;
    if (head == nullptr){ //No nodes in list
        head = node; //Assign node as new list
    } else {
        ptr = head;
        while(node->next)
            ptr = ptr->next;
        ptr->next = node;
    }
}
template <class T>
void SimpleVector<T>::insert(T val){
    List *node = new List;
    List *ptr = nullptr;
    List *prev = nullptr;
    node->val = val;
    if (!head){
        head = node;
    } else {
        ptr = head;
        while(ptr != nullptr && ptr->val < val){
            prev = ptr;
            ptr = ptr->next;
        }
        if (prev == nullptr){
            head = node;
            node->next = ptr;
        } else
            node->next = ptr;
    }
}
template <class T>
bool SimpleVector<T>::remove(T val){
    bool status = false;
    List ptr = head;
    List prev = nullptr;
    if(!head){ //List is empty
        return status;
    }
    if(head->val == val){ //Value is the first element
        ptr = head->next;
        delete head;
        head = ptr;
        status = true;
    } else {
        while (ptr != nullptr && ptr->val != val){ //Skip non-matching values
            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr){ //Delete node
            delete ptr;
        }
    }
    return status;
}
   
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
#endif