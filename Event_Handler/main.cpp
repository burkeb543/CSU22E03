#include <iostream>
#include <string>
#include <vector>
#include "event.hpp"

using namespace std;

int main() {
  vector<event> vec1; // a vector of events
  vector<event>::iterator k; // to help us walk 
  cout << "Enter the events in year month day:description format, one per line." << endl;
  
  while (cin.eof() == false) {
  	int y, m, d;
  	cin >> y >> m >> d;
  	if (cin.fail() == false) {
			char c;
			cin >> c; // this should be a colon character: ":"
			string s;
			getline(cin,s);
      cout << "Read in: \"" << y << " " << m << " " << d << ":" << s << "\"" << endl;
      event t;
      t.set_event(y, m, d, s);
      // Here, we walk down the vector to find
      // where to insert the new element so as to
      // preserve the date order.
      // We'll use get_date_number() for
      // helping us to order the events.
      if (vec1.empty()) {
        // if the vector is empty, put the new element at the end:
        vec1.push_back(t);
      } else {
        // If the new element is later than the last ("back") element
        // in the vector, put the new element at the end:
        if (t.get_date_number() >= vec1.back().get_date_number()) {
            vec1.push_back(t); // put it at the end
        } else {
          // Otherwise (finally), search through the entries
          k = vec1.begin(); // Start at the very beginning
          // We know the new element can't be later than the last element
          // because we already checked for that.
          // So we know the new element must go somewhere before the last element.
          // That means that we don't have to worry about
          // running past the last element by accident.
          // Instead, we just have to look for the right place.
          while (t.get_date_number() >= k->get_date_number()) {
            // If the incoming date is after the date we are looking at,
            // keep going...
            ++k;
          }
          // We found where it must go, so insert the new item
          vec1.insert(k,t);
        }
      }
      // Diagnostic: print out all the entries in the vector
      // cout <<  "Use a plain old-fashioned index." << endl;
      for (int i = 0; i < vec1.size(); i++) {
        cout << i+1 << ": " << vec1[i].get_description() << endl;
      }
    }
  }
  // Print out the entire vector
  for (k = vec1.begin(); k != vec1.end(); ++k) {
      cout << k->get_year() << "/" << k->get_month() << "/" << k->get_day () << ": " << k->get_description() << endl;
  }
}
