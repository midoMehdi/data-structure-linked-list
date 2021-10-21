#pragma once
#include<iostream>
#include<memory>

template <typename T>
class list ;

namespace data_structure {

	template <typename T>
	class node
	{
		T m_data;
		std::shared_ptr< node<T> > m_next;
		
	public:

		node() {

		}
		node(const node<T>& n) :
			m_data(n.m_data), 
			m_next(n.m_next)
		{

		}
		node(const T& data)
			: m_data(data)
		{
			m_next = nullptr;
		}
		node<T>& operator=(const node<T>& n) {
			if (this != &n) {
				m_data = n.m_data;
				m_next = n.m_next;
			}
			return *this;
		}

		~node() {

		}
		template<typename> friend class list;
		
	};

}


