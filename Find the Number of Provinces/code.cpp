void dfs(int node, vector<int>& visited, vector<vector<int>> roads){
    visited[node] = 1;
    for(int i=0; i<roads[node-1].size(); i++){
        if(roads[node-1][i] == 1 && !visited[i+1]){
            dfs(i+1, visited, roads);
        }
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    vector<int> visited(n+1);
    int count = 0;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            count++;
            dfs(i, visited, roads);
        }
    }
    return count;
}
