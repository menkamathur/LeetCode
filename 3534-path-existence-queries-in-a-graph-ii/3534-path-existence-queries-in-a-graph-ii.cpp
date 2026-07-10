class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int,int>> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> pos(n);
        vector<int> comp(n);

        // position of each original node in sorted order
        for (int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        // connected components
        int cid = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first > maxDiff)
                cid++;
            comp[i] = cid;
        }

        // next reachable position
        vector<int> nxt(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r + 1 < n &&
                   arr[r + 1].first - arr[i].first <= maxDiff)
                r++;
            nxt[i] = r;
            if (r == i) r = i;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = nxt;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (u > v) swap(u, v);

            // different connected components
            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            int cur = u;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < v) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            steps++;   // final jump reaches or passes v
            ans.push_back(steps);
        }

        return ans;
    }
};