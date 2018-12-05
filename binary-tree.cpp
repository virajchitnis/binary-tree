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
    else if (opt == "P" || opt == "p") {
      cout << bt;
      cout << "Size: " << bt.size() << endl;
    }
    else if (opt == "MIN" || opt == "min") {
      cout << "Searching for smallest entry..." << endl;
      Node *mn = bt.find_minimum_value(bt.first_node());
      cout << "Smallest entry: " << *mn << endl;
    }
    else if (opt == "MAX" || opt == "max") {
      cout << "Searching for largest entry..." << endl;
      Node *max = bt.find_maximum_value(bt.first_node());
      cout << "Largest entry: " << *max << endl;
    }
    else {
      cin >> input;
      if (opt == "Q" || opt == "q") {
        cout << "Lookup (" << input << "): " << bt.lookup(input) << endl;
      }
      else if (opt == "G" || opt == "g") {
        Node *cg = bt.get(input);
        if (cg != 0) {
          cout << "Get (" << input << "): " << *cg << endl;
        }
        else {
          cout << "No matching entry found." << endl;
        }
      }
      else if (opt == "A" || opt == "a") {
        Node *n = bt.insert(new Node(input));
        cout << *n << endl;
      }
      else if (opt == "D" || opt == "d") {
        cout << "Deleting (" << input << ")..." << endl;
        bt.remove(input);
        cout << "Done!" << endl;
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
