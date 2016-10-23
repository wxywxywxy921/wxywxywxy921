class Solution {
public:
  /**
   * @param prices: Given an integer array
   * @return: Maximum profit
   */
  int maxProfit(vector<int> &prices) {
    // write your code here
        
    int min_price, max_profit, i;
        
    min_price = 99999999;
    max_profit = 0;
        
    for(i = 0; i < prices.size(); i++)
    {
      if(prices[i] < min_price)
      {
        min_price = prices[i];
      }
            
      if((prices[i] - min_price) > max_profit)
      {
        max_profit = prices[i] - min_price;
      }
    }
        
    return max_profit;
  }
};
