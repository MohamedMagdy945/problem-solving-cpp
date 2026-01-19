class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0 , high = nums.size() - 1;
        
        while(low <high )
        {
            int mid = low + (high - low ) /2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            if(nums[mid] == nums[mid - 1])
            {
                mid--;
            }
            if((mid - low) % 2 != 0)
            {
                high = mid - 1;
            }
            else{
                low = mid + 2 ;
            }
        }
        return nums[high];
    }
};