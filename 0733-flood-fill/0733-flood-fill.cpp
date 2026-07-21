class Solution {
private:
    void dfs(vector<vector<int>>&image,int sr,int sc,int color,int parent){
        if(image[sr][sc] == color){return;}
        image[sr][sc] = color;
        int dir[] = {-1,0,1,0,-1};
        for(int i = 1; i <= 4; i++){
            int nrow = sr + dir[i-1];
            int ncol = sc + dir[i];
            if(nrow < image.size() && nrow >= 0 && ncol < image[0].size() && ncol >=0 && image[nrow][ncol] == parent){
                dfs(image,nrow,ncol,color,parent);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int parent = image[sr][sc];
       dfs(image,sr,sc,color,parent);
       return image;
    }
};