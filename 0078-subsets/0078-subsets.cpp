class Solution {
public:
    vector<vector<int>>result;
    vector<int>path;
      void backtrack(int start, vector<int>& nums) {
        result.push_back(path);

        for(int i =start; i < nums.size();  i++){
            path.push_back(nums[i]);
            backtrack(i+1, nums);
            path.pop_back();
        }
      }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0,nums);
        return result;
    }
};