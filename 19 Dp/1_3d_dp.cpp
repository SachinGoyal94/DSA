class Solution {
public:
    int solve(vector<int>& prices,int i,int buy,int no)
    {
        if(i==prices.size() )
            return 0;
        if(buy && no<2)
        {
            int buyprofit=solve(prices,i+1,0,no+1)-prices[i];
            int skipprofit=solve(prices,i+1,1,no);
            return max(buyprofit,skipprofit);
        }
        else
        {
            if(!buy)
            {
                int sellprofit=solve(prices,i+1,1,no)+prices[i];
                int skipprofit=solve(prices,i+1,0,no);
                return max(sellprofit,skipprofit);
            }
        }
        return 0;
    }
    int solvedp(vector<int>& prices, int i, int buy, int no, vector<vector<vector<int>>>& dp) 
    {
        if (i == prices.size() || no == 2) 
            return 0; 
        
        if (dp[i][buy][no] != -1) 
            return dp[i][buy][no];
        if (buy) 
        {
            int buyProfit = solvedp(prices, i + 1, 0, no, dp) - prices[i]; 
            int skipProfit = solvedp(prices, i + 1, 1, no, dp);
            return dp[i][buy][no] = max(buyProfit, skipProfit);
        } 
        else 
        {
            int sellProfit = solvedp(prices, i + 1, 1, no + 1, dp) + prices[i]; 
            int skipProfit = solvedp(prices, i + 1, 0, no, dp);
            return dp[i][buy][no] = max(sellProfit, skipProfit);
        }
    }
    int solvetab(vector<int>& prices,vector<vector<vector<int>>>&dp)
    {
        for(int i=prices.size()-1;i>-1;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                for(int no=1;no>-1;no--)
                {
                    if (buy) 
                    {
                        int buyProfit = dp[i + 1][0][no] - prices[i]; 
                        int skipProfit = dp[i + 1][1][no];
                        dp[i][buy][no] = max(buyProfit, skipProfit);
                    } 
                    else 
                    {
                        int sellProfit = dp[i + 1][1][no+1]+ prices[i]; 
                        int skipProfit = dp[i + 1][0][no];
                        dp[i][buy][no] = max(sellProfit, skipProfit);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
    int solveSO(vector<int>& prices,int k)
    {
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));
        for(int i=prices.size()-1;i>-1;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                for(int no=k-1;no>-1;no--)
                {
                    if (buy) 
                    {
                        int buyProfit = next[0][no] - prices[i]; 
                        int skipProfit = next[1][no];
                        curr[buy][no] = max(buyProfit, skipProfit);
                    } 
                    else 
                    {
                        int sellProfit = next[1][no+1]+ prices[i]; 
                        int skipProfit = next[0][no];
                        curr[buy][no] = max(sellProfit, skipProfit);
                    }
                }
            }
            next=curr;
        }
        return curr[1][0];
    }
    int maxProfit(vector<int>& prices) 
    {
        int buy=1;
        // int ans=solve(prices,0,buy,0);
        // vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, -1)));
        // int ans=solvedp(prices,0,buy,0,dp);
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));
        // int ans=solvetab(prices,dp);
        int ans=solveSO(prices,2);
        return ans;    
    }
};