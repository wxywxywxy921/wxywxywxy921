class Solution {
public:
  /**
   * @param candidates: A list of integers
   * @param target:An integer
   * @return: A list of lists of integers
   */
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    // write your code here
    vector<int> cur;
    vector<vector<int> > ret;
    int i;
        
    sort(candidates.begin(), candidates.end());
        
    helper(candidates, target, ret, 0, cur);
        
    return ret;
  }
    
  bool helper(vector<int> &candidates, int target, vector<vector<int> > &ret, int idx, vector<int> &cur)
  {
    int i;
        
    if(candidates[idx] > target)
    {
      //printf("[4]\n");   
      return false;
    }
    else if(candidates[idx] == target)
    {
      cur.push_back(candidates[idx]);
      //printf("[0] push=%d, size=%d\n", candidates[idx], cur.size());
      ret.push_back(cur);
      cur.pop_back();
      //printf("[3] pop, size=%d\n", cur.size());   
            
      return true;
    }
    else
    {
      for(i = idx; i < candidates.size(); i++)
      {
        cur.push_back(candidates[i]);
        //printf("[1] push=%d, size=%d\n", candidates[i], cur.size());   
                
        if(target != candidates[i])
        {
          helper(candidates, target - candidates[i], ret, i, cur);
        }
        else
        {
          ret.push_back(cur);  //[xywu] missed this case!!!
        }
                
        cur.pop_back();
        //printf("[2] pop, size=%d\n", cur.size());   
      }
    }
  }
};
