class MyCircularQueue {
public:
    int *arr;
    int start;
    int end;
    int len;
    int capacity;
    
    MyCircularQueue(int k) {
        arr = new int[k];
        capacity = k;
        start = 0;
        end = -1;
        len = 0;
    }
    
    bool enQueue(int value) {
        if(len == capacity){
            return false;
        }
        else{
            if(end == capacity-1){
                end = 0;
            }
            else{
                end++;
            }
            arr[end] = value;
            len++;
            return true;
        }
    }
    
    bool deQueue() {
        if(len == 0){
            return false;
        }
        else{
            if(start == capacity-1){
                start = 0;
            }
            else{
                start++;
            }
            len--;
            return true;
        }
    }
    
    int Front() {
        if(len == 0){
            return -1;
        }
        else{
            return arr[start];
        }
    }
    
    int Rear() {
        if(len == 0){
            return -1;
        }
        else{
            return arr[end];
        }
    }
    
    bool isEmpty() {
        if(len == 0){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if(len == capacity){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */