class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long m=1ll*mass;
        for(int i=0;i<asteroids.size();i++){
             if(m<1ll*asteroids[i]){
                return false;
             }
             m+=1ll*asteroids[i];
        }
        return true;    

    }
};