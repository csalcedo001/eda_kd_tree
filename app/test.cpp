#include <iostream>

#include "kd_tree.hpp"

#define M 2

using namespace std;

int main() {
	eda::kd_tree::KDTree<string, M> kd_tree;

	array<int, M> point;
	string label;

	point[0] = 1;
	point[1] = 3;
	
	label = "First";

	kd_tree.insert(point, label);

	point[0] = -1;
	point[1] = 4;

	label = "Second";

	kd_tree.insert(point, label);

	kd_tree.print();

	return 0;
}
