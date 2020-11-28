#include <iostream>
#include <vector>
#include <experimental/filesystem>

#include "CImg.h"
#define N_PICS 832

using namespace cimg_library;
using namespace std;

vector<int> vectorize(CImg<double> & img) {
	vector<int> v(256, 0);
    for(int i=0;i< img.width();i++) {
        for(int j=0;j< img.height();j++) {
            int r = img(i,j,0);
            int g = img(i,j,1);
            int b = img(i,j,2);
            
			int grey = (r+g+b)/3;
			v[grey]++;
        }
	}
	return v;
}

vector<vector<int>> get_vectors(string directory_name, vector<string> &classes) {
	vector<vector<int>> points;
	for (const auto& entry : experimental::filesystem::directory_iterator(directory_name)) {
		string entry_s = entry.path().filename().string();
		string entry_path = directory_name;
		entry_path.append("/");
		entry_path.append(entry_s);
		CImg<double> A(entry_path.c_str());
		vector<int> vA = vectorize(A);
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
		for (int & i : vectors[i]) cout << i << " ";
		cout << classes[i] << "\n";
	}
	int test_set_size = vectors.size() - training_set_size;
	cout << test_set_size << "\n";
	for (int i = training_set_size; i < vectors.size(); ++i) {
        for (int & i : vectors[i]) cout << i << " ";
        cout << classes[i] << "\n";
    }

	return 0;
}
