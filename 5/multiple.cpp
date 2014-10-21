/*
 * Project Euler
 * Problem 5
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <iostream>

using namespace std;

int main() {
  int num = 0;
  bool found = false;

  while (found == false) {
    num++;

    for (int i = 1; i <= 20; i++) {
      if (num % i > 0) { found = false; break; }
      else found = true;
    }
  }
  cout << num << endl;

  return 0;
}
