/* Author: Viraj R Chitnis
 * Date: 02/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <iostream>
#include <fstream>
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
  bool recursive_lookup(Node *curr_node, Node *target);
  void recursive_search(Node *curr_node, string *query, BinaryTree *bt);
public:
  BinaryTree();
  BinaryTree(Node *fnode) : _first_node(fnode) { _size++; }

  Node* insert(Node *new_node);
  void remove(string target);
  bool lookup(string target);
  BinaryTree* search(string query);
  int size() const { return _size; }

  Node* find_minimum_value(Node *curr_node);
  Node* find_maximum_value(Node *curr_node);

  void read_file(string file_name);

  Node* first_node() const { return _first_node; }

  bool has_first_node() const { if(_first_node != 0) return true; return false; }

  friend ostream& operator<<(ostream& os, const BinaryTree& n);

  // Destructor
  ~BinaryTree();
};
#endif
