#include <iostream>
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
    visited[s] = 1;
    for (int i = 1; i <= N; i++) {
        if (!visited[i] && matrix[s - 1][i - 1] == 1) {
            DFS(i);
        }
    }
    cout << s << " ";
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
