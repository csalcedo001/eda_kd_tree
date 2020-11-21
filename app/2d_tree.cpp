#include <iostream>

#include "kd_tree.hpp"

#define M 2

using namespace std;

int main() {
	eda::kd_tree::KDTree<string, M> kd_tree;

	int n;

	cin >> n;

	array<int, M> point;
	string name;

	while (n--) {
		for (int i = 0; i < M; i++) {
			cin >> point[i];
		}

		cin >> name;

		kd_tree.insert(point, name);
	}

	kd_tree.print();

	return 0;
}
