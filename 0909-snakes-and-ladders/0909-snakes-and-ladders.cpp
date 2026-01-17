class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {  
        int n = board.size();
        int m = n * n;
        vector<int> b(m + 1);
        bool leftToRight = (n % 2 == 0);
        int k = m;

        for (int i = 0; i < n; i++) {
            if (leftToRight)
                for (int j = 0; j < n; j++) b[k--] = board[i][j];
            else
                for (int j = n - 1; j >= 0; j--) b[k--] = board[i][j];
            leftToRight = !leftToRight;
        }
        queue<int> q ;
        q.push(1);
        int steps  = 0;
        vector<bool> visited(m + 1, false);
        visited[1] = true;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)   
            {
                int curr = q.front() ;
                q.pop();
                for(int dice = 1 ; dice <=6 ; dice++)
                {
                    int next = curr + dice;
                    if (next > m) continue;
                    if (b[next] != -1) next = b[next];
                    if (next == m) return steps + 1;
                    if (!visited[next]) { visited[next] = true; q.push(next); }
                }  
            }
            steps++;
        }
        return -1;
    }
};