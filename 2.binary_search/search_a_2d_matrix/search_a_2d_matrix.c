#include "search_a_2d_matrix.h"

int main()
{
  Solution solution;
  vector<vector<int> >matrix;
  vector<int> tmp;

  tmp.push_back(1);
  tmp.push_back(3);
  tmp.push_back(5);
  tmp.push_back(7);
  matrix.push_back(tmp);
  tmp.clear();

  tmp.push_back(10);
  tmp.push_back(11);
  tmp.push_back(16);
  tmp.push_back(20);
  matrix.push_back(tmp);
  tmp.clear();

  tmp.push_back(23);
  tmp.push_back(30);
  tmp.push_back(34);
  tmp.push_back(50);
  matrix.push_back(tmp);
  tmp.clear();

  printf("ret=%d\n", solution.searchMatrix(matrix, 7));

  return 0;
}
