class Solution {
public:
    int titleToNumber(string columnTitle)
{
    int number = 0 ;
    for(int i = 0 ; i < columnTitle.size() ; i++)
    {
        number = number * 26 +( columnTitle[i] - 'A' + 1);
    }
    return number ;
}

};