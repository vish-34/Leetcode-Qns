class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(vector<int>& candidates, int start, int target) {

        // Found a valid combination
        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {

            // Skip duplicate choices at the same level
            if(i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since sorted, no later number can work either
            if(candidates[i] > target)
                break;

            // Choose
            curr.push_back(candidates[i]);

            // Move forward: element cannot be reused
            backtrack(candidates, i + 1, target - candidates[i]);

            // Undo
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, 0, target);

        return ans;
    }
};