class Solution {
public:
  /**
   * Calculate the total number of distinct N-Queen solutions.
   * @param n: The number of queens.
   * @return: The total number of distinct solutions.
   */
  int totalNQueens(int n) {
    // write your code here
        
    vector<vector<int> > result;
    vector<int> curr;
    int i;
        
    for(i = 0; i < n; i ++)
    {
      curr.push_back(i);
      helper(n, result, curr);
      curr.pop_back();
    }
        
    return result.size();
  }
    
  void helper(int n, vector<vector<int> > &result, vector<int> &curr)
  {
    int i;
        
    if(curr.size() == n)
    {
      result.push_back(curr);
      return;
    }
        
    for(i = 0; i < n; i ++)
    {
      if(!isValid(i, curr))
      {
        continue;
      }
      else
      {
        curr.push_back(i);
        helper(n, result, curr);
        curr.pop_back();
      }
    }
  }
    
  bool isValid(int i, vector<int> &curr)
  {
    int j; 
        
    for(j = 0; j < curr.size(); j++)
    {
      if(i == curr[j]
         || curr.size() - j == i - curr[j]
         || curr.size() - j == curr[j] - i)
      {
        return false;
      }
    }
        
    return true;
  }
};
