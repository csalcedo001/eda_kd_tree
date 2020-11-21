#ifndef KD_TREE_BASE_NODE_IPP_
#define KD_TREE_BASE_NODE_IPP_

#include "base_node.hpp"

#include <array>

namespace eda {

namespace kd_tree {

template <typename T, int m, class Node>
BaseNode<T, m, Node>::BaseNode(std::array<int, m> &point, T &data) :
	point_(point),
	data_(data)
{ }

} // namespace kd_tree

} // namespace eda

#endif // KD_TREE_BASE_NODE_IPP_
