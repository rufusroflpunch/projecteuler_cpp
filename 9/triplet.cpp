/*
 * Project Euler
 * Problem 9
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {

  for (int c = 0; c <= 1000; c++) {
    for (int b = 0; b <= 1000; b++) {
      for (int a = 0; a <= 1000; a++) {
        // a > b > c
        if (a > b || a > c) break;
        if (b > c) break;
        
        // a^2 + b^2 == c^2
        // and a+b+c == 1000
        if (
            ( pow(a,2) + pow(b,2) == pow(c,2) )
            && ( a + b + c == 1000 )
           )
          cout << a*b*c << endl; // Output final result
      }
    }
  }


  return 0;
}
