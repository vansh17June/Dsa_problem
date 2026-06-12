class Solution {
public:
    int n;
    vector<int>temp1,temp2;
    void buildmaxtree(int i,int start,int end,vector<int>&nums){
        if(start==end){
            temp1[i]=nums[start];
            return;
        }else if(start>end){
            temp1[i]=INT_MIN;
            return;
        }
        int mid=start+(end-start)/2;
        buildmaxtree(2*i+1,start,mid,nums);
        buildmaxtree(2*i+2,mid+1,end,nums);
        temp1[i]=max(temp1[2*i+1],temp1[2*i+2]);
        
    }
    void buildmintree(int i,int start,int end,vector<int>&nums){
        if(start==end){
            temp2[i]=nums[start];
            return;
        }else if(start>end){
            temp2[i]=INT_MAX;
            return;
        }
        int mid=start+(end-start)/2;
        buildmintree(2*i+1,start,mid,nums);
        buildmintree(2*i+2,mid+1,end,nums);
        temp2[i]=min(temp2[2*i+1],temp2[2*i+2]);
        
    }
    int getmax(int i,int start,int end,int l,int r){
        if(l>end||r<start){
            return INT_MIN;
        }
        if(start>=l&&end<=r){
            return temp1[i];
        }
        int mid=start+(end-start)/2;
        int left=getmax(2*i+1,start,mid,l,r);
        int right=getmax(2*i+2,mid+1,end,l,r);
        return max(left,right);

    }
     int getmin(int i,int start,int end,int l,int r){
        if(l>end||r<start){
            return INT_MAX;
        }
        if(start>=l&&end<=r){
            return temp2[i];
        }
        int mid=start+(end-start)/2;
        int left=getmin(2*i+1,start,mid,l,r);
        int right=getmin(2*i+2,mid+1,end,l,r);
        return min(left,right);

    }
    long long maxTotalValue(vector<int>& nums, int k) {
    n=nums.size();
    temp1.resize(4*n),temp2.resize(4*n);
    buildmaxtree(0,0,n-1,nums);
    buildmintree(0,0,n-1,nums);
    priority_queue<pair<int,pair<int,int>>>pq;
    for(int i=0;i<n;i++){
       int maxVal=getmax(0,0,n-1,i,n-1);
       int minVal=getmin(0,0,n-1,i,n-1);
       pq.push({(maxVal-minVal),{i,n-1}});
    }
    long long ans=0;
    while(k--&&!pq.empty()){
       auto temp=pq.top();
       pq.pop();
       int val=temp.first,l=temp.second.first,r=temp.second.second;
       ans+=1ll*val;
       if(l!=r){
       int score=getmax(0,0,n-1,l,r-1)-getmin(0,0,n-1,l,r-1);
       pq.push({score,{l,r-1}});
       }
    }
    return ans;
    }
};