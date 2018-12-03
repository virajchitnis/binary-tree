#include <string>

using namespace std;

#ifndef NODE
#define NODE
class Node {
private:
  string _value;
  Node *_left_child;
  Node *_right_child;
public:
  Node(string value) : _value(value) {}

  string value() const { return _value; }
  Node* left_child() const { return _left_child; }
  Node* right_child() const { return _right_child; }

  void set_left_child(Node *lchild) { _left_child = lchild; }
  void set_right_child(Node *rchild) { _right_child = rchild; }

  bool has_left_child() { if(_left_child != 0) return true; return false; }
  bool has_right_child() { if(_right_child != 0) return true; return false; }

  friend ostream& operator<<(ostream& os, const Node& n);

  bool operator==(const Node& p) const;
  bool operator<(const Node& p) const;
  bool operator>(const Node& p) const;
};
#endif
