class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> row(9),col(9);
        vector<vector<set<char>>> box(3,vector<set<char>>(3));
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(board[i][j]!='.')
                {
                    if(row[i].find(board[i][j])==row[i].end())
                    {
                        row[i].insert(board[i][j]);
                    }
                    else return false;
                    
                    if(col[j].find(board[i][j])==col[j].end())
                    {
                        col[j].insert(board[i][j]);
                    }
                    else return false;

                    if(box[i/3][j/3].find(board[i][j])==box[i/3][j/3].end())
                    {
                        box[i/3][j/3].insert(board[i][j]);
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};