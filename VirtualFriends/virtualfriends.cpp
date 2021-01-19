#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

void f_union(string n1, string n2,
             unordered_map<string, string> &people,
             unordered_map<string, int> &size) {
    string end1 = n1;
    string end2 = n2;
    while (end1 != people[end1]) {
        end1 = people[end1];
    }
    while (end2 != people[end2]) {
        end2 = people[end2];
    }

    if (size[end1] < size[end2]) {
        people[end1] = end2;
        size[end2] += size[end1];
    }
    else {
        people[end2] = end1;
        size[end1] += size[end2];
    }
}

int f_find(string a, string b,
            unordered_map<string, string> &people,
            unordered_map<string, int> &size) {
    string end1 = a;
    string end2 = b;
    while (end1 != people[end1]) {
        end1 = people[end1];
    }
    while (end2 != people[end2]) {
        end2 = people[end2];
    }
    if (end1 == end2) {
        return size[end1];
    }
    else {
        return 0;
    }
}

int main() {
    int T;
    cin >> T;
    int F;
    for (int i = 0; i < T; i++) {
        cin >> F;
        unordered_map<string, int> size;
        unordered_map<string, string> people;
        for (int j = 0; j < F; j++) {
            string n1, n2;
            cin >> n1 >> n2;
            if (people.count(n1) == 0) {
                people.insert({n1, n1});
                size.insert({n1, 1});
            }
            if (people.count(n2) == 0) {
                people.insert({n2, n2});
                size.insert({n2, 1});
            }

            int num = f_find(n1, n2, people, size);

            if (num > 0) {
                cout << num << endl;
            }
            else {
                if (n1 != n2) {
                    f_union(n1, n2, people, size);
                }
                cout << f_find(n1, n2, people, size) << endl;
            }
        }
    }
}