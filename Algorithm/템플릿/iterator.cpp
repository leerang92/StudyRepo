#include <iostream>
#include <cassert>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

int main()
{
	cout << " : " << flush;
	istream_iterator<string> in(cin);
	ostream_iterator<string> out(cout, " ");

	copy(in, istream_iterator<string>(), out);

	//istreambuf »ç¿ë
	/*istreambuf_iterator<char> in(cin);
	istreambuf_iterator<char> eos;
	ostream_iterator<char> out(cout, "");

	copy(in, eos, out);*/
	
	return 0;
}