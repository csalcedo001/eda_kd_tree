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

	int n = 2, d = 2;

	ANNpointArray pa = annAllocPts(n, d);

	pa[0][0] = 1;
	pa[0][1] = 3;

	pa[1][0] = -1;
	pa[1][1] = 4;

	ANNkd_tree tree(pa, n, d);

	tree.Print(ANNtrue, cout);

	ANNidxArray nn_idx = new ANNidx[d];
	ANNdistArray dists = new ANNdist[d];

	ANNpoint q = annAllocPt(d);

	cout << q[0] << ' ' << q[1] << endl;

	tree.annkSearch(q, 1, nn_idx, dists);

	cout << pa[nn_idx[0]][0] << ' ' << pa[nn_idx[0]][1] << endl;

	annDeallocPts(pa);


	// array<int, M> point;
	// string label;

	// point[0] = 1;
	// point[1] = 3;
	// 
	// label = "First";

	// kd_tree.insert(point, label);

	// point[0] = -1;
	// point[1] = 4;

	// label = "Second";

	// kd_tree.insert(point, label);

	// kd_tree.print();

	return 0;
}
