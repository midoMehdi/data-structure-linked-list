#pragma once
#include<iostream>
#include<memory>
#include<ostream>
#include<vector>
#include<cstdbool>
#include"node.h"

#include"bounderException.h"
#include"sizeException.h"
#include"emptylListException.h"


//class iterator;
namespace data_structure {

	template<typename T>
	class list
	{

		std::shared_ptr< node<T> > m_first;// ~ equivalent à node<T>* .		

		void print(std::ostream& out) { //use it within the operator<<.

			std::shared_ptr< data_structure::node<T> > current_node(m_first);
			while (current_node) {
				out << current_node->m_data << std::endl;
				current_node = current_node->m_next;
			}
		}

		
	public:

		list() {
			m_first = nullptr;
		}

		list<T>& operator=(const list<T>& l) {
			if (this != &l) {
				m_first = l.m_first;
			}
			return *this;
		}

		list(const list<T>& l) {
			//std::cout << l[0] << std::endl; error violation accès mémoire
			m_first = l.m_first;
		}

		~list() {
			
		}

		void add(const T& element) {
			if (!m_first) {
				m_first = std::make_shared<node<T> >(element);
				return;
			}
			std::shared_ptr< node<T> > current_node(m_first);
			while (current_node->m_next)
				current_node = current_node->m_next;
			std::shared_ptr< node<T> > new_node = std::make_shared< node<T> >(element);
			current_node->m_next = new_node;
		}

		void print() const {
			
			std::shared_ptr< node<T> > current_node(m_first);
			while (current_node) {
				std::cout << current_node->m_data << std::endl;
				current_node = current_node->m_next;
			}
		}

		void clean() {
			while(m_first)
				m_first = m_first->m_next;
		}

		size_t size() const {

			std::shared_ptr< node<T> > current_node(m_first);
			size_t counter = 0;
			while (current_node) {
				counter++;
				current_node = current_node->m_next;
			}
			return counter;
		}
		
		T& operator[](size_t index) {
			if (index < 0 || index > size()) {
				throw listException::bounderException("exception : out of bounds index.");
			}
			
			std::shared_ptr< node<T> > current_node(m_first);
			size_t count = 0;
			while (current_node) {
				count++;
				if (index == count) {
					return current_node->m_data;
				}
				current_node = current_node->m_next;
			}
			return  current_node->m_data; // optional, to prevent warning C4715: not all control paths return a value.
		}

		const T& operator[](size_t index) const {
			if (index < 0 || index > size()) {
				throw listException::bounderException("exception : out of bounds index.");
			}

			std::shared_ptr< node<T> > current_node(m_first);
			size_t count = 0;
			while (current_node) {
				count++;
				if (index == count) {
					return current_node->m_data;
				}
				current_node = current_node->m_next;
			}
			return  current_node->m_data; // optional, to prevent warning C4715: not all control paths return a value.
		}

		/*
		* removing the top-most item from a list.
		*/
		void pop() { 
			if (!m_first)
				return;
			std::shared_ptr< node<T> > new_list = m_first->m_next;
			m_first = new_list;
		}

		/*
		* deprecated method.(first try).!!!!! not working
		*/
		/*void reverse() {
			size_t size = this->size();
			size_t counter = 1;
			std::shared_ptr< node<T> > current_node(m_first);//pointer.
			std::shared_ptr< node<T> > newlist = std::make_shared< node<T> >();;
			std::shared_ptr< node<T> > pointer_newlist(newlist);
			for (size_t i = size; i > 0; i--) {
				while (current_node) {
					if (counter == i) {
						std::shared_ptr< node<T> > new_node = std::make_shared< node<T> >(current_node->m_data);
						pointer_newlist->m_next = new_node;
						pointer_newlist = pointer_newlist->m_next;
					}
					counter++;
					current_node = current_node->m_next;
				}
				current_node = m_first;
				counter = 1;
			}
			clean();
			m_first = newlist;
		}*/

		/*
		* second method.
		*/

		void reverse() {
			std::vector<T> tempList;
			std::shared_ptr< node<T> > current_node(m_first);
			while (current_node) {
				tempList.push_back(current_node->m_data);
				current_node = current_node->m_next;
			}
			
			clean();//delete current list.

			//Warnning : don't use the size_t type, because it's always positive, so the loop will never end, result: exception will be thrown.
			for (int i = tempList.size() - 1; 0 <= i ; i--) {
				add(tempList.at(i));
			}
				
		}

