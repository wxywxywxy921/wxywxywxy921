class Solution {
  /** 
   * param A : an integer sorted array
   * param target :  an integer to be inserted
   * return : an integer
   */
public:
  int searchInsert(vector<int> &A, int target) {
    // write your code here
        
    int begin, end;
    int tar_idx = 0;
        
    end = A.size() - 1;
        
    if(A.size())
    {
      do_work(A, target, begin, end, tar_idx);
    }
        
    return tar_idx;
  }
    
  void do_work(vector<int> &A, int target, int begin, int end, int &tar_idx)
  {
    int mid;
        
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
            
      if(target < A[mid])
      {
        do_work(A, target, begin, mid, tar_idx);
      }
      else if(target > A[mid])
      {
        do_work(A, target, mid, end, tar_idx);
      }
      else
      {
        tar_idx = mid;
        return;
      }
    }
    else
    {
      if(target <= A[begin])
      {
        tar_idx = begin;
      }
      else if(target > A[end])
      {
        tar_idx = end + 1;
      }
      else
      {
        tar_idx = end;
      }
      return;
    }
  }
};
