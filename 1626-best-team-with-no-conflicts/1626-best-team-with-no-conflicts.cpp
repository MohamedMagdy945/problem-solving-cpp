class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> players;
        for (int i = 0; i < n; i++) {
            players.push_back({ages[i], scores[i]});
        }
        sort(players.begin(), players.end());
        int bestScore = players[0].second  ;
        vector<int> dp(n) ;
        dp[0] = bestScore ;
        for(int i = 1 ; i < scores.size() ; i++){
            int score = 0 ;
            for (int j = i - 1 ; j >= 0 ; j--){
                if(players[j].second <= players[i].second)
                {
                    if(dp[j] > score )
                    {
                        score = dp[j] ;
                    }
                }
            }
            dp[i] = score + players[i].second ;
            if(bestScore <  dp[i]) bestScore = dp[i];
        }
        return bestScore;
    }
};
