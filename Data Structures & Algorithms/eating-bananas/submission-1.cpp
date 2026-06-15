#define sum for  

class Solution {
public:
    int check(int speed, vector<int> & piles) {
        int time = 0;
        for (auto m : piles) {
            time  += ((m + speed -1 )/ speed );
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxSpeed = *max_element(piles.begin(),piles.end());
        int minSpeed = 1;
        while (minSpeed < maxSpeed) {
            int mid = minSpeed + (maxSpeed - minSpeed) / 2;
            if (check(mid,piles) <= h) maxSpeed = mid;
            else minSpeed = mid+1;
        }
        return minSpeed;
    }
};
