class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int requireddays = 1;
        int currentweight = 0;
        for (int weight : weights){
            if (currentweight + weight <= capacity){
                currentweight += weight;
            }else{
                requireddays++;
                currentweight = weight;
            }
           
        }
         return requireddays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while(left < right){
            int mid = left + (right - left) / 2;
            if(canShip(weights, days, mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
       
        }
             return left;
    }
};