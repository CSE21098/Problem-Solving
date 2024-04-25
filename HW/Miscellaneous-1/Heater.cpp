class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters){
        heaters.push_back(INT_MAX) ;
        sort(houses.begin(),houses.end()) ;
        sort(heaters.begin(),heaters.end()) ;
        heaters.insert(heaters.begin(),INT_MAX) ;
        int min_radius = 0 ;
        int nextHeater = 1 ;
        for (auto house : houses){
            while (heaters[nextHeater] < house) nextHeater++ ;
            min_radius = max(min_radius , min(abs(house -(heaters[nextHeater-1])) , 
                                              abs((heaters[nextHeater]) - house))) ;
        }
        return min_radius ;
    }
};