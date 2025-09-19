#include<bits/stdc++.h>
using namespace std;

// LOGIC 

/*
    -> CREATE A DISTANCE ARRAY AND A MIN HEAP PRIORITY QUEUE.
    -> MIN HEAP SHOULD CONTAIN PAIR, FIRST ONE CONTAINING DISTANCE AND SECOND ONE CONTAINING NODE
    -> WE ARE DOING SO THAT PRIORITY QUEUE SORT ELEMENTS ON THE BASIS OF DISTANCE NOT ON THE BASIS OF NODES.
    -> PUT DISTANCE OF SOURCE AS 0 AND NODE OF SOURCE IN QUEUE.
    -> ITERATE WHILE PQ ISN'T EMPTY
    -> COMPUTE NEW DISTANCE
    -> IF NEW DISTANCE IS LESS THAN PREV, UPDATE THE DISTANCE AND PUSH THE NODE IN PQ.
*/

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    // CREATING  GRAPH
    vector<vector<pair<int,int>>>adj(V);
    for(int i = 0; i<edges.size();i++){
        int node = edges[i][0];
        int directedTo = edges[i][1];
        int distance = edges[i][2];
        adj[node].push_back({directedTo,distance});
        adj[directedTo].push_back({node,distance});
    }
    // INITIALISING PQ AND DISTANCE
    vector<int>dist(V,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>minHeap;
    // PUSHING INITIAL VALUES IN PQ
    minHeap.push({0,src});
    dist[src] = 0;
    while(!minHeap.empty()){
        auto node = minHeap.top();
        minHeap.pop();
        // INITIAL DISTANCE
        int val = node.second, distance = node.first;

        for(auto it:adj[val]){
            int node = it.first;
            // NEW DISTANCE
            int newDist = distance + it.second;
            // IF NEW DISTANCE IS LESS UPDATE IN DISTANCE, AND PUSH IN PQ.
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