#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>

using namespace std;

template <typename T>
class Node{
public:
  Node(T setData);
  ~Node();
  Node *next;
  Node *prev;
  T data;
};

template <typename T>
Node<T>::Node(T setData)
{
  next = nullptr;
  prev = nullptr;
  data = setData;
}

template <typename T>
Node<T>::~Node()
{
  next = nullptr;
  prev = nullptr;
}

template <typename T>
class GenStack{
public:
  GenStack();
  ~GenStack();
  void push(T addData); //add to top
  T pop(); //remove from top
  T peek(); //return top without removing
  int size();
  bool isEmpty();

private:
  Node<T> *head;
  Node<T> *tail;
  int count; //number of items currently in stack
};

template <typename T>
GenStack<T>::GenStack(){
  head = nullptr;
  tail = nullptr;
  count = 0;
}

template <typename T>
GenStack<T>::~GenStack(){
  while (head != nullptr)
  {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
  }
}

template <typename T>
void GenStack<T>::push(T addData){
  Node<T> *temp = new Node<T>(addData);
  if (isEmpty())
  {
    tail = temp;
  }
  else
  {
    //not an empty list
    temp->next = head;
    head->prev = temp;
  }
  head = temp;
  count++;
}


template <typename T>
T GenStack<T>::pop()
{
  T result;
  try
  {
    if (isEmpty())
    {
      throw runtime_error("Stack is empty.");
    }
    if(head->next == nullptr)
    {
      tail == nullptr;
    }
    else
    {
      head->next->prev = nullptr;
    }
    Node<T> *temp = head;
    head = head->next;
    result = temp->data;
    count--;

  }
  catch (runtime_error& excpt)
  {
    cout << excpt.what() << endl;
  }
  return result;
}

template <typename T>
T GenStack<T>::peek(){
  return head->data;
}

template <typename T>
int GenStack<T>::size(){
  return count;
}

template <typename T>
bool GenStack<T>::isEmpty(){
  return (count==0);
}

#endif
