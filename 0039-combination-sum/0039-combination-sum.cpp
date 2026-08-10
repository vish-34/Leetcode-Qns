class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;

    void backtrack(vector<int>& candidates, int idx, int remaining){
        if(remaining == 0)
        {
        ans.push_back(curr);
        return;

        }
    
        if(remaining < 0 || idx == candidates.size())
        return ;

        curr.push_back(candidates[idx]);
        backtrack(candidates, idx, remaining - candidates[idx]);
        curr.pop_back();
        backtrack(candidates, idx + 1, remaining);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, 0, target);
        return ans;
    }
};