/* Author: Viraj R Chitnis
 * Date: 03/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <iostream>
#include "Node.h"
#include "BinaryTree.h"

using namespace std;

int main() {
  Node *a = new Node("Viraj");
  Node *b = new Node("Chitnis");
  Node *c = new Node("Viraj");
  cout << *a << endl;
  cout << *b << endl;

  if (*a < *b) {
    cout << "a < b" << endl;
  }
  else if (*b < *a) {
    cout << "b < a" << endl;
  }

  if (*a > *b) {
    cout << "a > b" << endl;
  }
  else if (*b > *a) {
    cout << "b > a" << endl;
  }

  if (*a == *b) {
    cout << "a == b" << endl;
  }
  else {
    cout << "a != b" << endl;
  }

  if (*a == *c) {
    cout << "a == c" << endl;
  }
  else {
    cout << "a != c" << endl;
  }

  BinaryTree bt;
  bt.insert(a);
  bt.insert(b);
  bt.insert(new Node("Person"));
  bt.insert(new Node("Blah"));
  bt.insert(new Node("Wow"));
  bt.insert(new Node("Irate"));
  cout << bt;
  cout << "Size: " << bt.size() << endl;
  cout << "Contains (Blah): " << bt.lookup("Blah") << endl;
  cout << "Contains (Test): " << bt.lookup("Test") << endl;
  cout << "Contains (Irate): " << bt.lookup("Irate") << endl;

  BinaryTree rt = *bt.search("ir");
  cout << "Search (ir):" << endl;
  cout << rt;
  // cout << bt.insert(b);
  // cout << bt.insert(c);

  return 0;
}
