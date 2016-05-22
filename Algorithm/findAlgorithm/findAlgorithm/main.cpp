#include <iostream>>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

void main() {
	string str = "C++ is better than C";

	string::iterator wheres;
	wheres = find(str.begin(), str.end(), 'e');
	assert(*wheres == 'e' && *(wheres + 1) == 't');
	cout << "String test -- OK" << endl;
}