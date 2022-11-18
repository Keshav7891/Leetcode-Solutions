//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
   bool dfs(int i,int j,int index,vector<vector<char>>& board,string word,int row,int col,vector<vector<int>>& vis) {
        if(index==word.length()) return true;
        
        if(i<0||j<0||i>=row||j>=col) return false;
        if(board[i][j]!=word[index]) return false;
        if(vis[i][j]) return false;
        
        vis[i][j]=1;
        
        for(int k=0;k<4;k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(dfs(ni,nj,index+1,board,word,row,col,vis)) return true;
        }
        vis[i][j]=0;
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(board[i][j]==word[0] && dfs(i,j,0,board,word,row,col,vis)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends