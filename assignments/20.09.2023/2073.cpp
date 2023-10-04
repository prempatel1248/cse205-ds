class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        queue<int> q;
        for(int i=0; i<tickets.size(); i++){
            q.push(tickets[i]);
        }
        int i = k;
        while(q.front()!=1 || i!=0){
            if(q.front() == 0){
                q.pop();
                i--;
            }
            else{
                q.push(q.front()-1);
                q.pop();
                if(i==0){
                    i = q.size()-1;
                }
                else{
                    i--;
                }
                time++;
            }
        }
        time++;
        return time;
    }
};