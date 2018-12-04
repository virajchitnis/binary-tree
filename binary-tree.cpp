/* Author: Viraj R Chitnis
 * Date: 03/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <iostream>
#include "Node.h"
#include "BinaryTree.h"

using namespace std;

int main(int argc, char** argv) {
  string file_name;
  if (argc <= 1) {
    cout << "Enter file name> ";
    cin >> file_name;
  }
  else {
    file_name = argv[1];
  }

  BinaryTree bt;
  bt.read_file(file_name);
  cout << "Size: " << bt.size() << endl;

  string opt, input;
  cout << "binary-tree> ";
  while (cin >> opt) {
    if (opt == "exit" || opt == "E" || opt == "e") {
      return 0;
    }
    else if (opt == "M" || opt == "m") {
      cout << "Searching for smallest entry..." << endl;
      Node *mn = bt.find_minimum_value(bt.first_node());
      cout << "Smallest entry: " << *mn << endl;
    }
    else {
      cin >> input;
      if (opt == "Q" || opt == "q") {
        cout << "Lookup (" << input << "): " << bt.lookup(input) << endl;
      }
      else if (opt == "A" || opt == "a") {
        Node *n = bt.insert(new Node(input));
        cout << *n << endl;
      }
      else if (opt == "S" || opt == "s") {
        cout << "Searching for (" << input << ")..." << endl;
        BinaryTree rt = *bt.search(input);
        cout << rt;
        cout << "Found " << rt.size() << " entries." << endl;
      }
      else {
        cout << "Invalid input" << endl;
      }
    }
    cout << "binary-tree> ";
  }

  return 0;
}
