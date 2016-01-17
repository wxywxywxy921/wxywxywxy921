/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
 */
class Solution {
public:
  /**
   * @param n: An integers.
   * @return: An integer which is the first bad version.
   */
  int findFirstBadVersion(int n) {
    // write your code here
        
    int ret = 0;
        
    if(n > 0)
    {
      do_work(1, n, ret);
    }
        
    return ret;
  }
    
  void do_work(int begin, int end, int &ret)
  {
    int mid;
        
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
            
      if(SVNRepo::isBadVersion(mid))
      {
        do_work(begin, mid, ret);
      }
      else
      {
        do_work(mid, end, ret);
      }
    }
    else
    {
      if(SVNRepo::isBadVersion(begin))
      {
        ret = begin;
      }
      else
      {
        ret = end;
      }
      return;
    }
  }
};
