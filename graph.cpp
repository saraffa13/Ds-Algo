Dfs
void dfs(int v){
    vis[v]=1;
    for(int x:edges[v]){
        if(!vis[x]){
            dfs(x);
        }
    }
}
