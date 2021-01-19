#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include <queue>

using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++) {
		int n, t, b;
		cin >> n >> t;
		vector<int> table(3601, -1);
		table[0] = 0;
		vector <bool> unseen(3601, true);
		queue <int> order;
		order.push(0);
		unseen[0] = 0;
		vector<int> nums;
		for (int j = 0; j < n; j++) {
			cin >> b;
			nums.push_back(b);
		}
		while (order.size()) {
			int a = order.front();
			order.pop();
			for (auto b : nums) {
				int j = max(min(a + b, 3600), 0);
				if (unseen[j]) {
					unseen[j] = false;
					order.push(j);
					table[j] = table[a] + 1;
				}
			}
		}
		for (int j = t; j <= 3600; j++) {
			if (table[j] > -1) {
				cout << table[j] << ' ' << j - t << endl;
				break;
			}
		}

		

	}

}