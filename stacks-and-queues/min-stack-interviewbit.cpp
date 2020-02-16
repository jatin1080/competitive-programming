#include <bits/stdc++.h>

using namespace std;

stack<int> minStack;
stack<int> minElement;

class MinStack {
public:
    MinStack();
    void push(int x);
    void pop();
    int top();
    int getMin();
};

int main() {
    // s.push(10);
    // cout<<"top element: "<<s.top()<<endl;
    // cout<<"min element: "<<s.getMin()<<endl;
    // s.pop();
    // cout<<"top element: "<<s.top()<<endl;

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    MinStack s;
    int N;
    cin>>N;

    for(int i=1; i<=N; i++)
    {
        char operation;
        cin>>operation;
        // if(i==1)cout<<"entering for loop \n";

        switch(operation) {
            case 'P' : 
                int x;
                cin>>x;
                i++;
                s.push(x);
                break;
            case 'p' :
                s.pop();
                break;
            case 'g' : 
                cout<<s.getMin()<<endl;
                break;
            case 't' :
                cout<<s.top()<<endl;
                break;
            default: 
                // cout<<"calling default: Dont know why! \n";
                break;

        }
    }

    return 0;
}

MinStack::MinStack() {
    cout<<"calling constructor MinStack() \n";
    // stack<int>().swap(minStack);
    // stack<int>().swap(minElement);
}

void MinStack::push(int x) {
    // cout<<"calling push() \n";
    minStack.push(x);
    if(minElement.empty()) minElement.push(x);
    else {
        int y = minElement.top() ;
        (x <= y) ? minElement.push(x) : minElement.push(y);    
        }
}

void MinStack::pop() {
    // cout<<"calling pop() \n";
    if(!minStack.empty()) minStack.pop();
    if(!minElement.empty()) minElement.pop();
}

int MinStack::top() {
    // cout<<"top element: ";
    return minStack.empty() ? -1 : minStack.top();
}

int MinStack::getMin() {
    // cout<<"min element: ";
    return minElement.empty() ? -1 : minElement.top();
}