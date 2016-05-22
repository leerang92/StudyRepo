#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

void main()
{
	vector<int> vector1(5, 9);
	list<int> list1;

	merge(vector1.begin(), vector1.end(),
		istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(list1));

	merge(vector1.begin(), vector1.end(),
		list1.begin(), list1.end(), ostream_iterator<int>(cout, " "));

}