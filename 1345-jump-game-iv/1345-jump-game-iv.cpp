class Solution{
private:
public:
int minJumps(vector<int>& arr) {
  int n = arr.size();      
  vector<bool> visited(n,false);

  unordered_map<int,vector<int>> map ;
  for(int i = 0 ; i< n ; i++)
  {
    map[arr[i]].push_back(i); 
  }
  queue<int> q; 
  q.push(0);
  int steps = 0;
  visited[0] = true ;
  while (!q.empty())
  {
    int size = q.size();

    while(size--)
    {
        int idx  = q.front();
        q.pop();
        
        if(idx == n - 1) return steps ;
        if(idx + 1 && !visited[idx + 1]) 
        {
            q.push(idx + 1);
            visited[idx + 1] = true;
        }
        if(idx != 0 && !visited[idx - 1])
        {
            q.push(idx - 1);
            visited[idx - 1] = true;
        }
        for(auto &item: map[arr[idx]])
        {
            if(!visited[item])
            {
                q.push(item);
                visited[item] = true ;
            }
        }  
         map[arr[idx]].clear();  
    }
    steps++;
  }
return steps;
}
};