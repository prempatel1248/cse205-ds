class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        int ans;
        for(int i=0; i<stones.size(); i++){
           p.push(stones[i]);
        }
        if(stones.size()==1){
            return stones[0];
        }
        while(!p.empty()){
            if(p.size()==1){
                break;
            }
            int x = p.top();
            p.pop();
            int y = p.top();
            p.pop();
            if(x>y){
                p.push(x-y);
                ans = x-y;
            }
            else if(x<y){
                p.push(y-x);
                ans = y-x;
            }
            else if(x==y){
                ans = 0;
                p.push(0);
            }
            
        }
        return ans; 

    }
};