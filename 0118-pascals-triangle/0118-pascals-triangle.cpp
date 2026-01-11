class Solution {
public:
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> pascalTriangle;
   
    for(int i = 0 ; i < numRows ; i++)
    {
        vector<int> v = {1};
        for(int j = 1 ; j < i; j++ )
        {
            v.push_back(pascalTriangle[i-1][j] + pascalTriangle[i-1][j-1]);
        }
        if(i != 0)
            v.push_back(1);
        pascalTriangle.push_back(v);
    }
    return pascalTriangle;
}
};