/*
문제 링크 
https://www.acmicpc.net/problem/9012
*/
#include <iostream>
#include <cstdlib>
using namespace std;
struct Stack {
    char data[10000];
    int size;
    Stack() {
        size = 0;
    }
    void push (char token) {
        data[size] = token;
        size += 1;
    }
    bool empty() {
        if (size == 0) {
            return true;
        } else {
            return false;
        }
    }
    int top() {
        if (empty()) {
            return -1;
        } else {
            return data[size - 1];
        }
    }
    int pop() {
        if (empty()) {
            return -1;
        } else {
            size -= 1;
            return data[size];
        }
    }
};
string valid(string s) {
    Stack stack;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stack.push(s[i]);
        } else {
            if (stack.empty()) {
                return "NO";
            } else {
                stack.pop();
            }
            if (stack.size < 0) {
                return "NO";
            }
        }
    }
    if (stack.size == 0) {
        return "YES";
    } else {
        return "NO";
    }
}
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        string s;
        cin >> s;
        cout << valid(s) << '\n';
    }
    return 0;
}
