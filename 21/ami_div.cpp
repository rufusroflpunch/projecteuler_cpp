/*
 * Project Euler
 * Problem 21
 *
 * Find the sum of all amicable numbers under 10000.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int main() {

  auto sums = vector<int64_t>{0},
       amis = vector<int64_t>{};

  for (int64_t i = 1; i < 10000; i++) {
    int acc{0};
    for (int64_t j = 1; j < i; j++)
      if (i % j == 0) acc += j;
    sums.push_back(acc);
  }

  for (int64_t i = 1; i < 10000; i++) {
    int64_t i1{i}, i2{sums[i1]};
    if (i1 > 10000 || i2 > 10000) continue; // Prevent segfault
    if (i1 == sums[i2] && i1 != i2) { 
      amis.push_back(i1);
      amis.push_back(i2);
    }
  }

  // Divide by two because the algorithm finds each pair twice
  cout << accumulate(begin(amis), end(amis), 0) / 2 << endl;
  return 0;
}
