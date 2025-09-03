#include<bits/stdc++.h>
using namespace std;

// LOGIC 

/*
    -> 
*/

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

    vector<vector<pair<int,int>>>adj(V);
    for(int i = 0; i<edges.size();i++){
        int node = edges[i][0];
        int directedTo = edges[i][1];
        int distance = edges[i][2];
        adj[node].push_back({directedTo,distance});
        adj[directedTo].push_back({node,distance});
    }
    
    vector<int>dist(V,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>minHeap;
        
    minHeap.push({0,src});
    dist[src] = 0;
    while(!minHeap.empty()){
        auto node = minHeap.top();
        minHeap.pop();
        int val = node.second, distance = node.first;

        for(auto it:adj[val]){
            int node = it.first;
            int newDist = distance + it.second;
            if(newDist < dist[node]){
                dist[node] = newDist;
                minHeap.push({newDist, it.first});
            }
        }
    }
    return dist;
}

int main (){

}