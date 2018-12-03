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
  Node *_first_node;
public:
  BinaryTree();
  BinaryTree(Node *fnode) : _first_node(fnode) {}

  Node* first_node() const { return _first_node; }

  void set_first_node(Node *n) { _first_node = n; }

  bool has_first_node() { if(_first_node != 0) return true; return false; }

  friend ostream& operator<<(ostream& os, const BinaryTree& n);
};
#endif
