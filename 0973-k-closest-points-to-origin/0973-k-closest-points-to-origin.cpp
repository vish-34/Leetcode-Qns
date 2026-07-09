class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, pair<int,int>>> pq;

        for (auto &point : points) {

            int x = point[0];
            int y = point[1];

            int distance = x * x + y * y;

            pq.push({distance, {x, y}});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back({pq.top().second.first,
                           pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};