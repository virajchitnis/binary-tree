/* Author: Viraj R Chitnis
 * Date: 03/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <iostream>
#include "Node.h"
#include "BinaryTree.h"

using namespace std;

int main() {
  cout << "Enter file name > ";
  string file_name;
  cin >> file_name;
  BinaryTree bt;
  bt.read_file(file_name);
  cout << "Size: " << bt.size() << endl;

  string opt, input;
  cout << "binary-tree> ";
  while (cin >> opt) {
    if (opt == "0") {
      return 0;
    }
    else {
      cin >> input;
      if (opt == "Q") {
        cout << "Lookup (" << input << "): " << bt.lookup(input) << endl;
      }
      else if (opt == "A") {
        Node *n = bt.insert(new Node(input));
        cout << *n << endl;
      }
      else {
        cout << "Invalid input" << endl;
      }
      cout << "binary-tree> ";
    }
  }

  // cout << "Contains (Blah): " << bt.lookup("Blah") << endl;
  // cout << "Contains (dragon): " << bt.lookup("dragon") << endl;
  // cout << "Contains (Irate): " << bt.lookup("Irate") << endl;
  //
  // BinaryTree rt = *bt.search("ag");
  // cout << "Search (ag):" << endl;
  // cout << rt;
  //
  // rt = *bt.search("a");
  // cout << "Search (a):" << endl;
  // cout << rt;
  //
  // rt = *bt.search("e");
  // cout << "Search (e):" << endl;
  // cout << rt;

  return 0;
}
