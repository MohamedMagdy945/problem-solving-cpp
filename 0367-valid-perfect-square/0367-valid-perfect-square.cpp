class Solution {
public:
bool isPerfectSquare(int num){
    if(num < 2) return true;
    int left = 0;
    int right = num /2;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        long long sqrt = (long long)mid * mid;
        if (sqrt  == num )
        {
            return true;
        }
        else if( sqrt < num)
        {
            left = mid +1 ;
        }
        else {
            right = mid - 1;
        }
    }
    return false; 
}
};