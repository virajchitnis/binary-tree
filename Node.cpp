#include "Node.h"

// Overload the << operator
ostream& operator<<(ostream& os, const Node& n) {
  return os << n.value();
}
