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
        int sum, max;
        
        sum = 0;
        max = -9999999;
        
        for(i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            if(sum > max)
            {
                max = sum;
            }
            
            if(sum < 0)
            {
                sum = 0;
            }
        }
        
        return max;
    }
};
