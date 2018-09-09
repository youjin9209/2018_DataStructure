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
        // 1) 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
        if (cmd == 'L') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } 
        // 2) 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
        else if (cmd == 'D') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } 
        // 3) 커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
        else if (cmd == 'B') {
            if (!left.empty()) {
                left.pop();
            }
        } 
        // 4) $라는 문자를 커서 왼쪽에 추가함
        else if (cmd == 'P') {
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
