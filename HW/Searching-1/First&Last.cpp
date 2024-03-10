int low(vector<int>&nums,int target){
        int beg=0;
        int end=nums.size()-1;

        int ans=-1;

        int mid=beg+(end-beg)/2;
        while(beg<=end){
            if(target==nums[mid]){
                ans=mid;
                end=mid-1;
            }
            else if(target<nums[mid]){
                end=mid-1;
            }
            else{
                beg=mid+1;
            }
            mid=beg+(end-beg)/2;
        }
        return ans;
    }
    int upr(vector<int>&nums,int target){
        int beg=0;
        int end=nums.size()-1;

        int ans=-1;

        int mid=beg+(end-beg)/2;
        while(beg<=end){
            if(target==nums[mid]){
                ans=mid;
                beg=mid+1;
            }
            else if(target<nums[mid]){
                end=mid-1;
            }
            else{
                beg=mid+1;
            }
            mid=beg+(end-beg)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {low(nums,target),upr(nums,target)};
    }