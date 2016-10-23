class Solution {
public:
  /**
   * @param str a string
   * @return all permutations
   */
  vector<string> stringPermutation2(string& str) {
    // Write your code here
        
    sort(str.begin(), str.end());
        
    vector<string> ret;
    string curr_string;
    vector<int> record(str.size(), 0);
    int i;
        
    helper(str, ret, record, curr_string);
        
    return ret;
  }
    
  void helper(string& str, vector<string> &ret, vector<int> &record, string &curr_string)
  {
    int i;
        
    if(curr_string.size() == str.size())
    {
      ret.push_back(curr_string);
    }
    else
    {
      for(i = 0; i < str.size(); i++)
      {
        if(record[i] == 0)
        {
          record[i] = 1;
          curr_string.push_back(str[i]);
          helper(str, ret, record, curr_string);
          curr_string.pop_back();
          record[i] = 0;
                    
          while(i < str.size() && str[i] == str[i + 1])
          {
            i++;
          }
        }
      }
    }
  }
};
