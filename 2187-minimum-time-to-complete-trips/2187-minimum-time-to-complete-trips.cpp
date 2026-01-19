class Solution
{
private:
    bool cantrip(vector<int>& time   , long long numOfTime , long long totalTrips)
    {
        long long numberOfTrip =0 ;
        for(auto &t : time)
        {
            numberOfTrip += numOfTime / t ;
            if(numberOfTrip >= totalTrips) return true ;
        }
        return false  ;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        long long min = INT_MAX  ;
        for(auto &t : time)
        {
            if( min > t ) min = t ;
        }
        long long low = min , high = low * totalTrips ;
        long long minNumberOfTrip = high ;
        while(low <= high)
        {
            long long mid = low + (high - low ) /2 ;
           
            if(cantrip(time,mid, totalTrips))
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