class Solution {
public:
    vector<int> getRow(int numRows)
{
    vector<int> row(numRows + 1, 1);  

    for(int i = 0 ; i < numRows ; i++)
    {
        for(int j = i ; j > 0; j-- )
        {
            row[j] = row[j] + row[j-1] ;
        }     
    }
    return row;
}

};