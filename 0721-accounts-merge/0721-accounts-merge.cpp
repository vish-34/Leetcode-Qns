class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false;

        if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, int> emailToId;
        unordered_map<string, string> emailToName;

        int id = 0;

        // Give every email a unique id
        for (auto &account : accounts) {
            string name = account[0];

            for (int i = 1; i < account.size(); i++) {
                string email = account[i];

                if (!emailToId.count(email)) {
                    emailToId[email] = id++;
                }

                emailToName[email] = name;
            }
        }

        parent.resize(id);
        rank.resize(id, 0);

        for (int i = 0; i < id; i++) {
            parent[i] = i;
        }

        // Union all emails in the same account
        for (auto &account : accounts) {
            int firstEmail = emailToId[account[1]];

            for (int i = 2; i < account.size(); i++) {
                Union(firstEmail, emailToId[account[i]]);
            }
        }

        unordered_map<int, vector<string>> groups;

        for (auto &it : emailToId) {
            string email = it.first;
            int idx = it.second;

            int root = find(idx);

            groups[root].push_back(email);
        }

        vector<vector<string>> ans;

        for (auto &group : groups) {

            vector<string> emails = group.second;

            sort(emails.begin(), emails.end());

            vector<string> account;

            account.push_back(emailToName[emails[0]]);

            for (auto &email : emails)
                account.push_back(email);

            ans.push_back(account);
        }

        return ans;
    }
};