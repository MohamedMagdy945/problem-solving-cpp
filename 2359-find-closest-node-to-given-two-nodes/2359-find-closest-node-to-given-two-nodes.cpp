class Solution{
    public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis1 (n , -1);
        vector<int> dis2 (n , -1);
        dis1[node1] =0 , dis2[node2] =0 ;
        int distant = 1;
        
        while( edges[node1] != -1 && dis1[edges[node1]] == -1 )
        {
            dis1[edges[node1]] = distant++;
            node1= edges[node1];
        }
        distant = 1;
        while(edges[node2] != -1 && dis2[edges[node2]] == -1)
        {
            dis2[edges[node2]] = distant++;
            node2= edges[node2] ;
        }
        int best = INT_MAX;
        int node = -1;
        for(int i = 0; i < n; i++) {
            if(dis1[i] == -1 || dis2[i] == -1) continue;

            int cur = max(dis1[i], dis2[i]);
            if(cur < best) {
                best = cur;
                node = i;
            }
        }
        return node ;
    }
};