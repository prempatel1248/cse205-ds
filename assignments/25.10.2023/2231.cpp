class Solution {
public:
    int largestInteger(int num) {
        vector<int> arr;
        vector<int> nums;
        priority_queue<int> even;
        priority_queue<int> odd;

        while(num!=0){
            nums.push_back(num%10);
            num = num/10;
        }
        reverse(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0){
                even.push(nums[i]);
            }
            else{
                odd.push(nums[i]);
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0){
                arr.push_back(even.top());
                even.pop();
            }
            else{
                arr.push_back(odd.top());
                odd.pop();
            }
        }
        int ans=0;
        for(int i=0; i<arr.size(); i++){
            ans = ans + (arr[i]* pow(10, arr.size()-i-1));
        }
        return ans;
    }
};