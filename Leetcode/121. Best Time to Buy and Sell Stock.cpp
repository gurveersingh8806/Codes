class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min = INT_MAX;
        int profit = 0;

        for(int j=0;j<n;j++){
            if(prices[j]<min)
            min = prices[j];
            else if(prices[j]-min > profit)
            profit = prices[j]-min;
        }

        return profit;
    }
};