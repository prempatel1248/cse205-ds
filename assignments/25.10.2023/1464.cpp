class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>p;
        for(int i=0; i<nums.size(); i++){
            p.push(nums[i]);
        }
        int x = p.top();
        p.pop();
        int y = p.top();
        return (x-1)*(y-1);
    }
};