		bool operator==(const list<T>& l) const  {
			if (size() == l.size()) {
				std::shared_ptr< node<T> > current_node_one(m_first);
				std::shared_ptr <node<T> > current_node_two(l.m_first);
				while (current_node_one) {
					if (current_node_one->m_data != current_node_two->m_data)
						return false;
					current_node_one = current_node_one->m_next;
					current_node_two = current_node_two->m_next;
				}
				return true;
			}
			return false;
		}

		bool operator!=(const list<T>& l) const {//
			if (size() == l.size()) {
				std::shared_ptr< node<T> > current_node_one(m_first);
				std::shared_ptr <node<T> > current_node_two(l.m_first);
				while (current_node_one) {
					if (current_node_one->m_data != current_node_two->m_data)
						return true;
					current_node_one = current_node_one->m_next;
					current_node_two = current_node_two->m_next;
				}
				return false;
			}
			return true;
		}

		list<T> operator+(const list<T>& l) const {
			list<T> result;
			if (size() != l.size())
				throw listException::sizeException("exception : two lists do not have same length.");
			std::shared_ptr< node<T> > current_node_one(m_first);
			std::shared_ptr <node<T> > current_node_two(l.m_first);
			while (current_node_one)
			{
				result.add(current_node_one->m_data + current_node_two->m_data);
				current_node_one = current_node_one->m_next;
				current_node_two = current_node_two->m_next;
			}
			return result;

		}

		list<T> operator+= (const list<T>& l) { //the same idea for operator-=(...).
			if (size() != l.size())
				throw listException::sizeException("exception : two lists do not have same length.");
			std::vector<T> tempList;
			std::shared_ptr< node<T> > current_node(this->m_first);
			std::shared_ptr< node<T> > current_node_two(l.m_first);
			while (current_node)
			{
				tempList.push_back(current_node->m_data + current_node_two->m_data);
				current_node = current_node->m_next;
				current_node_two = current_node_two->m_next;

			}
			clean();

			for (size_t i = 0; i < tempList.size(); i++)
				add(tempList.at(i));

			return *this;

		}

		//operator of conversion return the first element in the list.
		operator T () {

			if (!m_first) {
				throw listException::emptylListException("exception : empty list");
			}
			return m_first->m_data;
		}

		

		
		//if I use const data_structure::list<T>&, this error will be thrown : 2 overloads have no conversion allowed for this pointer.
		template <typename T>
		friend std::ostream& operator<<(std::ostream&, data_structure::list<T>&);

		
		class list_it
		{
			list<T> m_list;
			size_t position;

		public:

			list_it(const list<T>& l) :
				m_list(l), 
				position(0)
			{
				
				
				// m_list.print();
			}

			list_it(const list<T>& l, size_t pos) : 
				m_list(l), 
				position(pos)
			{

			}

			T operator*() {
				std::shared_ptr< node<T> > current_node(this->m_list.m_first);
				size_t counter = 0;
				while (current_node) {
					if (counter == position)
						return current_node->m_data;
					counter++;
					current_node = current_node->m_next;
				}
				return current_node->m_data; // optional to prevent warning C4715: not all control paths return a value.
			}

			const T operator*() const {
				std::shared_ptr< node<T> > current_node(this->m_list.m_first);
				size_t counter = 0;
				while (current_node) {
					if (position == counter)
						return current_node->m_data;
					counter++;
					current_node = current_node->m_next;
				}
			}

			bool operator==(const list_it& it) const {
				return this->position == it.position;
			}

			bool operator!=(const list_it& it) const {
				return this->position != it.position;
			}

			list_it& operator++(int) {
				list_it it(this->m_list);
				position++;
				it.position = position;
				return it;
			}
		};
		

		list_it begin() const {

			return list_it(*this);
		}
		list_it end() const {
			return list_it(*this, size());
		}

	};

	template<typename T>
	inline std::ostream& operator<<(std::ostream& out, data_structure::list<T>& l)
	{
		l.print(out);
		return out;
	}

}


