class Solution
{
private:
    long long calcTrip(vector<int>& time , long long hour)
    {
        long long numberOfTrip =0 ;
        for(auto &t : time)
        {
            numberOfTrip += hour / t ;
        }
        return numberOfTrip ;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        long long min = INT_MAX , max = 0 ;
        for(auto &t : time)
        {
            if( min > t ) min = t ;
            if( max < t ) max = t ;
        }
        long long low = min , high = max * totalTrips ;
        long long minNumberOfTrip = high ;
        while(low <= high)
        {
            long long mid = low + (high - low ) /2 ;
            long long trip = calcTrip(time, mid) ;
            if( trip >= totalTrips)
            {
                high = mid - 1 ;
                minNumberOfTrip = mid ;
            }
            else {
                low = mid + 1 ;
            }
        } 
        return minNumberOfTrip;
    }
};