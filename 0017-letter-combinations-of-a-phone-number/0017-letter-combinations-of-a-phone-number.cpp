class Solution {
public:
 vector<string>ans;
        string curr;

         vector<string> letters = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack (string& digits, int idx){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }

        string possible = letters[digits[idx]  - '0'];
        for(char ch : possible){
            curr.push_back(ch);
            backtrack(digits, idx + 1);
            curr.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
       if(digits.empty())
       return {};

       backtrack(digits, 0);
       return ans;
    }
};