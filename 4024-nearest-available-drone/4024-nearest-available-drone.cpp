class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int idx=-1,dis=INT_MAX;
        for(int i=0;i<drones.size();i++){
            if(abs(target[0]-drones[i][0])+abs(target[1]-drones[i][1])<=drones[i][2]&&abs(target[0]-drones[i][0])+abs(target[1]-drones[i][1])<dis){
                idx=i;
                dis=abs(target[0]-drones[i][0])+abs(target[1]-drones[i][1]);
            }
        }
        return idx;
    }
};