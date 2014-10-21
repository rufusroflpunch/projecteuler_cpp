/*
 * Project Euler
 * Problem 6
 *
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int sum = 0, square = 0;

  for (int i = 1; i < 101; i++) {
    sum += pow(i,2);
    square += i;
  }

  square = pow(square, 2);

  cout << square - sum << endl;

  return 0;
}
