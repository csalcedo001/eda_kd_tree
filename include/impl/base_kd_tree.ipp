#ifndef KD_TREE_BASE_KD_TREE_IPP_
#define KD_TREE_BASE_KD_TREE_IPP_

#include "base_kd_tree.hpp"

#include <iostream>
#include <array>

#include "base_node.hpp"

namespace eda {

namespace kd_tree {

template <typename T, int m, class Node>
BaseKDTree<T, m, Node>::BaseKDTree() :
	head_(nullptr)
{ }

template <typename T, int m, class Node>
void BaseKDTree<T, m, Node>::insert(std::array<int, m> &point, T &data) {
	this->insert(this->head_, point, data, 0);
}

template <typename T, int m, class Node>
void BaseKDTree<T, m, Node>::print() {
	this->print(this->head_, 0);
}

template <typename T, int m, class Node>
void BaseKDTree<T, m, Node>::insert(Node *&node, std::array<int, m> &point, T &data, int dimension) {
	if (node == nullptr) {
		node = new Node(point, data);
		return;
	}

	this->insert(node->children_[point[dimension] >= node->point_[dimension]], point, data, (dimension + 1) % m);
}

template <typename T, int m, class Node>
void BaseKDTree<T, m, Node>::print(Node *node, int level) {
	if (node != nullptr) {
		this->print(node->children_[0], level + 1);

		for (int i = 0; i < level; i++) {
			std::cout << "    ";
		}

		std::cout << node->point_[0];

		for (int i = 1; i < m; i++) {
			std::cout << ' ' << node->point_[1];
		}

		std::cout << std::endl;

		this->print(node->children_[1], level + 1);
	}
}

} // namespace kd_tree

} // namespace eda

#endif // KD_TREE_BASE_KD_TREE_IPP_
