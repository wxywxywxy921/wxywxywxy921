class Solution {
public:
  /**
   * @param prices: Given an integer array
   * @return: Maximum profit
   */
  int maxProfit(vector<int> &prices) {
    // write your code here
        
    int profit = 0;
    int i = 0;
        
    for(i = 1; i < prices.size(); i ++)
    {
      if(prices[i] > prices[i - 1])
      {
        profit += prices[i] - prices[i - 1];
      }
    }
        
    return profit;
  }
};
