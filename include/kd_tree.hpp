#ifndef KD_TREE_KD_TREE_HPP_
#define KD_TREE_KD_TREE_HPP_

#include "base_kd_tree.hpp"
#include "node.hpp"

namespace eda {

namespace kd_tree {

template <typename T, std::size_t m>
class KDTree : public BaseKDTree<T, m, Node<T, m> > { };

} // namespace kd_tree

} // namespace eda

#endif // KD_TREE_KD_TREE_HPP_
