//gfg find first -ve no in window of k elements
class Solution {
  public:
    vector<int> printFirstNegativeInteger(vector<int>& A, int k) 
    {
        deque< int> q;
        vector<int>  ans;
        for(int i=0; i<k; i++ )
        {
            int element = A[i];    
            if(element < 0) 
            {
                q.push_back(i);
            }
        }
        if(q.empty()) 
        {
            ans.push_back(0);
        }
        else 
        {
            int index = q.front();
            int element = A[index];
            ans.push_back(element);
        }
        for(int i=k; i<A.size(); i++) 
        {
            if(!q.empty() && q.front() < i-k+1 ) 
            {
                q.pop_front();
            }
            int element = A[i];
            if(element < 0) 
            {
                q.push_back(i);
            }
            if(q.empty()) 
            {
                ans.push_back(0);
            }
            else 
            {
                int index = q.front();
                int element = A[index];
                ans.push_back(element);
            }
        }
    return ans;
    }
};