class Solution {
public:
    typedef pair<long long, pair<long long, long long>> p;

    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                      int power, vector<int>& price, int src,
                                      int target) {
        unordered_map<long long, vector<pair<long long, long long>>> mp;

        for (vector<int> &x : edges) {
            mp[x[0]].push_back({x[1], x[2]});   // node, time
        }

        priority_queue<p> pq;

        vector<vector<long long>> dp(n + 1,
                                     vector<long long>(power + 1, LLONG_MAX));

        dp[src][0] = 0;
        pq.push({0, {0, src}});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            long long time = -it.first;
            long long cost = -it.second.first;
            long long node = it.second.second;

            if (node == target) {
                return {time, power - cost};
            }

            for (auto x : mp[node]) {
                long long nnode = x.first;
                long long ntime = time + x.second;
                long long ncost = cost + price[node];

                if (ncost > power)
                    continue;

                if (dp[nnode][ncost] > ntime) {
                    dp[nnode][ncost] = ntime;
                    pq.push({-ntime, {-ncost, nnode}});
                }
            }
        }

        return {-1, -1};
    }
};