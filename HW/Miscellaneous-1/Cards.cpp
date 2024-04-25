class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum1=0,sum2=0;
        int i=0,j=cardPoints.size()-1;
        int a=j-k;
        for(i=0;i<k;i++){
            sum1 += cardPoints[i];
        }
        sum2=sum1;
        i=k-1;
        while(i>=0 && j>a){
            sum2=sum2 + cardPoints[j] - cardPoints[i];
            sum1=max(sum2,sum1);
            i--;
            j--;
        }
        return sum1;
    }
};