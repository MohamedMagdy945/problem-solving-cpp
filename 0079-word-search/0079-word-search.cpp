class Solution {
private:
    int n, m;
    bool backtrack(vector<vector<char>>& board, int idx , int x , int y , string& word)
    {           
        if(idx == word.size()) return true;    
        if ( x < 0 || x >= m || y < 0 || y >= n ) return false ;
        
        if(word[idx] != board[x][y]) return false ;
        char temp = board[x][y] ;
        board[x][y] = '#' ;
        bool found = 
            backtrack(board, idx + 1 , x , y - 1 , word) || 
            backtrack(board, idx + 1 , x , y + 1 ,word) ||
            backtrack(board, idx + 1 , x - 1 , y ,  word) ||
            backtrack(board, idx + 1 , x + 1, y ,  word);
        
        board[x][y] = temp ;
        
        return found ;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size() ;

        for( int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if (backtrack(board,0 ,i , j ,word )) return true ;
            }
        }      
        return false ;
    }
};