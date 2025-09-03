#include<bits/stdc++.h>
using namespace std;

// LOGIC

/*
    -> WE WILL DO TOPOLOGICAL SORT.
    -> WE WILL NOW DO RELAXATION OF DISTANCE.
*/


// FINDING TOPOSORT
void topoSort(int node, vector<int> &vis, 
vector<vector<pair<int,int>>> &graph,stack<int> &st){
    vis[node] = 1;
    for(auto it:graph[node]){
        if(!vis[it.first]) topoSort(it.first,vis,graph,st);
    }
    st.push(node);
}



vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    // INIITALISING GRAPH
    vector<vector<pair<int,int>>>adj(V);
    for(int i = 0; i<edges.size(); i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    
    // COMPUTING TOPOSORT
    stack<int>st;
    vector<int>vis(V,0);
    topoSort(0,vis,adj,st);
    
    // INITIALISING DISTANCE WITH INFINITY(MAX DISTANCE POSS)
    vector<int>dist(V,INT_MAX);
    
    // RELAXATION OF THE DISTANCE.
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        int distance = dist[node];
        // CALCULATING NEW DISTANCE, COMPARING WITH OLDER ONE AND UPDATING IF REQUIRED.
        for(auto it:adj[node]){
            int oldDist = dist[it.first];
            int newDist = distance + it.second;
            dist[it.first] = min(oldDist,newDist);
        }
        
    }

    // IF WE ARE NOT ABLE TO REACH THE NODE, CHANGING IT'S DISTANCE TO -1.
    for(int i = 0; i<V; i++){
        if(dist[i]==INT_MAX) dist[i] = -1;
    }
    return dist;
    
}

int main (){

}