#include <vector>
#include <algorithm>
#include <stdio.h>
#include "subset_ii.h"

int main()
{
  Solution2 solution;

  vector<int> input;
  int i, j;

  input.push_back(5);
  input.push_back(5);
  input.push_back(5);
  input.push_back(5);
  input.push_back(5);

  solution.subsetsWithDup(input);
  return 0;
}
