#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row;
        unordered_set<char> col;
        unordered_set<char> box;

        // rows validation
        for (int i = 0; i < 9; i++ ) {
            row.clear();
            for (int j = 0; j < 9; j++) {
                char current = board[i][j];
                if (current == '.') continue;
                if (row.count(current)) return false;
                row.insert(current);
            }
        }

        // colums validation
        for (int i = 0; i < 9; i++) {
            col.clear();
            for (int j = 0; j < 9; j++) {
                char current = board[j][i];
                if (current == '.') continue;
                if (col.count(current)) return false;
                col.insert(current);
            }
        }

        // boxes validation
        for (int i = 0; i < 9; i +=3) {
            for (int j = 0; j < 9; j +=3) {
                box.clear();
                for (int r = i;r < i + 3; r++){
                    for (int c = j; c < j + 3; c++) {
                        char current = board[r][c];
                        if (current == '.') continue;
                        if (box.count(current)) return false;
                        box.insert(current);
                    }
                }
            }
        }

        return true;
    }
};
