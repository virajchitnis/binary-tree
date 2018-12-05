/* Author: Viraj R Chitnis
 * Date: 03/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include "BinaryTree.h"

BinaryTree::BinaryTree() {
  // Do nothing.
}

void BinaryTree::recursive_remove(Node *curr_node, Node *target) {
  if (curr_node->has_left_child()) {
    Node *test_left = curr_node->left_child();
    if (*test_left == *target) {
      if (!test_left->has_left_child() && !test_left->has_right_child()) {
        curr_node->set_left_child(0);
      }
      else if (test_left->has_left_child() && !test_left->has_right_child()) {
        curr_node->set_left_child(test_left->left_child());
      }
      else if (test_left->has_right_child() && !test_left->has_left_child()) {
        curr_node->set_left_child(test_left->right_child());
      }
      else {
        Node *min = find_minimum_value(test_left->right_child());
        min->set_left_child(test_left->left_child());
        curr_node->set_left_child(min);
      }
      _size--;
      return;
    }
    else if (*target < *curr_node) {
      return recursive_remove(curr_node->left_child(), target);
    }
  }
  if (curr_node->has_right_child()) {
    Node *test_right = curr_node->right_child();
    if (*test_right == *target) {
      if (!test_right->has_left_child() && !test_right->has_right_child()) {
        curr_node->set_right_child(0);
      }
      else if (test_right->has_left_child() && !test_right->has_right_child()) {
        curr_node->set_right_child(test_right->left_child());
      }
      else if (test_right->has_right_child() && !test_right->has_left_child()) {
        curr_node->set_right_child(test_right->right_child());
      }
      else {
        Node *min = find_minimum_value(test_right->right_child());
        min->set_left_child(test_right->left_child());
        curr_node->set_right_child(min);
      }
      _size--;
      return;
    }
    else if (*target > *curr_node) {
      return recursive_remove(curr_node->right_child(), target);
    }
  }
}

void BinaryTree::remove(string target) {
  Node *n = new Node(target);
  if (_first_node == 0) {
    return;
  }
  if (*_first_node == *n) {
    if (!_first_node->has_left_child() && !_first_node->has_right_child()) {
      _first_node = 0;
    }
    else if (_first_node->has_left_child() && !_first_node->has_right_child()) {
      _first_node = _first_node->left_child();
    }
    else if (_first_node->has_right_child() && !_first_node->has_left_child()) {
      _first_node = _first_node->right_child();
    }
    else {
      Node *min = find_minimum_value(_first_node->right_child());
      min->set_left_child(_first_node->left_child());
      _first_node = min;
    }
    _size--;
    return;
  }
  return recursive_remove(_first_node, n);
}

Node* BinaryTree::find_minimum_value(Node *curr_node) {
  if (curr_node->has_left_child()) {
    return find_minimum_value(curr_node->left_child());
  }
  return curr_node;
}

Node* BinaryTree::find_maximum_value(Node *curr_node) {
  if (curr_node->has_right_child()) {
    return find_maximum_value(curr_node->right_child());
  }
  return curr_node;
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

void BinaryTree::read_file(string file_name) {
  cout << "Reading from file..." << endl;
  ifstream infile(file_name);
  string word;
  int word_count = 0;
  while (infile >> word) {
    insert(new Node(word));
    word_count++;
    if ((word_count % 1000000) == 0) {
      cout << word_count/1000000 << " million entries read so far..." << endl;
    }
  }
}

BinaryTree::~BinaryTree() {
  delete _first_node;
}

// Overload the << operator
ostream& operator<<(ostream& os, const BinaryTree& bt) {
  if (!bt.has_first_node()) {
    return os;
  }
  return bt.recursive_print(os, bt.first_node());
}
