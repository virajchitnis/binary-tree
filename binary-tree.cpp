#include <iostream>
#include "Node.h"

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

  return 0;
}
