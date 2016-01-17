class Solution {
public:
  /**
   * @param A an integer array
   * @param target an integer
   * @param k a non-negative integer
   * @return an integer array
   */
     
  int abs(int x)
  {
    int ret;
         
    if(x < 0)
      ret = -x;
    else
      ret = x;
            
    return ret;
  }
     
  vector<int> kClosestNumbers(vector<int>& A, int target, int k) {
    // Write your code here
        
    vector<int> ret;
    int begin, end, tar_idx;
    int neg_idx, pos_idx;
        
    begin = 0;
    end = A.size() - 1;
    tar_idx = -1;
        
    if(A.size() && k > 0)
    {
      do_work(A, begin, end, target, tar_idx);
            
      if(tar_idx >= 0)
      {
        if(!tar_idx)
        {
          neg_idx = tar_idx;
          pos_idx = tar_idx + 1;
        }
        else
        {
          neg_idx = tar_idx - 1;
          pos_idx = tar_idx;
        }
                
        while(1)
        {
          if(abs(target - A[neg_idx]) < abs(target - A[pos_idx]))
          {
            ret.push_back(A[neg_idx]);

            neg_idx --;
                        
            if(neg_idx < 0)
            {
              while(pos_idx < A.size() && ret.size() < k)
              {
                ret.push_back(A[pos_idx]);
                pos_idx ++;
              }
              break;
            }
          }
          else if(abs(target - A[neg_idx]) > abs(target - A[pos_idx]))
          {    
            ret.push_back(A[pos_idx]);
                        
            pos_idx ++;
                        
            if(pos_idx > A.size() - 1)
            {
              while(neg_idx >= 0 && ret.size() < k)
              {
                ret.push_back(A[neg_idx]);
                neg_idx --;
              }
              break;
            }
          }
          else
          {
            ret.push_back(A[neg_idx]);

            if(ret.size() < k)
            {
              ret.push_back(A[pos_idx]);
            }
            else
            {
              break;
            }
                        
            pos_idx ++;
            neg_idx --;
                        
            if(neg_idx < 0)
            {
              while(pos_idx < A.size() && ret.size() < k)
              {
                ret.push_back(A[pos_idx]);
                pos_idx ++;
              }
              break;
            }
                        
            if(pos_idx > A.size() - 1)
            {
              while(neg_idx >= 0 && ret.size() < k)
              {
                ret.push_back(A[neg_idx]);
                neg_idx --;
              }
              break;
            }
          }
                    
          if(ret.size() == k)
          {
            break;
          }
        }
      }
    }
        
    return ret;
  }
    
  void do_work(vector<int> &A, int begin, int end, int target, int &tar_idx)
  {
    int mid;
        
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
            
      if(A[mid] < target)
      {
        do_work(A, mid, end, target, tar_idx);
      }
      else if(A[mid] > target)
      {
        do_work(A, begin, mid, target, tar_idx);
      }
      else
      {
        tar_idx = mid;
        return;
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
      else
      {
        if(target < A[begin])
        {
          tar_idx = begin;
        }
        else if(target > A[end])
        {
          tar_idx = end;
        }
        else 
        {
          if(A[end] - target > target - A[begin])
          {
            tar_idx = begin;
          }
          else
          {
            tar_idx = end;
          }
        }
        return;
      }
    }
  }
};
