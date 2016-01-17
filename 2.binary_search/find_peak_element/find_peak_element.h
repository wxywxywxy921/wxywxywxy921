class Solution {
public:
  /**
   * @param A: An integers array.
   * @return: return any of peek positions.
   */
  int findPeak(vector<int> A) {
    // write your code here
        
    int begin, end, tar_idx;
        
    begin = 0;
    end = A.size() - 1;
    tar_idx = -1;
        
    if(A.size())
    {
      do_work(A, begin, end, tar_idx);
    }
        
    return tar_idx;
  }
    
  void do_work(vector<int> &A, 
               int &begin,
               int &end,
               int &tar_idx)
  {
    int mid;
                    
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
                        
      if(A[mid] > A[mid - 1] && A[mid] < A[mid + 1])
      {
        do_work(A, mid, end, tar_idx);
      }
      else if(A[mid] < A[mid - 1] && A[mid] > A[mid + 1])
      {
        do_work(A, begin, mid, tar_idx);
      }
      else if(A[mid] < A[mid - 1] && A[mid] < A[mid + 1])
      {
        do_work(A, begin, mid, tar_idx);
      }
      else
      {
        tar_idx = mid;
        return;
      }
    }
    else
    {
      if(A[begin] > A[end])
      {
        tar_idx = begin;
      }
      else
      {
        tar_idx = end;
      }
      return;
    }
  }
};
