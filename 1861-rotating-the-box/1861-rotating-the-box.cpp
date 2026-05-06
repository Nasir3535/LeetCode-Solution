class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int cols = box[0].size();
      
        vector<vector<char>> rotatedBox(cols, vector<char>(rows));
      
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                rotatedBox[col][rows - row - 1] = box[row][col];
            }
        }
      
        for (int col = 0; col < rows; ++col) {
            queue<int> emptyPositions;  
            for (int row = cols - 1; row >= 0; --row) {
                if (rotatedBox[row][col] == '*') {
                   
                    queue<int> newQueue;
                    swap(emptyPositions, newQueue);
                } 
                else if (rotatedBox[row][col] == '.') {
                    emptyPositions.push(row);
                } 
                else if (rotatedBox[row][col] == '#' && !emptyPositions.empty()) {
                    int targetRow = emptyPositions.front();
                    emptyPositions.pop();
                  
                    rotatedBox[targetRow][col] = '#';
                    rotatedBox[row][col] = '.';        
                    emptyPositions.push(row);          
                }
            }
        }
      
        return rotatedBox;
    }
};