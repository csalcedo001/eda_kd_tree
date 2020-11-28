#include <iostream>

#define cimg_use_jpeg
#include "CImg.h"
#include "ANN/ANN.h"

#include "kd_tree.hpp"

#define M 2

using namespace cimg_library;
using namespace std;

int main() {
	eda::kd_tree::KDTree<string, M> kd_tree;

	int n, dimensions;

	cin >> n >> dimensions;

	ANNpointArray point_array = annAllocPts(n, dimensions);

	vector<string> labels(n);

	for (int i = 0; i < n; i++) {
		for (int d = 0; d < dimensions; d++) {
			cin >> point_array[i][d];
		}

		cin >> labels[i];
	}

	ANNkd_tree tree(point_array, n, dimensions);

	tree.Print(ANNtrue, cout);

	int m;

	cin >> m;

	ANNpoint query = annAllocPt(dimensions);
	ANNidxArray nn_idx = new ANNidx[1];
	ANNdistArray dists = new ANNdist[1];

	while (m--) {
		cin >> query[0] >> query[1];

		tree.annkSearch(query, 1, nn_idx, dists);

		cout << labels[nn_idx[0]] << endl;
	}

	annDeallocPts(point_array);
	annDeallocPt(query);

	return 0;
}
