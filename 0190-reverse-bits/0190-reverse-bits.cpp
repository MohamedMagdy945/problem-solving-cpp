class Solution {
public:
  int reverseBits(int n){
    string binary;
    for (int i = 0; i < 32; i++) {
        int bit = n % 2;
        binary += bit + '0'; 
        n /= 2;
    }
    int reversebit = 0;
    for (char c : binary){
        reversebit = reversebit * 2 + (c - '0');
    }
    return reversebit;
}
};