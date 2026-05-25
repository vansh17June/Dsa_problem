class NumArray {
public:
    vector<int>nums;
    vector<int>segment_tree;
    int size;
    NumArray(vector<int>& nums) {
        this->nums=nums;
        this->size=nums.size();
       segment_tree.assign(4 * size, 0);

        buildSegmentTree(0,nums.size()-1,0);
    }
    void  buildSegmentTree(int l,int r,int idx){
        if(l==r){
            segment_tree[idx]=nums[l];
            return;
        }
        if(l>r){
            return;
        }
        int mid=(l+r)/2;
        buildSegmentTree(l,mid,2*idx+1);
        buildSegmentTree(mid+1,r,2*idx+2);
        segment_tree[idx]=segment_tree[2*idx+1]+segment_tree[2*idx+2];
    }
    
    
    void update_tree(int index, int val,int l,int r,int idx) {
        if(l==r&&l==index){
            segment_tree[idx]=val;
            return ;
        }
        if(l>=r){
            return ;
        }
        int mid=(l+r)/2;
        if(index<=mid){
            update_tree(index,val,l,mid,2*idx+1);
        }else{
            update_tree(index,val,mid+1,r,2*idx+2);
        }
        segment_tree[idx]=segment_tree[2*idx+1]+segment_tree[2*idx+2];
        

          
    }
    void update(int index,int val){
        update_tree(index,val,0,size-1,0);
    }
    int solve(int left,int right,int s,int e,int idx){
        if(s>right||e<left){
            return 0;
        }
        if(left<=s&&e<=right){
            return segment_tree[idx];
        }
        int mid=(s+e)/2;
        return solve(left,right,s,mid,2*idx+1)+solve(left,right,mid+1,e,2*idx+2);
    }
    int sumRange(int left, int right) {
        return solve(left,right,0,nums.size()-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */