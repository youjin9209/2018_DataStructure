/*
문제 풀이 
https://www.acmicpc.net/problem/1406
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
struct Stack {
    char data[600001];
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
    int n;
    cin >> s;
    cin >> n;
    Stack left, right;
    for (int i = 0; i < s.size(); i++) {
        left.push(s[i]);
    }
    while (n-- > 0) {
        char cmd;
        scanf(" %c", &cmd);
        if (cmd == 'L') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } else if (cmd == 'D') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if (cmd == 'B') {
            if (!left.empty()) {
                left.pop();
            }
        } else if (cmd == 'P') {
            char c;
            scanf(" %c", &c);
            left.push(c);
        }
    }
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        printf("%c", right.top());
        right.pop();
    }
    printf("\n");
    return 0;
}
