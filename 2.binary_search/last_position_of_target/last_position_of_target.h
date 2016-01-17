class Solution {
public:
  /**
   * @param A an integer array sorted in ascending order
   * @param target an integer
   * @return an integer
   */
  int lastPosition(vector<int>& A, int target) {
    // Write your code here
        
    int begin, end, tar_idx;
        
    begin = 0;
    end = A.size() -1;
    tar_idx = -1;
        
    if(A.size())
    {
      do_work(A, begin, end, target, tar_idx);
    }
        
    return tar_idx;
  }
    
  void do_work(vector<int> &A, int begin, int end, int target, int &tar_idx)
  {
    int mid;
        
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
            
      if(A[mid] > target)
      {
        do_work(A, begin, mid, target, tar_idx);
      }
      else if(A[mid] < target)
      {
        do_work(A, mid, end, target, tar_idx);
      }
      else
      {
        if(mid > tar_idx)
        {
          tar_idx = mid;
        }
                
        do_work(A, mid, end, target, tar_idx);
      }
    }
    else
    {
      if(A[begin] == target && begin > tar_idx)
      {
        tar_idx = begin;
      }
      else if(A[end] == target && end > tar_idx)
      {
        tar_idx = end;
      }
            
      return;
    }
  }
};
