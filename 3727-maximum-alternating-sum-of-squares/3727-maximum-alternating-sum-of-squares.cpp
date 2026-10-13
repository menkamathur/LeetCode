class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> v(n,0);
        for(int i=0;i<n;i++){
            v[i]=(nums[i]*nums[i]);
        }
        sort(v.begin(),v.end());
        long long sc=0;
        for(int i=n/2;i<n;i++){
            sc+=v[i];
        }
        for(int i=0;i<n/2;i++){
            sc-=v[i];
        }
        return sc;
    }
};