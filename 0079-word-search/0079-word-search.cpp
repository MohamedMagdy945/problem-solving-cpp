class Solution {
private:
    vector<vector<bool>> visited;

    int n, m;
    bool backtrack(vector<vector<char>>& board, int idx , int x , int y , string& w , string& word)
    {           
        w.push_back(word[idx]);
        if (board[x][y] != word[idx])
        {
            w.pop_back();
            return false ;
        }
        if (w == word) return true ;
        bool leftDir =false ,  rightDir = false ,  topDir = false ,  downDir = false; 
        visited[x][y] = true ;
        if (y > 0 && !visited[x][y - 1])
        {
            leftDir = backtrack(board, idx + 1 , x , y - 1 , w , word);
        }
        if (y < n - 1 && !visited[x][y + 1] )
        {
            rightDir = backtrack(board, idx + 1 , x , y + 1 , w , word);
        }
        if (x  > 0 && !visited[x - 1][y] )
        {
            topDir = backtrack(board, idx + 1 , x - 1 , y , w , word);
        }
        if (x < m - 1 && !visited[x + 1][y])
        {
            downDir = backtrack(board, idx + 1 , x + 1, y , w , word);
        }
        w.pop_back();
        visited[x][y] =false ;
        return leftDir || rightDir || topDir || downDir ;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size() ;
        string w = "";

        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for( int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if (backtrack(board,0 ,i , j , w ,word )) return true ;
            }
        }
        
        return false ;
    }
};
