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

	point[0] = 3;
	point[1] = 0;

	auto data = kd_tree.get(point);

	if (data.size() == 0) {
		cout << "No data at position (" << point[0] << "," << point[1] << ')' << endl;
	}
	else {
		cout << "Data at position (" << point[0] << "," << point[1] << "):" << endl;

		for (auto e : data) {
			cout << "    " << e << endl;
		}
	}


	int axis = 1;
	data = kd_tree.get_min(0);

	if (n == 0) {
		cout << "Empty KD-tree, can't get min on " << (axis == 0 ? 'x' : 'y') << " axis" << endl;
	}
	else {
		cout << "Data at minimum position across " << (axis == 0 ? 'x' : 'y') << " axis" << endl;

		for (auto e : data) {
			cout << "    " << e << endl;
		}
	}

	point[0] = 1;
	point[1] = 4;

	int k = 3;
	data = kd_tree.nearest_neighbors(point, k);

	cout << k << " nearest neighbors to position (" << point[0] << ',' << point[1] << "):" << endl;

	for (auto e : data) {
		cout << "    " << e << endl;
	}

	return 0;
}
