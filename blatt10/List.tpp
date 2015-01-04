/*
 * List.tpp
 *
 *  Created on: Jan 2, 2015
 *      Author: Michael Micke, Frank Mehne
 */

#ifndef LIST_TPP_
#define LIST_TPP_

#include "List.hpp"

/**
 * Constructor for an empty List
 */
template<typename T>
List<T>::List() {

	// Create a root Node
	m_list = new Node();
}

/**
 * Destructor for the List
 */
template<typename T>
List<T>::~List() {

	// As long as there are Nodes in the List
	while (m_list->next) {

		// get the next node
		Node* tmpNode = m_list->next;

		// Get the Node after the next one
		m_list->next = tmpNode->next;

		// delete the current Node
		delete tmpNode;
	}

	// delete root Node
	delete m_list;
}

/**
 * Inserts new Node in List
 */
template<typename T>
void List<T>::insert(T item) {

	// Create new Node
	Node* tmpNode = new Node();

	// Assign data to new Node
	tmpNode->data = item;

	// Insert Node
	tmpNode->next = m_list->next;
	m_list->next = tmpNode;

}

/**
 * Iterator that calls function on all Nodes in the List
 */
template<typename T>
void List<T>::for_each(void (*do_something)(T item)) {

	// Create temporary Node to not change position of list by iterating
	Node* tmpNode = m_list->next;

	// go through all Nodes of the List
	while (tmpNode) {

		// Call the given function on the data
		do_something(tmpNode->data);

		// Move forward in List
		tmpNode = tmpNode->next;
	}
}

#endif /* LIST_TPP_ */
