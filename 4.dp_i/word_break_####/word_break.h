class Solution {
public:
  /**
   * @param s: A string s
   * @param dict: A dictionary of words dict
   */
  bool wordBreak(string s, unordered_set<string> &dict) {
    // write your code here
        
    int dict_largest_size = 0;
    int i, j;
    int dp[s.size()];
    int start;
        
    if(!s.size())
      return true;
        
    for(i = 0; i < s.size(); i++)
    {
      dp[i] = false;
    }
        
    if(dict.find(s.substr(0, 1)) != dict.end())
    {
      dp[0] = true;
    }
        
    for(auto it = dict.begin(); it != dict.end(); ++it)
    {
      if(it->size() > dict_largest_size)
      {
        dict_largest_size = it->size();
      }
    }
        
    for(i = 1; i < s.size(); i++)
    {
      if( i >= dict_largest_size)
      {
        start = i - dict_largest_size + 1;
      }
      else
      {
        start = 1;
      }
            
      if(start == 1 && dict.find(s.substr(0, i + 1)) != dict.end())
      {
        dp[i] = true;
      }
            
      for(j = start; j <= i; j++ )
      {
        if(dp[j - 1] && dict.find(s.substr(j, i - j + 1)) != dict.end())
        {
          dp[i] = true;
          break;
        }
      }
    }
        
    return dp[s.size() - 1];
  }
};
