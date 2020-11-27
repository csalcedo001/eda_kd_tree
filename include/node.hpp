#ifndef KD_TREE_NODE_HPP_
#define KD_TREE_NODE_HPP_

#include "base_node.hpp"

namespace eda {

namespace kd_tree {

template <typename T, std::size_t m>
class Node : public BaseNode<T, m, Node<T, m> > {
public:
	Node(std::array<int, m> &, T &);
};

} // namespace kd_tree

} // namespace eda

#include "impl/node.ipp"

#endif // KD_TREE_NODE_HPP_
