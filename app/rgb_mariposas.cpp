#include <iostream>
#include <vector>
#include <filesystem>

#include "CImg.h"
#define N_PICS 832

using namespace cimg_library;
using namespace std;

vector<double> vectorize(CImg<double> & img) {
	CImg<double> haar = img.haar(false, 3);
	CImg<double> crop = haar.crop(0,0,27,27);

	vector<double> result;
	cimg_forXY(crop, x, y) {
		result.push_back((crop(x,y,0)+crop(x,y,1)+crop(x,y,2))/3);
	}

	return result;
}

vector<vector<double>> get_vectors(string directory_name, vector<string> &classes) {
	vector<vector<double>> points;
	for (const auto& entry : filesystem::directory_iterator(directory_name)) {
		string entry_s = entry.path().filename().string();
		string entry_path = directory_name;
		entry_path.append("/");
		entry_path.append(entry_s);
		CImg<double> A(entry_path.c_str());
		A.resize(304,208);
		vector<double> vA = vectorize(A);
		points.push_back(vA); 
		classes.push_back(entry_s.substr(0,3));
	}
	return points;
}


int main() {
	vector<string> classes;
	auto vectors = get_vectors("leedsbutterfly/images", classes);
	int training_set_size = (double) vectors.size() * 0.7;
	cout << training_set_size << " " << vectors[0].size() << "\n";
	for (int i = 0; i < training_set_size; ++i) {
		for (auto & i : vectors[i]) cout << i << " ";
		cout << classes[i] << "\n";
	}
	int test_set_size = vectors.size() - training_set_size;
	cout << test_set_size << "\n";
	for (int i = training_set_size; i < vectors.size(); ++i) {
        for (auto & i : vectors[i]) cout << i << " ";
        cout << classes[i] << "\n";
    }

	return 0;
}
