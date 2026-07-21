class Solution {
private:
    void dfs(vector<vector<int>>&image,vector<vector<int>>&vis,int &sr,int &sc,int &color,int &parent){

        image[sr][sc] = color;
        vis[sr][sc] = 1;
        int dir[] = {-1,0,1,0,-1};
        for(int i = 1; i <= 4; i++){
            int nrow = sr + dir[i-1];
            int ncol = sc + dir[i];
            if(nrow < image.size() && nrow >= 0 && ncol < image[0].size() && ncol >=0 && image[nrow][ncol] == parent && !vis[nrow][ncol]){
                dfs(image,vis,nrow,ncol,color,parent);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int parent = image[sr][sc];
       vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
       dfs(image,vis,sr,sc,color,parent);
       return image;
    }
};