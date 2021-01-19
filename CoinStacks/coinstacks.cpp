#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	int s = accumulate(v.begin(), v.end(), 0);
	if (s % 2 or (s / 2 < *max_element(v.begin(), v.end()))) {
		cout << "no" << endl;
	}
	else {
		cout << "yes" << endl;
		while (s) {
			vector<int>::iterator m = max_element(v.begin(), v.end());
			for (vector<int>::iterator p = v.begin(); p < v.end(); p++) {
				if (p == m) {
					p++;
				}
				if (*p > 0) {
					cout << m - v.begin() + 1 << ' ' << p - v.begin() + 1 << endl;
					(*m)--;
					(*p)--;
					break;
				}
			}
			s -= 2;
		}
	}
}