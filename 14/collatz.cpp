/*
 * Project Euler
 * Problem 14
 *
 * Which number, starting under 1,000,000, produces the longest
 * Collatz sequence?
 *
 */

#include <iostream>
#include <vector>
using namespace std;

unsigned int next_collatz(unsigned int num);

int main() {
  
  unsigned int long_chain = 0, long_num = 0;
  vector<int> collatz;

  /*
   * For every number less than or equal to 1,000,000, calculate the number
   * in the collatz sequence. If the number is higher than the last highest
   * calculated, replace it.
   */
  for (unsigned int i = 2; i <= 1000000; i++) {
    collatz.clear();
    int next = i;
    collatz.push_back(next);
    while (next != 1) {
      next = next_collatz(next);
      collatz.push_back(next);
    }

    if (collatz.size() > long_chain) {
      long_chain = collatz.size();
      long_num = i;
    }
  }

  cout << long_num << endl;
  return 0;
}

unsigned int next_collatz(unsigned int num) {
  if (num % 2 == 0) return num / 2;
  else return 3*num+1;
}
