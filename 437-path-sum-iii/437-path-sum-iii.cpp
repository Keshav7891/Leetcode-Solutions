class Solution {
public:
    int ans=0;
    unordered_map<int,int> map;
	
    int pathSum(TreeNode* root,int sum) {
        if(!root) return 0;
        
        map[0] = 1;
        dfs(root,sum,0);
        
        return ans;
    }
    
	/** long int -> because of int overflow problem. */
    void dfs(TreeNode* root,int target,long int cur_sum){
        if(!root) return;
        
        cur_sum += root->val;
        
        if(map.find(cur_sum-target) != map.end())
            ans += map[cur_sum-target];
        
        map[cur_sum]++;
        dfs(root->left,target,cur_sum);
        dfs(root->right,target,cur_sum);
        map[cur_sum]--;
        
    }
};