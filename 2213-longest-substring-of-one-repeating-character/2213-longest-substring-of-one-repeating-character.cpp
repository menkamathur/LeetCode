class Solution {
public:

    struct Node {
        int pre = 0;
        int suf = 0;
        int maxLen = 0;
        char leftChar = 0;
        char rightChar = 0;
    };

    int n;
    vector<Node> segTree;

    Node merge(const Node& L, const Node& R, int leftLen, int rightLen) {
        Node res;

        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        // Prefix
        res.pre = L.pre;

        if (L.pre == leftLen && L.rightChar == R.leftChar) {
            res.pre = L.pre + R.pre;
        }

        // Suffix
        res.suf = R.suf;

        if (R.suf == rightLen && L.rightChar == R.leftChar) {
            res.suf = R.suf + L.suf;
        }

        // Maximum length inside left or right segment
        res.maxLen = max(L.maxLen, R.maxLen);

        // Maximum length crossing the middle
        if (L.rightChar == R.leftChar) {
            res.maxLen = max(res.maxLen, L.suf + R.pre);
        }

        return res;
    }

    void buildSegmentTree(int i, int l, int r, const string& s) {

        if (l == r) {
            segTree[i] = {1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2 * i + 1, l, mid, s);
        buildSegmentTree(2 * i + 2, mid + 1, r, s);

        segTree[i] = merge(
            segTree[2 * i + 1],
            segTree[2 * i + 2],
            mid - l + 1,
            r - mid
        );
    }

    void update(int i, int l, int r, int pos, char ch) {

        if (l == r) {
            segTree[i] = {1, 1, 1, ch, ch};
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid) {
            update(2 * i + 1, l, mid, pos, ch);
        }
        else {
            update(2 * i + 2, mid + 1, r, pos, ch);
        }

        segTree[i] = merge(
            segTree[2 * i + 1],
            segTree[2 * i + 2],
            mid - l + 1,
            r - mid
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        n = s.size();

        segTree.assign(4 * n, Node());

        buildSegmentTree(0, 0, n - 1, s);

        int k = queryIndices.size();
        vector<int> result;

        for (int i = 0; i < k; i++) {

            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(0, 0, n - 1, pos, ch);

            result.push_back(segTree[0].maxLen);
        }

        return result;
    }
};