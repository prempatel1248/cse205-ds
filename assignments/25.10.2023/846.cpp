class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        else{
            priority_queue<int, vector<int>, greater<int>> pq;
            for(int i=0; i<hand.size(); i++){
                pq.push(hand[i]);
            }
            while(!pq.empty()){
                vector<int> temp;
                for(int i=0; i<groupSize-1; i++){
                    int a = pq.top();
                    pq.pop();
                    if(pq.top()==a){
                        while(pq.top()==a && !pq.empty()){
                            pq.pop();
                            temp.push_back(a);
                        }
                    }
                    if(pq.top()-a != 1){
                        return false;
                    }
                }
                pq.pop();
                for(int i=0; i<temp.size(); i++){
                    pq.push(temp[i]);
                }
                temp.clear();
            }
            return true;
        }
    }
};