class Solution{
    public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis1 (n , -1);
        vector<int> dis2 (n , -1);
        dis1[node1] =0 , dis2[node2] =0 ;
        int distant = 1;
        
        while( edges[node1] != -1  )
        {
            dis1[edges[node1]] = distant++;
            node1= edges[node1];
        }
        distant = 1;
        while(edges[node2] != -1)
        {
            dis2[edges[node2]] = distant++;
            node2= edges[node2] ;
        }
        int maxDis =  1e9;
        int node = -1;
        for(int i = 0 ;  i < n ; i++)
        {
            int d1 = dis1[i] , d2 = dis2[i];
            if(d1  == -1 || d2 == -1) continue;
            if(d1 +  d2 == maxDis && i < node) node = i;
            else if( d1 + d2 < maxDis) 
            {
                maxDis = d1 + d2 ;
                node = i ;
            } 
        }
        return node ;
    }
};