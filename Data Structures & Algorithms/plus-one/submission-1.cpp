class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]!=9){
            digits[n-1]+=1;
            return digits;
        }

        if(n==count(digits.begin(),digits.end(),9)){
            digits.push_back(0);
            digits[0]=1;
            for(int i=1;i<n;i++){
                digits[i]=0;
            }
            return digits;
        }
        for(int i=n-1;i>=0;i--){
            if(digits[i]!=9){
                digits[i]+=1;
                return digits;
            }
            else{
                digits[i]=0;
            }
        }
        return {};
    }
};
