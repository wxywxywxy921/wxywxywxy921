class Solution {
public:
  /**
   * @param nums: A list of integers
   * @return: A list of integers includes the index of the first number 
   *          and the index of the last number
   */
  vector<int> subarraySum(vector<int> nums){
    // write your code here
        
        
    int i, j, sum;
    vector<int> ret;
        
    if(!nums.size())
    {
      return ret;
    }
        
    if(nums.size() == 1)
    {
      ret.push_back(0);
      ret.push_back(0);
            
      return ret;
    }
        
    for(i = 0; i < nums.size(); i++)
    {
      sum = nums[i];
                
      if(!sum)
      {
        ret.push_back(i);
        ret.push_back(i);
        return ret;
      }
            
      for(j = i + 1; j < nums.size(); j++)
      {
        sum += nums[j];
                
        if(!sum)
        {
          ret.push_back(i);
          ret.push_back(j);
          return ret;
        }
      }
    }
  }
};
