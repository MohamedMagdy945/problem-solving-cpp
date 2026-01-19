class Solution
{
    private:
    int calcDayPerWeight(vector<int>& weights, int maxWeight){
        int reminderWeight = maxWeight ;
        int days = 0;
        for(int &w : weights)
        {
            if(reminderWeight < w)
            {
                days++;
                reminderWeight = maxWeight;
            }
            reminderWeight -= w ;
        }
        if (reminderWeight < maxWeight) days++;
        return days;
    }
    public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low =  *max_element(weights.begin(), weights.end());
        int high = 0;
        for (int &x : weights) high += x;
        int maxWeight = high ;
        while(low <= high)
        {
            int m = low + (high - low ) / 2 ;
            int DaysPerWeight =  calcDayPerWeight(weights , m);
            if ( DaysPerWeight <= days)
            {
                high = m - 1;
                maxWeight = m;
            }
            else{
                low = m + 1;
            }
        }
        return maxWeight ;
    }
};
