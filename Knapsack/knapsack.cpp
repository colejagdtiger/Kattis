#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {

	int C, n;

	while (cin >> C >> n) {

		vector <vector <int> > table(n + 1, vector<int> (C + 1, 0));

		vector<pair<int, int>> objects;
		objects.push_back({0, 0});

		for (int i = 0; i < n; i++) {
			pair <int, int> obj;
			cin >> obj.first >> obj.second;
			objects.push_back(obj);
		}

		for (int i = 1; i <= n; i++) {
			int v = objects[i].first;
			int w = objects[i].second;
			for (int j = 1; j <= C; j++) {
				if (w > j) {
					table[i][j] = table[i - 1][j];
				}
				else {
					table[i][j] = max(table[i - 1][j], table[i - 1][j - w] + v);
				}
			}
		}
		vector<int> trace;
		int j = C;
		for (int i = n; i > 0; i--) {
			if (table[i][j] == 0) {
				break;
			}
			if (table[i][j] != table[i - 1][j]) {
				trace.push_back(i - 1);
				j -= objects[i].second;
			}
		}

		cout << trace.size() << endl;
		for (auto i : trace) {
			cout << i << ' ';
		}
		cout << endl;
	}
}