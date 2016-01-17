class Solution {
  /** 
   *@param A : an integer sorted array
   *@param target :  an integer to be inserted
   *return : a list of length 2, [index1, index2]
   */
public:
  vector<int> searchRange(vector<int> &A, int target) {
    // write your code here
        
    vector<int> ret;
    int begin, end, fir_tar_idx, last_tar_idx;
        
    begin = 0;
    end = A.size() - 1;
    fir_tar_idx = -1;
    last_tar_idx = -1;
        
    if(A.size())
    {
      do_work_first(A, begin, end, target, fir_tar_idx);
      do_work_last(A, begin, end, target, last_tar_idx);
    }
        
    ret.push_back(fir_tar_idx);
    ret.push_back(last_tar_idx);
        
    return ret;
  }
    
  void do_work_first(vector<int> &A,
                     int begin,
                     int end, 
                     int target,
                     int &fir_tar_idx)
  {
    int mid;
                            
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
                                
      if(A[mid] > target)
      {
        do_work_first(A, begin, mid, target, fir_tar_idx);
      }
      else if(A[mid] < target)
      {
        do_work_first(A, mid, end, target, fir_tar_idx);
      }
      else
      {
        if(mid < fir_tar_idx || -1 == fir_tar_idx)
        {
          fir_tar_idx = mid;
        }
        do_work_first(A, begin, mid, target, fir_tar_idx);
      }
    }
    else
    {
      if(A[begin] == target && 
         (begin < fir_tar_idx || fir_tar_idx == -1))
      {
        fir_tar_idx = begin;
      }
                                
      if(A[end] == target && 
         (end < fir_tar_idx || fir_tar_idx == -1))
      {
        fir_tar_idx = end;
      }
      return;
    }
  }
                        
    
  void do_work_last(vector<int> &A,
                    int begin,
                    int end, 
                    int target,
                    int &last_tar_idx)
  {
    int mid;
                            
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
                                
      if(A[mid] > target)
      {
        do_work_last(A, begin, mid, target, last_tar_idx);
      }
      else if(A[mid] < target)
      {
        do_work_last(A, mid, end, target, last_tar_idx);
      }
      else
      {
        if(mid > last_tar_idx || -1 == last_tar_idx)
        {
          last_tar_idx = mid;
        }
        do_work_last(A, mid, end, target, last_tar_idx);
      }
    }
    else
    {
      if(A[begin] == target && 
         (begin > last_tar_idx || last_tar_idx == -1))
      {
        last_tar_idx = begin;
      }
                                
      if(A[end] == target && 
         (end > last_tar_idx || last_tar_idx == -1))
      {
        last_tar_idx = end;
      }
      return;
    }
  }
};
