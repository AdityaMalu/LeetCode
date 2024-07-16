class Solution {
public:

    void dfs(vector<vector<int>> &img, int row,int col,int color,int og){
        if(row < 0 || col < 0 || row>=img.size() || col>=img[0].size()){
            return;
        }

        if(img[row][col] != color && img[row][col] ==og){
            img[row][col] = color;
            dfs(img,row+1,col,color,og);
            dfs(img,row,col+1,color,og);
            dfs(img,row-1,col,color,og);
            dfs(img,row,col-1,color,og);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};