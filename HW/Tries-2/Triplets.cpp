class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int i, j, x_or, count=0;

        for(i=0 ; i<arr.size() ; i++)
        {
            x_or=0;
            for(j=i ; j<arr.size() ; j++)
            {
                x_or ^= arr[j];
                if(x_or==0)
                {
                    count += (j-i);
                }
            }
        }
        return count;
    }
};