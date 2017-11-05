#include <iostream>
#include <stack>
#define N 6
using namespace std;

int matrix[N][N] = {
        { 0, 1, 0, 1, 1, 1 },
        { 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 }
};

int visited[N + 1] = { 0, };

void DFS(int s) {
    stack<int> stack;
    stack.push(s);
    visited[s] = 1;
    bool flag;
    while (!stack.empty()) {
        flag = false;
        int v = stack.top();
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && matrix[v - 1][i - 1] == 1) {
                visited[i] = 1;
                stack.push(i);
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << v << " ";
            stack.pop();
        }
    }
}

int main() {
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 1) {
            continue;
        }
        DFS(i);
    }
    return 0;
}
