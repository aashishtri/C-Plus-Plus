#include <bits/stdc++.h>
using namespace std;

int *topoSortKahn(int N, vector<int> adj[]);

int main() {
    
    int nodes, edges;
    cin >> edges >> nodes;
    if(edges==0||nodes==0)
    	return 0;
    int u, v;

    vector<int> graph[nodes];
    //create graph
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    int *topo = topoSortKahn(nodes, graph);
    //topologically sorted nodes
    for(int i = 0; i < nodes; i++){
    	cout<<topo[i]<<" ";
    }
    
    
}

int* topoSortKahn(int V, vector<int> adj[]) {
    // Your code here
    vector<bool>vis(V+1,false);
    vector<int>deg(V+1,0);
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            deg[adj[i][j]]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        //cout<<deg[i]<<" ";
        if(deg[i]==0){
            q.push(i);
            vis[i]=true;
        }
    }
    int *arr=new int[V+1];
    memset(arr,0,V+1);
    int count=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        arr[count]=cur;
        count++;
        //cout<<cur<<" ";
        for(int i=0;i<adj[cur].size();i++){
            if(!vis[adj[cur][i]]){
                deg[adj[cur][i]]--;
                
                
                if(deg[adj[cur][i]]==0)
                {    
                    q.push(adj[cur][i]);
                    vis[adj[cur][i]]=true;
                }
                
            }
        }
        
        
    }
    
    return arr;
}
