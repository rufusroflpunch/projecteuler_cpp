/*
 * Project Euler
 * Problem 1
 *
 * Find the sum of all multiples of 3 and 5 below 100.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

  vector<int> nlist;

  for (int i = 1; i < 1000; i++) nlist.push_back(i); // Fill the list

  nlist.erase(remove_if(begin(nlist), end(nlist),
        [] (int i) { return (i % 3 != 0) && (i % 5 != 0);}),
      end(nlist));


  int sum = 0;

  for (int i : nlist) sum += i;

  cout << sum << endl;

  return 0;
}
