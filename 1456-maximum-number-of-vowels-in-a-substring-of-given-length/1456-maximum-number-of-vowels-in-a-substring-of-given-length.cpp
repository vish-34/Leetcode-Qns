class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int vowelCount = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                vowelCount++;
            }
        }

        int ans = vowelCount;
        
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i])) {
                vowelCount++;
            }
            if (isVowel(s[i - k])) {
                vowelCount--;
            }

            ans = max(ans, vowelCount);
        }

        return ans;
    }
};