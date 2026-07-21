#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int cnt = 0;
        for(int i = 0 ;i< row;i++){
            for(int j= 0; j<col;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
                if(grid[i][j] == 1){
                    // fresh oranges
                    cnt++;
                }
            }
        }
        int timer = 0;
        int cntFresh = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();
            timer = max(timer,step);
            int dir[] = {-1,0,1,0,-1};
            for(int i=1; i <= 4;i++){
                int nrow = r + dir[i-1];
                int ncol = c + dir[i];
                if(nrow >= 0 && nrow < row && ncol >=0 && ncol < col && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},step+1});
                    grid[nrow][ncol] = 2;
                    cntFresh++;
                }
            }
        }
        if(cnt != cntFresh){
            return -1;
        }
        return timer;
    }   
};