class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a;
        double  b=minutes;
        if(hour==12){
           a=b/12;
        }else {
            a=hour*5+(b/12);
        }
        double ans=abs(a*6-b*6);
        ans=min(ans,(360-ans));
        return ans;

        
    }
};
