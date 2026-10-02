class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        function<void(int, int, string)> dfs =
            [&](int left, int right, string s) {
                if (s.size() == n * 2) {
                    result.push_back(s);
                    return;
                }

                if (left < n) {
                    dfs(left + 1, right, s + '(');
                }

                if (right < left) {
                    dfs(left, right + 1, s + ')');
                }
            };

        dfs(0, 0, "");
        return result;
    }
};