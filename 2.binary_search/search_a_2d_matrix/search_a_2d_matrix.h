#include <vector>
#include <algorithm>
#include <stdio.h>

#define FALSE 0
#define TRUE 1

using namespace std;

class Solution {
public:
  /**
   * @param matrix, a list of lists of integers
   * @param target, an integer
   * @return a boolean, indicate whether matrix contains target
   */
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    // write your code here
        
    int ret = FALSE;
    int begin = 0;
    int end = 0;
        
    if(matrix.size())
    {
      end = matrix.size() * matrix.front().size() - 1;
    }
        
    if(end)
    {
      do_work(matrix, target, begin, end, ret);
    }
        
    return ret;
  }
    
  void do_work(vector<vector<int> > &matrix, 
               int target,
               int begin,
               int end, 
               int &ret)
  {
    int mid;
    int mid_x, mid_y;
    int end_x, end_y;
    int begin_x, begin_y;
                    
    mid = (begin + end) >> 1;
                    
    {
      // translate the address
      mid_x = mid % matrix.front().size();
      mid_y = mid / matrix.front().size();
      begin_x = begin % matrix.front().size();
      begin_y = begin / matrix.front().size();
      end_x = end % matrix.front().size();
      end_y = end / matrix.front().size();
    }
                    
    if(begin + 1 < end)
    {
      printf("mid=%d\n", matrix.at(mid_y).at(mid_x));
      if(matrix.at(mid_y).at(mid_x) > target)
      {
        do_work(matrix, target, begin, mid, ret);
      }
      else if(matrix.at(mid_y).at(mid_x) < target)
      {
        do_work(matrix, target, mid, end, ret);
      }
      else
      {
        ret = TRUE;
        return;
      }
    }
    else
    {
      if(target == matrix.at(begin_y).at(begin_x)
         || target == matrix.at(end_y).at(end_x))
      {
        ret = TRUE;
      }
                        
      return;
    }
  }
};
