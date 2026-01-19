class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0 ;
        int high = arr.size() - 1; 

        while(low <= high)
        {
            int mid = low + (high - low) /2 ;
            int mssingItemNumber = arr[mid] - mid - 1 ;
            if( mssingItemNumber < k)
            {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low + k ;
    }
};