class Solution {
public:
void check(vector<vector<char>>& board,string word, vector<vector<int>>& vis,int x,int y,int i,bool & res)
{
    if(res==true)
    {
        return;
    }
    if(i==word.size())
    {
        res=true;
        return;
    }
    if((x>-1 && x<board.size()) && (y>-1 && y<board[0].size()) && board[x][y]==word[i] && vis[x][y]==false)
    {
        vis[x][y]=true;
        check(board,word,vis,x+1,y,i+1,res);
        check(board,word,vis,x-1,y,i+1,res);
        check(board,word,vis,x,y+1,i+1,res);
        check(board,word,vis,x,y-1,i+1,res);
        vis[x][y]=false;
    }
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        bool res=false;
        vector<vector<int>> vis(n,vector<int>(m,false));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                
                if(board[i][j]==word[0])
                {
                    check(board,word,vis,i,j,0,res);
                }
                if(res==true)
                {
                    break;
                }
            }
            if(res==true)
                {
                    break;
                }
            
        }
        return res;

    }
};