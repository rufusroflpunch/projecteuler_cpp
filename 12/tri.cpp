/*
 * Project Euler
 * Problem 12
 *
 * What is the value of the first triangle number to have over five hundred divisors?
 */

#include <iostream>
#include "../utility.h"
using namespace std;

int fac_count(BigUint num);

int main() {

  int count = 1;
  BigUint tri = 1;
  
  while (true) {
    tri = ++count + tri;
    // cout << tri << ": " << fac_count(tri) << endl;
    int temp = fac_count(tri);
    // cout << temp << " ";
    if (temp > 499) break;
  }

  cout << tri << endl;
  return 0;
}

int fac_count(BigUint num) {
  int count = 0, fac = num / 2;

  while (fac > 0)
    if (num % fac == 0) { count++; fac--; }
    else fac--;

  return count;
}
