#include <iostream>
#include <queue>
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

void BFS(int s) {
    queue<int> queue;
    queue.push(s);
    visited[s] = 1;
    while (!queue.empty()) {
        int front = queue.front();
        cout << front << " ";
        queue.pop();
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && matrix[front - 1][i - 1] == 1) {
                visited[i] = 1;
                queue.push(i);
            }
        }
    }
}

int main() {
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 1) {
            continue;
        }
        BFS(i);
    }
    return 0;
}
