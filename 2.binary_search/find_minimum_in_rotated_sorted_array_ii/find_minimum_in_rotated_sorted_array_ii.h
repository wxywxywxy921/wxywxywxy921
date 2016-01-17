class Solution {
public:
  /**
   * @param num: the rotated sorted array
   * @return: the minimum number in the array
   */
  int findMin(vector<int> &num) {
    // write your code here
        
    int begin, end, tar_idx;
        
    begin = 0;
    end = num.size() - 1;
    tar_idx = -1;
        
    if(num.size())
    {
      do_work(num, begin, end, tar_idx);
    }
        
    return tar_idx;
  }
    
  void do_work(vector<int> &num, int begin, int end, int &tar_idx)
  {
    int mid;
        
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
            
      if(num[mid] < num[begin])
      {
        do_work(num, begin, mid, tar_idx);
      }
      else if(num[mid] > num[begin])
      {
        if(num[mid] == num[end])
          do_work(num, begin, end - 1, tar_idx);
        else if(num[mid] < num[end])               //[xywu] this is for the un-rotated case
          do_work(num, begin, mid, tar_idx);
        else
          do_work(num, mid, end, tar_idx);
      }
      else
      {
        do_work(num, begin + 1, end, tar_idx);
      }
    }
    else
    {
      if(num[begin] <= num[end])
      {
        tar_idx = num[begin];
      }
      else
      {
        tar_idx = num[end];
      }
            
      return;
    }
  }
};
