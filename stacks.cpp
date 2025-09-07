#include <bits/stdc++.h>
using namespace std;
//these return the values directly, change the assignment for getting the indices
vector<int> nextMax(vector<int>& a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[i] > a[stk.top()]) {
            res[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    return res;
}

vector<int> prevMax(vector<int>& a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[i] > a[stk.top()]) stk.pop();
        if (!stk.empty()) res[i] = a[stk.top()];
        stk.push(i);
    }
    return res;
}

vector<int> nextMin(vector<int>& a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[i] < a[stk.top()]) {
            res[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    return res;
}

vector<int> prevMin(vector<int>& a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[i] < a[stk.top()]) stk.pop();
        if (!stk.empty()) res[i] = a[stk.top()];
        stk.push(i);
    }
    return res;
}

int main(){
    return 0;
}
