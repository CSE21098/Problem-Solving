class Solution {
public:

    int solvetab(vector<int> &nums){
        int n = nums.size();
        long long int  prev2 =nums[0] ;
        long long int  prev1 = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            long long int incl = prev2 + nums[i];
            long long int exc = prev1;
            long long int ans = max(incl,exc);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }


    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        vector<int> first,second;
        for(int i=0;i<nums.size();i++){
            if(i != nums.size()-1){
                first.push_back(nums[i]);
            }
            if(i != 0){
                second.push_back(nums[i]);
            }
        }
        return max(solvetab(first),solvetab(second));
    }
};