class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> pos;
        vector<int> digit;

        // Store positions and values of all non-zero digits
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int k = digit.size();

        // powers of 10
        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // prefix concatenated value
        vector<long long> prefVal(k + 1, 0);
        // prefix digit sum
        vector<long long> prefSum(k + 1, 0);

        for (int i = 0; i < k; i++) {
            prefVal[i + 1] = (prefVal[i] * 10 + digit[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digit[i];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int L = q[0], R = q[1];

            int l = lower_bound(pos.begin(), pos.end(), L) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), R) - pos.begin() - 1;

            if (l > r) {
                ans.push_back(0);
                continue;
            }

            int len = r - l + 1;

            long long x =
                (prefVal[r + 1] - prefVal[l] * pow10[len]) % MOD;
            if (x < 0) x += MOD;

            long long sum = prefSum[r + 1] - prefSum[l];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};