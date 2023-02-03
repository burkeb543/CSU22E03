#pragma once
#include <string>
#include "date.hpp"

class event : public date {
	std::string description;
	public:
	event();
	void set_event(int y, int m, int d, std::string e);
	std::string get_description();
};
