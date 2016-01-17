#include "first_position_of_target.h"

int main()
{
  Solution solution;
  vector<int> input;
  int target = 8;

  input.push_back(3);
  input.push_back(4);
  input.push_back(5);
  input.push_back(8);
  input.push_back(8);
  input.push_back(8);
  input.push_back(8);
  input.push_back(10);
  input.push_back(13);
  input.push_back(14);

  solution.binarySearch(input, target);

  return 0;
}
