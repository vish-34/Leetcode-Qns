class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set < int > window;

        int left = 0;
        int longest = 0;

        for (int right = 0; right < s.size(); right++ ){
            while ( window.count(s[right])){
                window.erase(s[left]);
                left ++;
            }
            window.insert(s[right]);
        longest = max(longest, right - left + 1);
        }

    return longest;
    }
};