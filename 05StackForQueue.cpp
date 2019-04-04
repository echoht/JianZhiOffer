class Solution
{
public:
    void push(int node) {
	    stack1.push(node);
    }

    int pop() {
		// 主stack中所有元素 push到 辅助stack
        while(!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
		//pop the first input node 
		int res = stack2.top();
		stack2.pop();
		// 剩下元素归位
		while(!stack2.empty()){
			stack1.push(stack2.top());
			stack2.pop();
		}
		return res;
    }

private:
    stack<int> stack1; // master stack 
    stack<int> stack2; // auxiliary stack
};
