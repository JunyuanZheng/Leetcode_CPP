#include <stack>
#include <climits>

using namespace std;

/*
class MinStack {
private:
    stack<int> storageStack;
    stack<int> minStack;
public:
    void push(int x) {
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
        storageStack.push(x);
    }

    void pop() {
        if (storageStack.top() == minStack.top()) {
            minStack.pop();
        }
        storageStack.pop();
    }

    int top() {
        return storageStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
 */

/*
class MinStack {
private:
    stack<int> s;
    int min = INT_MAX;
public:
    void push(int x) {
        if (x <= min) {
            s.push(min);
            min = x;
        }
        s.push(x);
    }

    void pop() {
        if (s.top() == min) {
            s.pop();
            min = s.top();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min;
    }
};
*/