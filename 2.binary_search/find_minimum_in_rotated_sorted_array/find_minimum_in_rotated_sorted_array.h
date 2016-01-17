class Solution {
public:
  /**
   * @param num: a rotated sorted array
   * @return: the minimum number in the array
   */
  int findMin(vector<int> &num) {
    // write your code here
        
    int begin, end, ret;
        
    begin = 0;
    end = num.size() - 1;
    ret = 0x7fffffff;
        
    if(num.size())
    {
      do_work(num, begin, end, ret);
    }
    else
    {
      ret = -1;
    }
        
    return ret;
  }
    
  void do_work(vector<int> &num,
               int &begin,
               int &end,
               int &ret)
  {
    int mid;
                    
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
                        
      if(num[begin] < num[mid])
      {
        if(num[end] < num[begin])
        {
          do_work(num, mid, end, ret);
        }
        else
        {
          do_work(num, begin, mid, ret);
        }
      }
      else
      {
        do_work(num, begin, mid, ret);
      }
    }
    else
    {
      if (num[begin] < num[end])
      {
        ret = num[begin];
      }
      else
      {
        ret = num[end];
      }
                        
      return;
    }
  }
};
