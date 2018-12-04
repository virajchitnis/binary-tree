/* Author: Viraj R Chitnis
 * Date: 03/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <iostream>
#include "Node.h"
#include "BinaryTree.h"

using namespace std;

int main() {
  BinaryTree bt;
  string file_name = "./test_files/rockyou.txt";
  bt.read_file(file_name);
  // cout << bt;
  cout << "Size: " << bt.size() << endl;

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
