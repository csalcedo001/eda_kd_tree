#include <iostream>
#include <vector>
#include <experimental/filesystem>

#include "CImg.h"

using namespace cimg_library;
using namespace std;

vector<double> vectorize(CImg<double> & img) {
	CImg<double> a = img.haar(false, 2);
  	a = a.crop(0, 0, 23, 23);
	
	vector<double> result;
	cimg_forXY(a, x, y) { 
		result.push_back(a(x,y,0));
   	}

	return result;
}

vector<vector<double>> get_vectors(string directory_name, string clase) {
	vector<vector<double>> points;
	directory_name.append("/" + clase);
	for (const auto& entry : experimental::filesystem::directory_iterator(directory_name)) {
		string entry_s = entry.path().filename().string();
		string entry_path = directory_name;
		entry_path.append("/");
		entry_path.append(entry_s);
		CImg<double> A(entry_path.c_str());
		vector<double> vA = vectorize(A);
		points.push_back(vA); 
	}
	return points;
}


int main() {
	vector<string> clases = {"anger", "contempt", "disgust", "fear", "happy", "sadness", "surprise"};

	vector<vector<double>> training_set, test_set;
	vector<string> training_class, test_class;

	for (auto& clase : clases) {
		auto vectors = get_vectors("CK+48", clase);
		int training_set_size = (double) vectors.size() * 0.7;
		for (int i = 0; i < training_set_size; ++i) {
			training_set.push_back(vectors[i]);
			training_class.push_back(clase);
		}
		for (int i = training_set_size; i < vectors.size(); ++i) {
        	test_set.push_back(vectors[i]);
			test_class.push_back(clase);
    	}
	}
	
	cout << training_set.size() << " " << training_set[0].size() << "\n";
	for (int i = 0; i < training_set.size(); ++i) {
		for (auto& value : training_set[i]) cout << value << " ";
		cout << training_class[i] << "\n";
	}

	cout << test_set.size() << "\n";
    for (int i = 0; i < test_set.size(); ++i) {
        for (auto& value : test_set[i]) cout << value << " ";
        cout << test_class[i] << "\n";
    }


	return 0;
}
