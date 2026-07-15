class Solution {
private:
    void dfs(vector<vector<int>>&vis,vector<vector<int>>&image,int sr,int sc,int color,int iniColor){
        if(image[sr][sc] == iniColor){
            image[sr][sc] = color;
        }
        vis[sr][sc] = 1;
        vector<int> dirRow = {-1,0,1,0};
        vector<int> dirCol = {0,-1,0,1};
        for(int step = 0; step < 4;step++){
            int nRow = sr + dirRow[step];
            int nCol = sc + dirCol[step];
            if(nRow >= 0 && nRow <image.size() && nCol >=0 && nCol < image[0].size() && !vis[nRow][nCol] && image[nRow][nCol] == iniColor){
                image[nRow][nCol] = color;
                dfs(vis,image,nRow,nCol,color,iniColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> vis(image.size(),vector<int>(image[0].size(),0));
        dfs(vis,image,sr,sc,color,iniColor);
        return image;
    }
};