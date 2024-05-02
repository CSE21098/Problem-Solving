class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int swaps = 0;
        for (int i = 0; i < row.size(); i += 2) {
            int partner = row[i] ^ 1;
            int partnerIndex = -1;
            if(row[i+1]==partner) continue;
            for (int j =0; j < row.size(); j++) {
                if (row[j] == partner) {
                    partnerIndex = j;
                    break;
                }
            }
            if (partnerIndex != -1) { 
                swap(row[i + 1], row[partnerIndex]); 
                swaps++; 
            }
        }
        return swaps; 
    }
};