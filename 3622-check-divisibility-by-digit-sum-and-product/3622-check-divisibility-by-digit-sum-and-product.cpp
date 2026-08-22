class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int original = n;
        while(n>0){
        int lastDigit = n%10;
        n = n/10; 
        sum = sum+lastDigit;
        prod = prod*lastDigit;
        }

         return original % (sum + prod) == 0; 

    }
};