#ifndef BST_H
#define BST_H
#include <cstdlib>
#include <iostream>
using namespace std;

template<class T>
class TreeNode{
public:
  TreeNode();
  TreeNode(T k);
  virtual ~TreeNode();

  T key;
  TreeNode<T>* left;
  TreeNode<T>* right;
};

template<class T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
}

template<class T>
TreeNode<T>::TreeNode(T k){
  left = NULL;
  right = NULL;
  key = k;
};

template<class T>
TreeNode<T>::~TreeNode(){

}

template<class T>
class BST{
private:
  TreeNode<T>* root;

public:
  BST();
  virtual ~BST();

  void insert(T value);
  bool contains(T value);
  T find(T value);
  bool removeNode(T k);
  bool isEmpty();

  T getMin();
  T getMax();

  TreeNode<T>* getSuccessor(TreeNode<T>* d);

  void recPrint(TreeNode<T>* node);
  void printTree();
};

template<class T>
BST<T>::BST(){
  root = NULL;
}

template<class T>
BST<T>::~BST(){

}

template<class T>
void BST<T>::recPrint(TreeNode<T>* node){
  if(node == NULL)
  {
    return;
  }
  recPrint(node->left);
  cout << node->key << endl;
  recPrint(node->right);
}

template<class T>
void BST<T>::printTree()
{
  recPrint(root);
}

template<class T>
T BST<T>::getMin(){
  if(isEmpty())
  {
    return 0;
  }
  TreeNode<T>* current = root;

  while(current->left != NULL){
    current = current->left;
  }

  return current->key;
}

template<class T>
T BST<T>::getMax(){
  if(isEmpty())
  {
    return 0;
  }

  TreeNode<T>* current = root;

  while(current->right != NULL){
    current = current->right;
  }

  return current->key;
}

template<class T>
void BST<T>::insert(T value){
  TreeNode<T>* node = new TreeNode<T>(value);

  if (isEmpty()){
    root = node;
  }
  else{
    TreeNode<T>* current = root;
    TreeNode<T>* parent = NULL;

    while(true){
      parent = current;

      if(value < current->key){
        current = current->left;

        if(current == NULL){
          parent->left = node;
          break;
        }
      }
      else{
        current = current->right;
        if(current == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}

template<class T>
bool BST<T>::contains(T value){
  if (isEmpty())
  {
    return false;
  }
  else{
    TreeNode<T>* current = root;

    while(current->key != value){
      if (value < current->key)
      {
        current = current->left;
      }
      else{
        current = current->right;
      }
      if(current == NULL){
        return false;
      }
    }
  }
  return true;
}

template<class T>
T BST<T>::find(T value){
  if (isEmpty())
  {
    return value;
  }
  else{
    TreeNode<T>* current = root;

    while(current->key != value){
      if (value < current->key)
      {
        current = current->left;
      }
      else{
        current = current->right;
      }
      if(current == NULL){
        return value;
      }
    }
    value = current->key;
  }
  return value;
}

template<class T>
bool BST<T>::removeNode(T k)
{
  if (isEmpty())
  {
    return false;
  }

  TreeNode<T>* parent = NULL;
  TreeNode<T>* current = root;
  bool isLeftNode = true;

  while(current->key != k)
  {
    parent = current;

    if(k < current->key)
    {
      isLeftNode = true;
      current = current->left;
    }
    else
    {
      isLeftNode = false;
      current = current->right;
    }

    if(current == NULL)
    {
      return false;
    }
  }
//No children
  if(current->left == NULL && current->right == NULL)
  {
    if(current == root)
    {
      delete root;
      root = NULL;
    }
    else if(isLeftNode)
    {
      parent->left = NULL;
      delete current;
    }
    else
    {
      parent->right = NULL;
      delete current;
    }
  }
  //One child, left child
  else if (current->right == NULL)
  {
    if(current == root)
    {
      root = current->left;
      delete current;
    }
    else if (isLeftNode)
    {
      parent->left = current->left;
      delete current;
    }
    else
    {
      parent->right = current->left;
      delete current;
    }
  }
  //One child, right child
  else if(current->left == NULL)
  {
    if (current == root)
    {
      root = current->right;
      delete current;
    }
    else if (isLeftNode)
    {
      parent->left = current->right;
      delete current;
    }
    else
    {
      parent->right = current->right;
      delete current;
    }
  }
  //Two children
  else
  {
    TreeNode<T>* successor = getSuccessor(current);

    if(current == root)
    {
      root = successor;
    }
    else if(isLeftNode)
    {
      TreeNode<T>* temp = parent;
      parent->left = successor;
    }
    else
    {
      parent->right = successor;
    }
    successor->left = current->left;
    delete current;
  }
  return true;
}

template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* d)
{
  TreeNode<T>* sp = d;
  TreeNode<T>* successor = d;
  TreeNode<T>* current = d->right;

  while(current != NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor != d->right)
  {
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

template<class T>
bool BST<T>::isEmpty(){
  return (root == NULL);
}

#endif
