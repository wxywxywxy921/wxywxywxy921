class Solution {
public:
  /**
   * @param s: A string
   * @return: A list of lists of string
   */
  vector<vector<string>> partition(string s) {
    // write your code here
        
    vector<vector<string> > ret;
    vector<string> cur;
        
    helper(s, ret, 0, cur);
        
    return ret;
  }
    
  void helper(string s, vector<vector<string> > &ret, int start, vector<string> &cur)
  {
    int i; 
        
    if(start == s.size())
    {
      ret.push_back(cur);
      return;
    }
        
    for(i = start; i < s.size(); i++)
    {
      if(is_pali(s, start, i))
      {
        cur.push_back(s.substr(start, i-start+1)); // [xywu] remember the way to push back the string
        helper(s, ret, i + 1, cur);
        cur.pop_back();
      }
    }
  }
    
  bool is_pali(string s, int start, int end)
  {
    while(start <= end)
    {
      if(s[start] != s[end])
      {
        return false;
      }
            
      start ++;
      end --;
    }
        
    return true;
  }
};
