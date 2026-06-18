class Solution {
public:
    double angleClock(int hour, int minutes) {
        int hr=(hour+12)%12;
        double temp=abs(60*hr-11*minutes)/2.0;
        return min(temp,360-temp);
    }
};