/* Author: Viraj R Chitnis
 * Date: 03/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include "BinaryTree.h"

BinaryTree::BinaryTree() {
  // Do nothing.
}

Node* BinaryTree::recursive_insert(Node *new_node, Node *curr_node) {
  if (*new_node < *curr_node) {
    if (curr_node->has_left_child()) {
      return recursive_insert(new_node, curr_node->left_child());
    }
    else {
      curr_node->set_left_child(new_node);
      _size++;
      return new_node;
    }
  }
  else if (*new_node > *curr_node) {
    if (curr_node->has_right_child()) {
      return recursive_insert(new_node, curr_node->right_child());
    }
    else {
      curr_node->set_right_child(new_node);
      _size++;
      return new_node;
    }
  }
  return curr_node;
}

ostream& BinaryTree::recursive_print(ostream& os, Node *curr_node) const {
  os << "[" << *curr_node << "]" << endl;
  if (curr_node->has_left_child()) {
    recursive_print(os, curr_node->left_child());
  }
  if (curr_node->has_right_child()) {
    recursive_print(os, curr_node->right_child());
  }
  return os;
}

Node* BinaryTree::insert(Node *new_node) {
  if (_first_node == 0) {
    _first_node = new_node;
    _size++;
    return _first_node;
  }
  return recursive_insert(new_node, _first_node);
}

bool BinaryTree::recursive_lookup(Node *curr_node, Node *target) {
  if (*curr_node == *target) {
    return true;
  }
  else if (*target < *curr_node && curr_node->has_left_child()) {
    return recursive_lookup(curr_node->left_child(), target);
  }
  else if (*target > *curr_node && curr_node->has_right_child()) {
    return recursive_lookup(curr_node->right_child(), target);
  }
  return false;
}

bool BinaryTree::lookup(string target) {
  if (_first_node == 0) {
    return false;
  }
  Node *n = new Node(target);
  return recursive_lookup(_first_node, n);
}

void BinaryTree::recursive_search(Node *curr_node, string *query, BinaryTree *bt) {
  string v = curr_node->value();
  transform(v.begin(), v.end(), v.begin(), ::tolower);
  if (v.find(*query) != string::npos) {
    bt->insert(new Node(curr_node->value()));
  }
  if (curr_node->has_left_child()) {
    recursive_search(curr_node->left_child(), query, bt);
  }
  if (curr_node->has_right_child()) {
    recursive_search(curr_node->right_child(), query, bt);
  }
}

BinaryTree* BinaryTree::search(string query) {
  if (_first_node == 0) {
    return 0;
  }
  transform(query.begin(), query.end(), query.begin(), ::tolower);
  BinaryTree *bt = new BinaryTree();
  recursive_search(_first_node, &query, bt);
  return bt;
}

// Overload the << operator
ostream& operator<<(ostream& os, const BinaryTree& n) {
  return n.recursive_print(os, n.first_node());
}
