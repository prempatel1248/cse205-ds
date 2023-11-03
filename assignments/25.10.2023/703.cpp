class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int largest;
public:
    KthLargest(int k, vector<int>& nums) {
        largest = k;
        int len = nums.size();
        for(int i=0; i<len; i++){
            pq.push(nums[i]);
        }
        for(int i=0; i<len-largest; i++){
            pq.pop();
        }
    }
    
    int add(int val) {
        if(pq.empty()){
            pq.push(val);
            return pq.top();
        }
        else if(pq.top()>val && pq.size()<largest){
            pq.push(val);
            return pq.top();
        }
        else if(pq.top()>val){
            return pq.top();
        }
        else if(pq.top()<=val && pq.size()<largest){
            pq.push(val);
            return pq.top();
        }
        else{
            pq.pop();
            pq.push(val);
            return pq.top();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */