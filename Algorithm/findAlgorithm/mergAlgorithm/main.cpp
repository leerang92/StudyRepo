#include <iostream>
#include <string>
#include <cassert>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

void main() {

	string str1 = "aeiou";
	string str2 = "abcdefghijk";
	list<char> list1(str2.begin(), str2.end());

	deque<char> deque1(26, 'x');

	merge(str1.begin(), str1.end(), list1.begin(), list1.end(), deque1.begin());

	cout << "first string : " << str1 << endl;
	cout << "second string : " << str2 << endl;
	cout << "Merge string : ";

	deque<char>::iterator whered;
	for (whered = deque1.begin(); whered != deque1.end(); whered++)
		cout << *whered;
	cout << endl;
}