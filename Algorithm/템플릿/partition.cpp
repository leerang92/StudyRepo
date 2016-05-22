#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

bool above40(int n) { return (n > 40); }

int main()
{
	const int N = 7;
	int array0[N] = { 50, 30, 10, 70, 60, 40, 20 };
	int array1[N];
	copy(&array0[0], &array0[N], &array1[0]);
	ostream_iterator<int> out(cout, " ");
	
	int* split = partition(&array1[0], &array1[N], above40);
	cout << "Result:";
	copy(&array1[0], split, out); cout << " | ";
	copy(split, &array1[N], out); cout << endl;

	//array1의 값을 원상복귀
	copy(&array0[0], &array0[N], &array1[0]);
	split = stable_partition(&array1[0], &array1[N], above40);

	cout << "Result:";
	copy(&array1[0], split, out); cout << " | ";
	copy(split, &array1[N], out); cout << endl;

	return 0;
}