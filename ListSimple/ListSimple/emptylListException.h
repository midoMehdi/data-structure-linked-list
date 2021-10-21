#pragma once
#include<iostream>
#include<string>
namespace listException {

	class emptylListException
	{
		std::string m_message;

	public:
		emptylListException( const std::string& message) : m_message(message) {

		}
		
		std::string print() const {
			return m_message;
		}
	};
}


