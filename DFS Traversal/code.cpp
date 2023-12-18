void dfs(int node, vector<int> &component, vector<bool> &visited, unordered_map<int, vector<int>> adj){
    component.push_back(node);
    visited[node] = true;

    for(auto itr: adj[node]){
      if(!visited[itr]){
        dfs(itr, component, visited, adj);
      }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{ 
    unordered_map<int, vector<int>> adj;
    for(int i=0; i<E; i++){
      int x = edges[i][0];
      int y = edges[i][1];

      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    vector<vector<int>> ans;
    vector<bool> visited(V, false);
    for(int i=0; i<V; i++){
      if(!visited[i]){
        vector<int> component;
        dfs(i, component, visited, adj);
        ans.push_back(component);
      }
    }
    return ans;
}
