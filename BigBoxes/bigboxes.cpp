#include<iostream>
#include<vector>
#include<stddef.h>
#include<iterator>

using namespace std;

bool test(int N, int k, vector<int> v) {
	vector<int>::iterator start;
	start = v.begin();
	int ind = 0;
	for (auto x = v.begin(); x != v.end(); x++) {
		if (ind >= k) {
			return false;
		}
		if (*x - *(x - 1) > N) {
			return false;
		}
		if (*x - *start > N) {
			start = x - 1;
			ind++;
		}
	}
	if (ind >= k) {
		return false;
	}
	return true;
	
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> cumsum;
	cumsum.push_back(0);
	int num;
	int upper;
	int lower = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (lower < num) {
			lower = num;
		}
		cumsum.push_back(num + cumsum[i]);
	}
	upper = cumsum.back();
	int N = (upper + lower) / 2;

	while (upper > lower) {
		if (test(N, k, cumsum)) {
			upper = N - 1;
		}
		else {
			lower = N + 1;
		}
		N = (upper + lower) / 2;
	}
	if (test(N, k, cumsum) == false) {
		N = N + 1;
	}
	cout << N << endl;



}