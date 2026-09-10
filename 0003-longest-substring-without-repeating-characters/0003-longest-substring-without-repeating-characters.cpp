class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
       int maxLen = 0;
        for(int i = 0; i < n; i++){
           int hash[250] = {0};
        
        for(int j = i; j < n; j++){
            if(hash[s[j]] == 1) break;
            hash[s[j]] = 1;
            int len = j-i+1;
            maxLen = max(len, maxLen);
        }
        }
        return maxLen;
        
        
    }
};