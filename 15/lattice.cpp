/*
 * Project Euler
 * Problem 15
 *
 * How many routes are there through a 20x20 grid?
 *
 */

#include <iostream>
#include <vector>
#include "../utility.h"
using namespace std;

#define MAX_DEPTH 20

BigUint branch(BigUint right_depth, BigUint down_depth);

int main() {

  cout << branch(0, 0) << endl;

  return 0;
}

BigUint branch(BigUint right_depth, BigUint down_depth) {
  BigUint count = 0;
  if (right_depth < MAX_DEPTH) count += branch(right_depth+1, down_depth);
  if (down_depth < MAX_DEPTH) count += branch(right_depth, down_depth+1);
  if (right_depth == MAX_DEPTH && down_depth == MAX_DEPTH) return 1;

  return count;
}
