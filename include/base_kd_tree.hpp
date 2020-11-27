#ifndef KD_TREE_BASE_KD_TREE_HPP_
#define KD_TREE_BASE_KD_TREE_HPP_

#include <array>
#include <vector>

namespace eda {

namespace kd_tree {

template <std::size_t m>
double distance(std::array<int, m> &, std::array<int, m> &);

template <std::size_t m>
bool same(std::array<int, m> &, std::array<int, m> &);

template <typename T, std::size_t m, class Node>
class BaseKDTree {
protected:
	Node *head_;

public:
	BaseKDTree();
	void insert(std::array<int, m> &, T &);
	void print();
	std::vector<T> get(std::array<int, m> &);
	std::vector<T> get_min(int);
	std::vector<T> nearest_neighbors(std::array<int, m> &, int);

protected:
	void insert(Node *&, std::array<int, m> &, T &, int);
	void print(Node *, int level);
	std::vector<T> get(Node *, std::array<int, m> &, int);
	Node *get_min(Node *, int, int);
	void nearest_neighbors(Node *, std::vector<T> &, std::array<int, m> &, int);
};

} // namespace kd_tree

} // namespace eda

#include "impl/base_kd_tree.ipp"

#endif // KD_TREE_BASE_KD_TREE_HPP_
