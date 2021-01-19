#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int n, k;
	cin >> n;
	vector <pair <int, int>> people;
	for (int i = 0; i < n; i++) {
		cin >> k;
		people.push_back({i+1, k});
	}
	int ind = 0;
	n = people.size();
	while (n > 1) {
		k = (ind + people[ind].second - 1) % n;
		if (k == n - 1) {
			ind = 0;
		}
		else {
			ind = k;
		}
		people.erase(people.begin() + k);
		n = people.size();
	}
	cout << people.front().first << endl;
}