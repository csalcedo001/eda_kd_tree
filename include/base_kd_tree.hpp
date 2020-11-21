#ifndef KD_TREE_BASE_KD_TREE_HPP_
#define KD_TREE_BASE_KD_TREE_HPP_

#include <array>

namespace eda {

namespace kd_tree {

template <typename T, int m, class Node>
class BaseKDTree {
protected:
	Node *head_;

public:
	BaseKDTree();
	void insert(std::array<int, m> &, T &);
	void print();

protected:
	void insert(Node *&, std::array<int, m> &, T &, int);
	void print(Node *, int level);
};

} // namespace kd_tree

} // namespace eda

#include "impl/base_kd_tree.ipp"

#endif // KD_TREE_BASE_KD_TREE_HPP_
