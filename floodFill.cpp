// https://leetcode.com/problems/flood-fill/submissions/
class Solution {
public:
    void helper(vector<vector<int>>& image, int initialColor, int i, int j,  int newColor){
         if( i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != initialColor || image[i][j] == newColor ) return;

         image[i][j] = newColor;
        
        helper(image, initialColor, i - 1, j    , newColor);
        helper(image, initialColor, i + 1, j    , newColor);
        helper(image, initialColor, i    , j - 1, newColor);
        helper(image, initialColor, i    , j + 1, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialColor = image[sr][sc];
        helper(image, initialColor,  sr,  sc,  newColor);
        return image;
    }
};