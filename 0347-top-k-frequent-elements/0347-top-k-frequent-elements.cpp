class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }
        vector<pair<int,int>> freqNums;
        for(auto pair:freq){
            freqNums.push_back(pair);
        }
        sort(freqNums.begin(), freqNums.end(), [](pair<int,int> & a, pair<int,int> & b){
            return a.second > b.second;
        });
        vector <int> result;
        for(int i = 0; i < k; i++){
            result.push_back(freqNums[i].first);
        }
        return result;
    }
};