#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cmath>
#include <map>

using namespace std;

const int N = 3;
typedef vector<vector<int>> Matrix;

struct Node {
    Matrix state;
    int g, h;
    string path;
    pair<int, int> blank_pos;
    
    Node(Matrix st, int g_cost, int h_cost, string p, pair<int, int> bp)
        : state(st), g(g_cost), h(h_cost), path(p), blank_pos(bp) {}

    int f() const { return g + h; }

    bool operator>(const Node &other) const {
        return f() > other.f();
    }
};

// Manhattan distance
int calculateHeuristic(const Matrix& state, const Matrix& goal) {
    map<int, pair<int, int>> goalPos;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            goalPos[goal[i][j]] = {i, j};

    int dist = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (state[i][j] != 0)
                dist += abs(i - goalPos[state[i][j]].first) + abs(j - goalPos[state[i][j]].second);
    return dist;
}

string matrixToString(const Matrix& state) {
    string s;
    for (const auto& row : state)
        for (int val : row)
            s += to_string(val);
    return s;
}

vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
vector<char> dirChar = {'U', 'D', 'L', 'R'};

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

void printMatrix(const Matrix& m) {
    for (auto& row : m) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
    cout << "\n";
}

bool AStar(Matrix start, Matrix goal) {
    auto h = calculateHeuristic(start, goal);
    pair<int, int> blank;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (start[i][j] == 0)
                blank = {i, j};

    priority_queue<Node, vector<Node>, greater<Node>> open;
    unordered_set<string> closed;
    open.push(Node(start, 0, h, "", blank));

    while (!open.empty()) {
        Node curr = open.top();
        open.pop();

        string id = matrixToString(curr.state);
        if (closed.find(id) != closed.end())
            continue;

        closed.insert(id);

        if (curr.state == goal) {
            cout << "Solution found in " << curr.g << " moves!\nPath: " << curr.path << "\n\n";
            cout << "Final state:\n";
            printMatrix(curr.state);
            return true;
        }

        for (int d = 0; d < 4; ++d) {
            int newX = curr.blank_pos.first + directions[d].first;
            int newY = curr.blank_pos.second + directions[d].second;

            if (isValid(newX, newY)) {
                Matrix newState = curr.state;
                swap(newState[curr.blank_pos.first][curr.blank_pos.second], newState[newX][newY]);
                string newID = matrixToString(newState);

                if (closed.find(newID) == closed.end()) {
                    int newG = curr.g + 1;
                    int newH = calculateHeuristic(newState, goal);
                    string newPath = curr.path + dirChar[d];
                    open.push(Node(newState, newG, newH, newPath, {newX, newY}));
                }
            }
        }
    }
    cout << "No solution found.\n";
    return false;
}

Matrix inputMatrix(string prompt) {
    Matrix mat(N, vector<int>(N));
    cout << "Enter " << prompt << " state (row by row, 0 for blank):\n";
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> mat[i][j];
    return mat;
}

int main() {
    Matrix start = inputMatrix("initial");
    Matrix goal = inputMatrix("goal");

    AStar(start, goal);
    return 0;
}
