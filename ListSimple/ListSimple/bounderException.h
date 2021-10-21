#pragma once
#include<iostream>
#include<string>
namespace listException {

	class bounderException
	{

		std::string m_message;

	public:

		bounderException(const std::string& message): m_message(message) {

		}

		std::string print() const {
			return m_message;
		}

	};

}


