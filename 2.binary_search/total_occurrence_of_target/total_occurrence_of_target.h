class Solution {
public:
  /**
   * @param A an integer array sorted in ascending order
   * @param target an integer
   * @return an integer
   */
  int totalOccurrence(vector<int>& A, int target) {
    // Write your code here
        
    int begin, end, tar_idx_first, tar_idx_last, ocur_cnt, idx;
        
    begin = 0;
    end = A.size() - 1;
    tar_idx_first = -1;
    tar_idx_last = -1;
    ocur_cnt = 0;
        
    if(A.size())
    {
      do_work_first(A, begin, end, target, tar_idx_first);
      do_work_last(A, begin, end, target, tar_idx_last);
            
      if(tar_idx_first != -1)
      {
        ocur_cnt = tar_idx_last - tar_idx_first + 1;
      }
    }
        
    return ocur_cnt;
  }
    
  void do_work_first(vector<int> &A, int begin, int end, int target, int &tar_idx)
  {
    int mid;
        
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
            
      if(A[mid] > target)
      {
        do_work_first(A, begin, mid, target, tar_idx);
      }
      else if(A[mid] < target)
      {
        do_work_first(A, mid, end, target, tar_idx);
      }
      else
      {
        if(tar_idx == -1 || mid < tar_idx)
        {
          tar_idx = mid;
        }
                
        do_work_first(A, begin, mid, target, tar_idx);
      }
    }
    else
    {
      if(A[begin] == target) 
      {
        if(tar_idx == -1 || begin < tar_idx)
        {
          tar_idx = begin;
        }
      }
            
      if(A[end] == target) 
      {
        if(tar_idx == -1 || end < tar_idx)
        {
          tar_idx = end;
        }
      }
            
      return;
    }
  }
    
  void do_work_last(vector<int> &A, int begin, int end, int target, int &tar_idx)
  {
    int mid;
        
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
            
      if(A[mid] > target)
      {
        do_work_last(A, begin, mid, target, tar_idx);
      }
      else if(A[mid] < target)
      {
        do_work_last(A, mid, end, target, tar_idx);
      }
      else
      {
        if(tar_idx == -1 || mid > tar_idx)
        {
          tar_idx = mid;
        }
                
        do_work_last(A, mid, end, target, tar_idx);
      }
    }
    else
    {
      if(A[begin] == target) 
      {
        if(tar_idx == -1 || begin > tar_idx)
        {
          tar_idx = begin;
        }
      }
            
      if(A[end] == target) 
      {
        if(tar_idx == -1 || end > tar_idx)
        {
          tar_idx = end;
        }
      }
            
      return;
    }
  }
};
