class Solution {
public:
  /**
   * @param arrays k sorted integer arrays
   * @return a sorted array
   */
  vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {
    // Write your code here
        
    vector<int> ret;
    int tot_size = 0;
    int i = 0;
    int j = 0;
        
    for(i = 0; i < arrays.size(); i++)
    {
      tot_size += arrays[i].size();
    }
        
    if(!tot_size)
    {
      return ret;
    }
    else
    {
      for(i = 0; i < arrays.size(); i++)
      {
        for(j = 0; j < arrays[i].size(); j++)
        {
          ret.push_back(arrays[i][j]);
        }
      }
    }
        
    sort(ret.begin(), ret.end());
        
    return ret;
  }
};
