struct Node {
    int val;
    int minVal;
    Node * next;
    Node * last;
    Node(int val_, int minVal_ ): val(val_), minVal(minVal_), next(NULL), last(NULL){};
    Node(int val_): val(val_), minVal(0), next(NULL), last(NULL){};

};

class Solution {
public:
    Solution(){
        stack_sz = 0;
        dumy_head = new Node(0);
        pos_idx = dumy_head;
    };
    
    void push(int value) {
        //find the min val
        if(stack_sz == 0){
            min_val = value;
        }else{
            if(value < min_val){
                min_val = value;
            }
        }
        
        //first new a val 
        Node *tmp = new Node(value, min_val);
        pos_idx->next = tmp;
        tmp->last = pos_idx;
        
        //update 
        pos_idx = tmp;
        stack_sz ++;
    }
    void pop() {
        // nothing to pop
        if(stack_sz <= 0){
            return;
        }
        Node *tmp = pos_idx->last;
        delete pos_idx;
        stack_sz --;
        pos_idx = tmp;
    }
    int top() {
        if(stack_sz <= 0){
            return -1;
        }
        return pos_idx->val;
    }
    int min() {
        if(stack_sz <= 0){
            return -1;
        }
        return pos_idx->minVal;
    }
private:
    int min_val; //最小值
    Node* dumy_head; //空的起始节点
    Node* pos_idx; //最后一个指针
    int stack_sz;
};
