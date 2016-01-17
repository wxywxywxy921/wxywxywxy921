class Solution {
public:
  /** 
   *@param L: Given n pieces of wood with length L[i]
   *@param k: An integer
   *return: The maximum length of the small pieces.
   */
  int woodCut(vector<int> L, int k) {
    // write your code here
        
    int ret = 0;
        
    sort(L.begin(), L.end());
        
    if(L.size())
    {
      do_work(L, k, 0, L[L.size() - 1], ret);
    }
        
    return ret;
  }
    
  void do_work(vector<int> L, int k, int begin, int end, int &ret)
  {
    int mid;
        
    if(begin + 1 < end)
    {
      mid = (end - begin) >> 1;
      mid += begin;
            
      if(meet_target(L, k, mid))
      {   
        if(mid > ret)
        {
          ret = mid;
        }
                
        do_work(L, k, mid, end, ret);
      }
      else
      {
        do_work(L, k, begin, mid, ret);
      }
    }
    else
    {
      if(meet_target(L, k, end))
      {
        ret = end;
      }
            
      if(meet_target(L, k, begin))
      {
        ret = begin;
      }
      return;
    }
  }
    
  int meet_target(vector<int> L, int k, int input)
  {
    int ret = 0;
    int cnt = 0;
    int idx = 0;
        
    //[xywu] important sanity check
    if(!input)
    {
      return ret;
    }
        
    for(; idx < L.size(); idx ++)
    {
      cnt += L[idx] / input;
    }
        
    if(cnt >= k)
    {
      ret = 1;
    }
        
    return ret;
  }
};
