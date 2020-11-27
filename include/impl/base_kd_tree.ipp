#ifndef KD_TREE_BASE_KD_TREE_IPP_
#define KD_TREE_BASE_KD_TREE_IPP_

#include "base_kd_tree.hpp"

#include <iostream>
#include <array>
#include <limits>
#include <cmath>

#include "base_node.hpp"

namespace eda {

namespace kd_tree {

template <typename T, std::size_t m, class Node>
BaseKDTree<T, m, Node>::BaseKDTree() :
	head_(nullptr)
{ }

template <typename T, std::size_t m, class Node>
void BaseKDTree<T, m, Node>::insert(std::array<int, m> &point, T &data) {
	this->insert(this->head_, point, data, 0);
}

template <typename T, std::size_t m, class Node>
void BaseKDTree<T, m, Node>::print() {
	this->print(this->head_, 0);
}

template <typename T, std::size_t m, class Node>
std::vector<T> BaseKDTree<T, m, Node>::get(std::array<int, m> &point) {
	return this->get(this->head_, point, 0);
}

template <typename T, std::size_t m, class Node>
std::vector<T> BaseKDTree<T, m, Node>::get_min(int query) {
	Node *node = this->get_min(this->head_, query, 0);

	return node == nullptr ? std::vector<T>() : node->data_;
}

template <typename T, std::size_t m, class Node>
std::vector<T> BaseKDTree<T, m, Node>::nearest_neighbors(std::array<int, m> &point, int k) {
	std::vector<T> neighbors;

	this->nearest_neighbors(this->head_, neighbors, point, k);

	return neighbors;
}

template <typename T, std::size_t m, class Node>
void BaseKDTree<T, m, Node>::insert(Node *&node, std::array<int, m> &point, T &data, int dimension) {
	if (node == nullptr) {
		node = new Node(point, data);
		return;
	}

	if (same(point, node->point_)) {
		node->data_.push_back(data);
		return;
	}

	this->insert(node->children_[point[dimension] >= node->point_[dimension]], point, data, (dimension + 1) % m);
}

template <typename T, std::size_t m, class Node>
void BaseKDTree<T, m, Node>::print(Node *node, int level) {
	if (node == nullptr) return;

	this->print(node->children_[0], level + 1);

	for (int i = 0; i < level; i++) {
		std::cout << "    ";
	}

	std::cout << node->point_[0];

	for (int i = 1; i < m; i++) {
		std::cout << ' ' << node->point_[1];
	}

	for (auto value : node->data_) {
		std::cout << ' ' << value;
	}

	std::cout << std::endl;

	this->print(node->children_[1], level + 1);
}

template <typename T, std::size_t m, class Node>
std::vector<T> BaseKDTree<T, m, Node>::get(Node *node, std::array<int, m> &point, int dimension) {
	if (node == nullptr) return {};
	if (same(point, node->point_)) return node->data_;

	return this->get(node->children_[point[dimension] >= node->point_[dimension]], point, (dimension + 1) % m);
}

template <typename T, std::size_t m, class Node>
Node *BaseKDTree<T, m, Node>::get_min(Node *node, int query, int dimension) {
	if (node == nullptr) return nullptr;

	Node *left = this->get_min(node->children_[0], query, (dimension + 1) % m);

	if (query == dimension) {
		return left != nullptr ? left : node;
	}

	Node *right = this->get_min(node->children_[1], query, (dimension + 1) % m);

	if (right == nullptr) return node;
	if (right->point_[query] < node->point_[query]) return right;

	return node;
}

template <typename T, std::size_t m, class Node>
void BaseKDTree<T, m, Node>::nearest_neighbors(Node *node, std::vector<T> &neighbors, std::array<int, m> &point, int k) {
	if (node == nullptr || neighbors.size() == k) return;

	double distances[3];
	int indices[3];

	int l = 3;

	while (l--) {
		indices[l] = l;
	}

	distances[0] = distances[1] = std::numeric_limits<int>::max();
	distances[2] = distance(node->point_, point);

	l = 2;

	// Sort indices according to distance from query point
	while (l--) {
		if (node->children_[l] != nullptr) {
			distances[l] = distance(node->children_[l]->point_, point);
		}

		if (distances[l] <= distances[l + 1]) {
			std::swap(distances[l], distances[l + 1]);
			std::swap(indices[l], indices[l + 1]);
		}
	}

	if (distances[0] <= distances[2]) {
		std::swap(distances[0], distances[2]);
		std::swap(indices[0], indices[2]);
	}

	l = 3;

	while (l--) {
		if (indices[l] != 2) {
			this->nearest_neighbors(node->children_[indices[l]], neighbors, point, k);
		}
		else {
			for (int i = 0; i < node->data_.size(); i++) {
				if (neighbors.size() >= k) return;

				neighbors.push_back(node->data_[i]);
			}
		}
	}
}

template <std::size_t m>
double distance(std::array<int, m> &a, std::array<int, m> &b) {
	double total = 0;

	for (int i = 0; i < m; i++) {
		total += (a[i] - b[i]) * (a[i] - b[i]);
	}

	return sqrt(total);
}

template <std::size_t m>
bool same(std::array<int, m> &a, std::array<int, m> &b) {
	for (int i = 0; i < m; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}

	return true;
}

} // namespace kd_tree

} // namespace eda

#endif // KD_TREE_BASE_KD_TREE_IPP_
