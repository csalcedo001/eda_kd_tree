#ifndef KD_TREE_NODE_IPP_
#define KD_TREE_NODE_IPP_

#include "node.hpp"

#include "base_node.hpp"

namespace eda {

namespace kd_tree {

template <typename T, int m>
Node<T, m>::Node(std::array<int, m> &point, T &data) :
	BaseNode<T, m, Node<T, m> >(point, data)
{ }

} // namespace kd_tree

} // namespace eda

#endif // KD_TREE_NODE_IPP_
