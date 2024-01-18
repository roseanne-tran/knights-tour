/*******************************************************************************
 *  Author             : Hang Tran
 *  Assignment 3       : stack
 *  Class              : CS8
 *  Due Date           : 03/20/18
 ******************************************************************************/

#ifndef MYSTACK_H
#define MYSTACK_H


enum STACK_ERRORS {STACK_EMPTY, STACK_FULL};

template<typename T>
struct node
{
    T data;       //IN - the value of node
    node *next;  //IN - pointer points to next
    node( T data ) : data(data), next(0) {}
};


template<typename T>
class myStack
{
    public:
        //default constructor
        myStack();
        //default constructor to capacity as parameter
        myStack(size_t cap);
        //destrcutor
        ~myStack();
        //copy constructor
        myStack(const myStack &other);
        //assignment operator
        myStack& operator=(const myStack &other);
        //check is stack is empty
        bool empty();
        //check if stack is full
        bool full();
        //delete all elements
        void clear();
        //get the element on top
        T peek();
        //delete the element on op
        void pop();
        //add element on top
        void push(const T &val);
        //display the content of the stack
        void display();
        void printReverse();
        void printReverse(node<T> *n);


     private:
        node<T> *tos;               //pointer to a list
        int mySize, myCapacity;     //size and capacity

        //delete all element in the list
        void nukem();
        //make copy
        void copy(const myStack &other);
};

template<typename T>
myStack<T>::myStack()
{
    tos = NULL;   //initialize pointer tos points to nothing(NULL) at the beginning
    mySize = 0;
    myCapacity = 1000;
}

template<typename T>
myStack<T>::myStack(size_t cap)
{
    tos = NULL;
    mySize = 0;
    myCapacity = cap;
}


template<typename T>
myStack<T>::~myStack()
{
    nukem();
}

template<typename T>
myStack<T>::myStack(const myStack &other)
{
    nukem();
    copy(other);
}

template<typename T>
myStack<T>& myStack<T>::operator=(const myStack &other)
{
   if(this != &other)
    {
       nukem();
       copy(other);
    }
    return *this;

}

template<typename T>
bool myStack<T>::empty()
{
    return tos == NULL ;

}

template<typename T>
bool myStack<T>::full()
{

   return mySize >= myCapacity;

}



template<typename T>
void myStack<T>::clear()
{
    nukem();

}


template<typename T>
T myStack<T>::peek()
{
    if(empty())
        throw STACK_EMPTY;

    return tos->data;

}



template<typename T>
void myStack<T>::pop()
{
    if(empty())
         throw STACK_EMPTY;

    //create a temp
    //set to to tos
    //set tos down by 1 element
    //delete temp
    node<T> *temp = tos;
    tos = tos->next;
    //decrease the size to 1 when pop
    mySize -= 1;
    delete temp;
    temp = NULL;
}

template<typename T>
void myStack<T>::push(const T &val)
{
    if(full())
        throw STACK_FULL;
    //increase size by 1 when push
    mySize += 1;

    //create a newNode with val
    //make it points to tos
    //set tos = newNode so tos is always points to the top element
    node<T> *newNode;

    newNode = new node<T>(val);
    newNode->next = tos;
    tos = newNode;
}

template<typename T>
void myStack<T>::copy(const myStack &other)
{

    if(other.tos)
    {
        mySize = other.mySize;
        myCapacity = other.myCapacity;

        node<T> *newNode, *next;
        //tos poins to newNode (copy the first element from other)
        tos = new node<T> (other.tos->data);
        //get newNode to tos, use newNode to iterate
        newNode = tos;
        next = other.tos->next;
        while(next)
        {
            newNode->next = new node<T> (next->data);
            newNode = newNode->next;
            next = next->next;
        }

        delete next;
        next = NULL;
    }

}


template<typename T>
void myStack<T>::nukem()
{
    while(tos)
    {
        pop();
    }
    tos = NULL;
}

//template<typename T>
//void myStack<T>::display()
//{
//    node<T> *temp;
//    temp = tos;
//    while(temp)
//    {
//        std::cout<< temp->data <<std::endl;
//        temp = temp->next;
//    }
//}

template<typename T>
void myStack<T>::printReverse()
{
    printReverse(tos); //kickstart the overload function below
//    std::cout<< "size: " << mySize << std::endl;
}

template<typename T>
void myStack<T>::printReverse(node<T> *n)
{
    if(n == NULL)
        return;
    printReverse(n->next);   //print the next
    std::cout << n->data << std::endl; //before printing me
}





#endif // MYSTACK_H
