/* Author: Viraj R Chitnis
 * Date: 02/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

#ifndef BINARYTREE
#define BINARYTREE
class BinaryTree {
private:
  Node *_first_node = 0;
  int _size = 0;
  Node* recursive_insert(Node *new_node, Node *curr_node);
  ostream& recursive_print(ostream& os, Node *curr_node) const;
public:
  BinaryTree();
  BinaryTree(Node *fnode) : _first_node(fnode) { _size++; }

  Node* insert(Node *new_node);
  int size() const { return _size; }

  Node* first_node() const { return _first_node; }

  bool has_first_node() { if(_first_node != 0) return true; return false; }

  friend ostream& operator<<(ostream& os, const BinaryTree& n);
};
#endif
