#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include<algorithm>
using namespace std;


struct person{
	int a, s;
	person(int ia, int is) {
		a = ia;
		s = is;
	}
};

bool comp(person lhs, person rhs) {
	if (lhs.a <= rhs.a) {
			return true;
		}
		else {
			return false;
		}
}

int main() {
	int n, m, count = 0;
	cin >> n >> m;
	priority_queue <int, vector<int>, greater<int>> times;
	vector<person> people;
	for (int i = 0; i < n; i++) {
		int a, s;
		cin >> a >> s;
		people.push_back(person(a, s));
	}
	sort(people.begin(), people.end(), comp);
	for (auto x : people) {
		while (times.size() && times.top() < x.a) {
			times.pop();
		}
		if (times.size() && (times.top() - m < x.a)) {
			times.pop();
			count--;
		}
		times.push(x.a + x.s + m);
		count++;	
	}
	cout << count << endl;
}