#ifndef KD_TREE_BASE_NODE_HPP_
#define KD_TREE_BASE_NODE_HPP_

#include <array>
#include <vector>

namespace eda {

namespace kd_tree {

template <typename T, std::size_t m, class Node>
class BaseNode {
public:
	std::array<int, m> point_;
	std::vector<T> data_;
	Node *children_[2];

	BaseNode(std::array<int, m> &);
	BaseNode(std::array<int, m> &, T);
};

} // namespace kd_tree

} // namespace eda

#include "impl/base_node.ipp"

#endif // KD_TREE_BASE_NODE_HPP_
