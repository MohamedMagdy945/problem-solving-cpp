class Solution {
public:
  bool isPowerOfFour(long long n) {
    if (n <= 0) return false;

    while (n % 4 == 0) {
        n /= 4;
    }

    return n == 1;
}

};