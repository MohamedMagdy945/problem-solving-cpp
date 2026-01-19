class Solution {
public:
    long long calchourPerK(vector<int>& piles , int k)
    {
        long long hour = 0;
        for(auto &p : piles)
        {
            hour += ( (p + k - 1) / k);
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin() , piles.end());
        int low = 1;
        int ans = high ;
        while(low <= high)
        {
            int k = low +( high - low ) / 2;
            if(calchourPerK(piles,k) <= h)
            {
                high = k - 1;
                ans = k;
            }
            else{
                low = k + 1;
            }
        }
        return ans;
    }
};