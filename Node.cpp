#include "Node.h"

// Overload the << operator
ostream& operator<<(ostream& os, const Node& n) {
  return os << n.value();
}

// Overload the == operator
bool Node::operator==(const Node& p) const {
  string v1 = _value;
  string v2 = p.value();
  if (v1 == v2) {
    return true;
  }
  return false;
}

// Overload the < operator
bool Node::operator<(const Node& p) const {
  string v1 = _value;
  string v2 = p.value();
  if (v1 < v2) {
    return true;
  }
  return false;
}

// Overload the > operator
bool Node::operator>(const Node& p) const {
  string v1 = _value;
  string v2 = p.value();
  if (v1 > v2) {
    return true;
  }
  return false;
}
