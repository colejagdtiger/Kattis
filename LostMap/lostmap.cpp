#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <utility>
#include <algorithm>

using namespace std;

struct edge {
	int weight;
	int v1;
	int v2;
	bool operator<(const edge& x) const {return x.weight < weight;}
};

struct UF {
	vector<int> v;
	UF (int n) {v.resize(n); iota(begin(v), end(v), 0);}
	int find(int x) {return v[x] = (v[x] == x ? x : find(v[x]));}
	void merge(int x, int y) {v[find(x)] = find(y);}
};

int main() {
	int n;
	cin >> n;
	vector<edge> pq;
	edge e;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> e.weight;
			e.v1 = i;
			e.v2 = j;
			if (i < j) {
				pq.push_back(e);
			}
		}
	}
	sort(pq.begin(), pq.end());
	UF uf(n);
	vector <pair<int, int>> mst;
	while (pq.size()) {
		e = pq.back();
		int x = e.v1;
		int y = e.v2;
		pq.pop_back();
		if (uf.find(x) != uf.find(y)) {
			uf.merge(x, y);
			mst.push_back({x + 1, y + 1});
		}
	}
	for (auto e : mst) {
		cout << e.first << ' ' << e.second << endl;
	}

}