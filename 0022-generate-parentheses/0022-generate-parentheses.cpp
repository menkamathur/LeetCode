class Solution {
public:
    void generateParenthesesHelper(int n, string current, int open, int close, vector<string>& result) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            generateParenthesesHelper(n, current + "(", open + 1, close, result);
        }

        if (close < open) {
            generateParenthesesHelper(n, current + ")", open, close + 1, result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesesHelper(n, "", 0, 0, result);
        return result;
    }
};