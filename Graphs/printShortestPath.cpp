#include<bits/stdc++.h>
using namespace std;

// LOGIC

/*
    -> APPLYING DIJKSTRA BY SLIDE MODIFICATION.
    -> WE WILL CREATE A PARENT ARRAY AND IF WE FOUND A BETTER DISTANCE WE WILL UPDATE IT'S PARENT.
    -> PARENT WILL KEEP TRACK FROM WHERE WE ARE COMING TO THE NODE.
    -> IF WE DIDN'T VISIT THE NODE, IT'S DISTANCE WOULD BE INT_MAX IN THAT CASE RETURN -1.
    -> ELSE WE WILL ITERATE TILL WHEN PARENT OF INDEX ISN'T THE INDEX ITSELF.
    -> THE PATH WE WILL GET IS IN REVERSE ORDER, HENCE WE WILL REVERSE THE PATH AND RETURN IT.
*/

vector<int> shortestPath(vector<vector<pair<int,int>>>graph, int n){
    // MIN HEAP
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    vector<int>dist(n,INT_MAX);
    dist[0] = 0;

    // INITIALISNG PARENT AS HIMSELF ONLY
    vector<int>parent(n);
    for(int i = 0; i<n; i++) parent[i] = i;

    // ITERATING
    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it:graph[node]){
            if(distance + it.second < dist[it.first]){
                dist[it.first] = distance + it.second;
                pq.push({dist[it.first],it.first});
                // UPDATING PARENT
                parent[it.first] = node;
            }
        }
    }
    // IF NOT ABLE TO REACH THE LAST NODE.
    if (dist[n-1] == INT_MAX) return {-1};
    vector<int>path;
    path.push_back(n-1);
    int index = n-1;
    // GETTING THE PATH IN REVERSE ORDER.
    while(parent[index]!=index){
        path.push_back(parent[index]);
        index = parent[index];
    }
    // GETTING THE CORRECT PATH BY REVERSING THE GIVEN PATH
    reverse(path.begin(),path.end());
    return path;

}

int main (){

}