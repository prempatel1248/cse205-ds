class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;
        for(int i=0; i<operations.size(); i++){
            if(operations[i]=="D"){
                int c = st.top();
                st.push(2*c);
                sum = sum + st.top();
            }
            else if(operations[i]=="C"){
                sum = sum - st.top();
                st.pop();
            }
            else if(operations[i]=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
                sum = sum + st.top();
            }
            else{
                st.push(stoi(operations[i]));
                sum = sum + st.top();
            }
        }
        return sum;
    }
};