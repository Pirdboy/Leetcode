//Title:Min Stack
//用一个栈存储数据,用另一个栈存储当前栈中的最小值
//第二个栈不需要在每次push的时候都存一遍最小值（如果不这样优化，将不能ac）
//如果新来的值比当前最小值要打,则没必要存,如果小或者相等,则需要存进去
//在pop时,如果弹出的值<=当前最小值,那么第二个栈也需要弹出当前最小值
class MinStack {
private:
    stack<int> mins;
    stack<int> nums;
public:
    void push(int x) {
        nums.push(x);
        if(mins.size()==0)
            mins.push(x);
        else{
            if(x<=mins.top())
                mins.push(x);
        }
    }

    void pop() {
        int a=nums.top();
        nums.pop();
        if(a<=mins.top())
            mins.pop();
    }

    int top() {
        return nums.top();
    }

    int getMin() {
        return mins.top();
    }
};
