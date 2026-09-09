class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0, rightSum = 0, maxSum = 0;
        for(int i = 0; i < k; i++){
            leftSum = leftSum + cardPoints[i];
            maxSum = leftSum;
        }
        int j = n-1;
        for(int i = k-1; i >= 0; i--){
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[j];
           j = j-1;
            maxSum = max(maxSum, leftSum+rightSum);

        }
        return maxSum;
        

    }
};