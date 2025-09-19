#include<bits/stdc++.h>
using namespace std;

// LOGIC 

/*
    -> CREATE A DISTANCE ARRAY AND A SET.
    -> SET SHOULD CONTAIN PAIR, FIRST ONE CONTAINING DISTANCE AND SECOND ONE CONTAINING NODE
    -> WE ARE DOING SO THAT SET SORT ELEMENTS ON THE BASIS OF DISTANCE NOT ON THE BASIS OF NODES.
    -> PUT DISTANCE OF SOURCE AS 0 AND NODE OF SOURCE IN SET.
    -> ITERATE WHILE SET ISN'T EMPTY
    -> COMPUTE NEW DISTANCE
    -> IF NEW DISTANCE IS LESS THAN PREV, UPDATE THE DISTANCE AND PUSH THE NODE IN PQ.
    -> IF NODE IS ALREADY VISITED AND WE GET A BETTER DISTANCE AGAIN, 
    -> THAT MEANS THERE IS STILL THE OLDER DISTANCE PRESENT IN THE SET, WE WILL JUST GO AND ERASE IT.
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
    // INITIALISING SET AND DISTANCE
    vector<int>dist(V,INT_MAX);
    set<pair<int,int>>st;
    dist[src] = 0;
    // PUSHING INITIAL VALUES IN SET
    st.insert({0,src});
    // ITERATING SET
    while(!st.empty()){
        auto it = *(st.begin());
        st.erase(st.begin());
        int node = it.second;
        int distance = it.first;
        for(auto i:adj[node]){
            int goingtTo = i.first;
            int prevDist = i.second;
            // COMPUTING NEW DISTANCE
            if(prevDist+distance < dist[goingtTo]){
                // FIRST TIME FOUND
                if(dist[goingtTo]==INT_MAX){
                    dist[goingtTo] = prevDist+distance;
                }
                // ALREADY VISITED, DELETING THE LARGER DISTANCE FROM SET
                else{
                    st.erase({prevDist,goingtTo});
                    dist[goingtTo] = prevDist+distance;
                }
                // INSERTING BETTER DISTANCE
                st.insert({prevDist+distance,goingtTo});
            }
        }
    }
    return dist;
}

int main (){

}