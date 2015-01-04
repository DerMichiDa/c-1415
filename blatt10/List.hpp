/*
 * List.hpp
 *
 *  Created on: Jan 2, 2015
 *      Author: Michael Micke, Frank Mehne
 */

#ifndef LIST_HPP_
#define LIST_HPP_

/**
 * @brief simple generic list class
 */
template<typename T>
class List {
public:
	/**
	 * @brief Struct to represent a node in the list.
	 */
	struct Node {
		Node* next;
		T data;
	};

	/**
	 * @brief Constructs an empty list.
	 */
	List<T>();

	/**
	 * @brief Destructor. Frees the generated nodes.
	 */
	~List<T>();

	/**
	 * @brief Inserts an item into the list, i.e. a new node
	 * containing @ref item is created.
	 */
	void insert(T item);

	/**
	 * @brief Iterates over all items in the list and calls
	 * the given function @ref do_something(...) for
	 * every item stored in the list.
	 */
	void for_each(void (*do_something)(T item));
private:
	// Root of the list
	Node* m_list;
};

#endif /* LIST_HPP_ */
