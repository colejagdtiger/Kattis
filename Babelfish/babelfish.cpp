#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

	map<string, string> dict;
	string s1, s2;
	string line;
	while (getline(cin, line) && !line.empty()) {
		auto delim = line.find(' ');
		s1 = line.substr(0, delim);
		s2 = line.substr(delim + 1);
		dict.insert({s2, s1});
	}

	while (cin >> s2) {
		if (dict.count(s2)) {
			cout << dict[s2] << endl;
		}
		else {
			cout << "eh" << endl;
		}
	}

}