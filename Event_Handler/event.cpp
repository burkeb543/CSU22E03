#include "event.hpp"

using namespace std;

event::event() : date() {
	description = "<no description>";
}

void event::set_event(int y, int m, int d, string e) {
	set_date(y, m, d);
	description = e;
}

string event::get_description() {
	return description;
}
