class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;

    bool isPalindrome(string& s, int left, int right) {

        while(left < right) {

            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void backtrack(string& s, int start) {

        // Entire string has been partitioned
        if(start == s.size()) {
            ans.push_back(curr);
            return;
        }

        // Try every possible substring starting at start
        for(int i = start; i < s.size(); i++) {

            // Only choose palindromes
            if(!isPalindrome(s, start, i))
                continue;

            // Choose
            curr.push_back(s.substr(start, i - start + 1));

            // Move to the remaining part
            backtrack(s, i + 1);

            // Undo
            curr.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {

        backtrack(s, 0);

        return ans;
    }
};