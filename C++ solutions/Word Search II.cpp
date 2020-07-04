class Trie{
public:
    Trie* children[26];
    bool endofword;
    Trie(){
        endofword=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
    ~Trie(){
        for(int i=0;i<26;i++)
            if(children[i]) 
                delete children[i];
    }
    void insert(string word){
        Trie* curr=this;
        for(char c:word){
            if(curr->children[c - 'a']==NULL)
                curr->children[c-'a']=new Trie();
            curr=curr->children[c-'a'];
        }
        curr->endofword=true;
    }
};
class Solution {
     unordered_set<string>result;
     vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
public:
    void dfs(int i,int j,vector<vector<char>>&b,Trie* trie,string s)
    {
        char c=b[i][j]; 
        
        if(c=='$')
            return;
        b[i][j]='$';
        Trie* t=trie->children[c-'a'];
        
        if(t){
            string ss=s+c;
            if(t->endofword)
                result.insert(ss);
            for(auto x:dir)
                if( i+x[0]>=0 && i+x[0]<b.size() && j+x[1]>=0 && j+x[1]<b[0].size() )
                    dfs(i+x[0],j+x[1],b,t,ss);
                 
        }
        b[i][j]=c;  
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        if(words.size()==0 )
            return {};
        Trie trie;
        for(string s: words)
            trie.insert(s);
       
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
               dfs(i,j,board,&trie,"");
            }
        }
        vector<string>results(result.begin(),result.end());
        return results;
    }
};
