class Solution {
public:
  /**
   * @param prices: Given an integer array
   * @return: Maximum profit
   */
  int maxProfit(vector<int> &prices) {
    // write your code here
        
    int i, max_price, min_price, ret;
        
    if(!prices.size() || prices.size() == 1)
    {
      return 0;
    }
        
    ret = -9999999;
        
    vector<int> left_max_profit(prices.size(), 0);
    vector<int> right_max_profit(prices.size(), 0);
        
    min_price = prices[0];
        
    for(i = 1; i < prices.size(); i++)
    {
      left_max_profit[i] = max(left_max_profit[i], prices[i] - min_price);
            
      if(prices[i] < min_price)
      {
        min_price = prices[i];
      }
    }
        
    max_price = prices[prices.size() - 1];
        
    for(i = prices.size() - 2; i >= 0; i--)
    {
      right_max_profit[i] = max(right_max_profit[i + 1], max_price - prices[i]);
            
      if(prices[i] > max_price)
      {
        max_price = prices[i];
      }
            
      if((right_max_profit[i] + left_max_profit[i]) > ret)
      {
        ret = right_max_profit[i] + left_max_profit[i];
      }
    }
        
    return ret;
  }
};
