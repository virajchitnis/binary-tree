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
    if (opt == "exit" || opt == "E" || opt == "e") {
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
      else if (opt == "S") {
        cout << "Searching for (" << input << ")..." << endl;
        BinaryTree rt = *bt.search(input);
        cout << rt;
        cout << "Found " << rt.size() << " entries." << endl;
      }
      else {
        cout << "Invalid input" << endl;
      }
      cout << "binary-tree> ";
    }
  }

  return 0;
}
