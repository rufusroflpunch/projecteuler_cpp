/*
 * Project Euler
 * Problem 2
 *
 * Find the sum of all even Fibonacci numbers which do not exceed four million.
 */

#include <algorithm>
#include <iostream>

using namespace std;

int main() {

  int sum = 0, fib = 0;
  vector<int> fibs{ 1, 2 };

  while (fib <= 4000000) {
    fib = fibs[fibs.size() - 1] + fibs[fibs.size() - 2];
    fibs.push_back(fib);
  }

  fibs.pop_back(); // The last element will be greater than four million, drop it

  fibs.erase(remove_if(begin(fibs),
                        end(fibs),
                        [] (int i) { return i % 2 != 0; }),
            end(fibs));

  for (auto &i : fibs) sum += i;

  cout << sum << endl;

  return 0;
}
