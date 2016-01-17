class Solution {
  /** 
   * param A : an integer ratated sorted array
   * param target :  an integer to be searched
   * return : an integer
   */
public:
  int search(vector<int> &A, int target) {
    // write your code here
        
    int begin, end, tar_idx;
        
    begin = 0;
    end = A.size() - 1;
    tar_idx = -1;
        
    if(A.size())
    {
      do_work(A, begin, end, target, tar_idx);
    }
        
    return tar_idx;
  }
    
  void do_work(vector<int> &A,
               int begin, int end, int target, int &tar_idx)
  {
    int mid;
                    
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
                        
      if(A[mid] == target)
      {
        tar_idx = mid;
        return;
      }
                        
      if(A[begin] == target)
      {
        tar_idx = begin;
        return;
      }
                        
      if(A[end] == target)
      {
        tar_idx = end;
        return;
      }
                        
      if(A[begin] < A[mid])
      {
        if(A[begin] < target && target < A[mid])
        {
          do_work(A, begin, mid, target, tar_idx);
        }
        else
        {
          do_work(A, mid, end, target, tar_idx);
        }
      }
      else
      {
        if(A[mid] < target && target < A[end])
        {
          do_work(A, mid, end, target, tar_idx);
        }
        else
        {
          do_work(A, begin, mid, target, tar_idx);
        }
      }
    }
    else
    {
      if(A[begin] == target)
      {
        tar_idx = begin;
      }
      else if(A[end] == target)
      {
        tar_idx = end;
      }
      return;
    }
  }
};
