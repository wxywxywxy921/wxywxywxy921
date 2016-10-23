class Solution {
public:    
  /**
   * @param numbers : Give an array numbers of n integer
   * @return : Find all unique triplets in the array which gives the sum of zero.
   */
  vector<vector<int> > threeSum(vector<int> &nums) {
    // write your code here
        
    vector<vector<int> > ret;
    vector<int> temp;
        
    sort(nums.begin(), nums.end());
        
    int i = 0, j = 0, k = 0;
        
    for(i = 0; i < nums.size() - 2; i ++)
    {
      j = i + 1;
      k = nums.size() - 1;
            
      while(j < k)
      {
        temp = twoSum(nums, j, k, nums[i]);
        if(temp.size())
        {
          ret.push_back(temp);
        }
                
        while(j < k && nums[j] == nums[j+1]) j++;
        while(j < k && nums[k] == nums[k-1]) k--;
                
        j++; k--;
      }
            
      while(nums[i] == nums[i+1] && i < nums.size() - 1) i++;
    }
        
    return ret;
  }
    
  vector<int> twoSum(vector<int> nums, int &start, int &end, int target)
  {
    vector<int> ret;
        
    while(start < end)
    {
      if(nums[start] + nums[end] == -target)
      {
        ret.push_back(target);
        ret.push_back(nums[start]);
        ret.push_back(nums[end]);
                
        return ret;
      }
      else if(nums[start] + nums[end] < -target)
      {
        start ++;
      }
      else
      {
        end --;
      }
    }
        
    return ret;
  }
};
