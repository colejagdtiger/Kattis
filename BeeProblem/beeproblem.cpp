#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;


int update(int i, int j, int n, int m, vector <vector<char>> &grid) {
    int count = 1;
    int s = -1, b = 1;
    if (i % 2) {
        s = 0, b = 2;
    }

    for (int x = s; x < b; x++) {
        for (int y = -1; y < 2; y += 2) {
            if (0 <= j + x && j + x < m &&
                0 <= i + y && i + y < n &&
                grid[i + y][j + x] == '.') {
                grid[i + y][j + x] = '#';
                count += update(i + y, j + x, n, m, grid);
            }
        }
    }

    for (int x = -1; x < 2; x++) {
        if (0 <= j + x && j + x < m &&
            grid[i][j + x] == '.') {

                grid[i][j + x] = '#';
                count += update(i, j + x, n, m, grid);
            }
    }
    return count;
}


int main() {
    int h, n, m;
    cin >> h >> n >> m;
    vector< vector <char> > grid(n, vector<char> (m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> counts;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                grid[i][j] = '#';
                counts.push_back(update(i, j, n, m, grid));

            }
        }
    }

    sort(counts.begin(), counts.end());
    int num = 0;

    while (h > 0) {
        h -= counts.back();
        counts.pop_back();
        num += 1;
    }

    cout << num << endl;



}