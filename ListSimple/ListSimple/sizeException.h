#pragma once
#include<iostream>
#include<string>
namespace listException {
	class sizeException
	{
		std::string m_message;
	public:
		sizeException(const std::string& message) : m_message(message) {

		}

		std::string message() const {
			return m_message;
		}
	};
}


