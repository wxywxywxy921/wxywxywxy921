#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
  /**
   * @param nums: The integer array.
   * @param target: Target number to find.
   * @return: The first position of target. Position starts from 0. 
   */
  int binarySearch(vector<int> &array, int target) {
    // write your code here
        
    int begin = 0;
    int end = array.size() - 1;
    int ret = 65535;
        
    if(end >= 0)
    {
      do_work(array, begin, end, target, ret);
    }
        
    if(ret == 65535)
    {
      ret = -1;
    }
        
    printf("ret=%d\n", ret);

    return ret;
  }
    
  void do_work(vector<int> &array,
               int &begin, 
               int &end,
               int &target,
               int &ret)
  {
    int mid;
                    
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
                        
      if(array[mid] > target)
      {
        do_work(array, begin, mid, target, ret);
      }
      else if(array[mid] < target)
      {
        do_work(array, mid, end, target, ret);
      }
      else
      {
        if(mid < ret)
        {
          ret = mid;
        }
        do_work(array, begin, mid, target, ret);
      }
    }
    else
    {
      if(array[begin] == target
         && begin < ret)
      {
        ret = begin;
      }
      else if(array[end] == target
              && end < ret)
      {
        ret = end;
      }
                        
      return;
    }
  }
};
