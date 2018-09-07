/*
문제 링크 
https://www.acmicpc.net/problem/10799
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

int main() {
    string s;
    cin >> s;
    Stack stack;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stack.push(s[i]);
        } else if (s[i] == ')') {
            stack.pop();
            if (s[i-1] == '(') {
                cnt += stack.size;
            } else {
                cnt += 1;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
