int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        while(low<high){
	    mid=low + (high-low)/2;
            if(nums[low]<=nums[high])
                {
                    return nums[low]; 
                }  
                    
            
            if(nums[low] > nums[mid]){
                high=mid;
            }
            else if(nums[mid] > nums[high]){
                low=mid+1;
            }
        }
        if(nums[low]<=nums[high])
            return nums[low];
        return -1;
    }