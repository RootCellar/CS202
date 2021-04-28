#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::cout;
using std::endl;

using std::vector;
using std::list;
using std::copy;


list<int> doubleCopy(vector<int> toCopy) {
  list<int> toRet;
  toRet.resize(toCopy.size() * 2);

  auto i = copy(toCopy.begin(), toCopy.end(), toRet.begin());

  copy(toCopy.begin(), toCopy.end(), i);

  return toRet;
}

int main() {
  vector<int> toCopy{1,2,3};

  list<int> ret = doubleCopy(toCopy);

  for(auto i = ret.begin(); i != ret.end(); i++) {
    cout << (*i);
  }
}
