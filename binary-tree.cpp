/* Author: Viraj R Chitnis
 * Date: 03/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <iostream>
#include <fstream>
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
  string file_name = "./test_files/best15.txt";
  bt.read_file(file_name);
  cout << bt;
  cout << "Size: " << bt.size() << endl;

  cout << "Contains (Blah): " << bt.lookup("Blah") << endl;
  cout << "Contains (Test): " << bt.lookup("dragon") << endl;
  cout << "Contains (Irate): " << bt.lookup("Irate") << endl;

  BinaryTree rt = *bt.search("ag");
  cout << "Search (ag):" << endl;
  cout << rt;

  rt = *bt.search("a");
  cout << "Search (a):" << endl;
  cout << rt;

  rt = *bt.search("e");
  cout << "Search (e):" << endl;
  cout << rt;

  return 0;
}
