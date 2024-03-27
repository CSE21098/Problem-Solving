class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int s=0,l=row*col-1;
        int mid = s+(l-s)/2;
        while(s<=l){
            int ele=matrix[mid/col][mid%col];
            if(ele==target){
                return true;
            }
            else if(ele<target){
                s=mid+1;
            }
            else{
                l=mid-1;
            }
            mid = s+(l-s)/2;
        }
        return false;
    }
};