class Solution {
    vector<vector<char>>b;
    vector<vector<char>>Board;
    int m,n;
    vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
public:
    void fill(int i ,int j)
    {
        
        for(auto x:dir){
            if(i+x[0]>=0 && i+x[0]<m && j+x[1]>=0 && j+x[1]<n && Board[i+x[0]][j+x[1]]=='O'&& b[i+x[0]][j+x[1]]=='X'){
                b[i+x[0]][j+x[1]]='O'; 
                fill(i+x[0],j+x[1]);
            }
        }
          
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        Board=board;
        m= board.size();
        n=board[0].size();
        int i,j;
        b=vector<vector<char>>(m,vector<char>(n,'X'));
        for(i=0,j=0;j<n;j++){
           if(board[i][j]=='O'){
               b[i][j]='O';
                fill(i,j);
           }
        }   
        for(i=0,j=0;i<m;i++){
            if(board[i][j]=='O'){
                 b[i][j]='O';
                fill(i,j);
           }
        }
        for(i=m-1,j=n-1;i>=0;i--){
            if(board[i][j]=='O'){
                 b[i][j]='O';
                 fill(i,j);
           }
        } 
        for(i=m-1,j=n-1;j>=0;j--){
            if(board[i][j]=='O'){
                 b[i][j]='O';
                 fill(i,j);
           }
        }
        board=b;
        
    }
};
