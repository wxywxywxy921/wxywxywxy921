class Solution {
public:    
  /**
   * @param nums: A list of integers
   * @return: A integer indicate the sum of max subarray
   */
  int maxSubArray(vector<int> nums) {
    // write your code here
        
    if(!nums.size())
      return 0;
           
    int i;
    int local_max, global_max;
        
    local_max = 0;
    global_max = -9999999;
        
    for(i = 0; i < nums.size(); i++)
    {
      if(i == 0)
      {
        local_max = nums[0];
      }
      else
      {
        local_max = max(local_max + nums[i], nums[i]);
      }
            
      if(local_max > global_max)
      {
        global_max = local_max;
      }
    }
        
    return global_max;
  }
};
