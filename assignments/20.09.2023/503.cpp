class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        
        for(int i = 2*n-1; i >= 0; i--) {
            while(!s.empty() && s.top() <= nums[i%n]) s.pop();
            int temp = nums[i%n];
            if(s.empty()) {
                if(i < n) nums[i] = -1;
            }
            else {
                if(i < n) nums[i] = s.top();
            }
            s.push(temp);
        }
        return nums;
    }
};