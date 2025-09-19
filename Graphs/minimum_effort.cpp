#include<bits/stdc++.h>
using namespace std; 

// LOGIC

/*
    -> WE WILL BE USING DIJKSTRA'S ALGO AS WE NEED TO FIND KINDA MIN PATH
    -> WE WILL KEEP TRACK OF MAX DIST IN THE PATH
    -> WE WILL ITERATE ALL THE POSSIBLE DIRECTIONG AND IF THE MAX OF PREV PATH
         AND CURRENT EFFORT IS SMALLER IN THE DIST VECTOR, WE WILL PUSH IN PQ AND UPDATE THE DIST VECTOR
    -> WE WILL END THE ITERATION WHEN THE DESTINATION IS POPPED OUT OF PQ
    -> THIS WILL HAPPEN SO, CUZ EVEN IF WE VISIT IT LATER, IT WILL HAVE MINIMUM PATH OF 2,
         NOTHING CAN BE SMALLER THAN IT.
*/


int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size(), m = heights[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>>pq;

    if(n==1 && m==1)return 0;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    // INITIALISING PQ AND DIST VECTOR
    vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
    pq.push({0,{0,0}});
    distance[0][0] = 0;
    int maxi = 0;
    // ITERATING PQ
    while(!pq.empty()){
        int dist = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        // DISTINATION IS POPPED OUT, RETURN DIST.
        if(x==n-1 && y==m-1) return dist;
        for(int i = 0; i<4; i++){
            int newx = dx[i] + x;
            int newy = dy[i] + y;
            if(newx >= 0 && newx < n && newy >= 0 && newy < m){
                int diff = abs(heights[x][y]-heights[newx][newy]);
                // DIFF WILL ALWAYS BE MAX OF PATH AND DIFF B/W HEIGHTS
                diff = max(dist,diff);
                // IF DIFF IS MIN THAN PREV, PUSHING IN PQ AND UPDATING DIST
                if(distance[newx][newy]>diff){
                    distance[newx][newy] = diff;
                    pq.push({diff,{newx,newy}});
                }
            }
        }
    }
    // IF NOT POSSIBLE TO REACH DESTINATION(WHICH WON'T HAPPEN).
    return -1;
}

int main (){
    
}
