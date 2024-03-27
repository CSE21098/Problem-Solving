double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int beg = 0, end = nums1.size();
        int mid = (nums1.size() + nums2.size() + 1) / 2;
        while (beg <= end)
        {
            int mid1 = (beg+end)>>1;
            int mid2 = mid - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1-1 >= 0){
                l1 = nums1[mid - 1];
            }
            if (mid2-1 >=0){
                l2 = nums2[mid2 - 1];
            }
            if(mid1<nums1.size()){
                r1 = nums1[mid1];
            } 
            if(mid2<nums2.size()){
                r2 = nums2[mid2];
            } 
            if(l1<=r2 && l2<=r1)
            {
                if((nums1.size()+nums2.size())%2==1){
                    return max(l1,l2);
                }
                return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
            }
            else if(l1>r2)
            {
                high = mid1-1;
            }
            else
            {
                low = mid1+1;
            }
        }
        return 0;
    }