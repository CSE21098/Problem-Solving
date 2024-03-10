int findPeakElement(vector<int>& nums) {
        int low=0;
        int high=nums.size();
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if((mid==0||nums[mid-1]<=nums[mid]) && (mid==nums.size()-1||nums[mid+1]<=nums[mid]))
                break;
            if(mid>0 && nums[mid-1]>nums[mid])
                high=mid-1;
            else
                low=mid+1;
        }
     return mid;
 }