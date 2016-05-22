#include <iostream>
#include <vector>
#include <list>
#include <cassert>
#include <numeric>
#include <algorithm>
using namespace std;

void main() {
	int x[5] = { 2,3,5,7,11 };
	
	//일반적인 방법
	int intsum = 0;
	for (int i = 0; i < 5; i++)
		intsum += x[i];

	//vector를 사용한 방법
	vector<int>vector1(&x[0], &x[5]);
	int sum = accumulate(vector1.begin(), vector1.end(), 0);
	assert(sum == intsum);
	cout << "vector를 이용한 accumuate 결과 : " << sum << endl;

	//list를 사용한 방법
	float y[5] = { 2.0f, 3.0f, 5.0f, 7.0f, 11.1f };
	float sum1;
	list<float> list1(&y[0], &y[5]);
	sum1 = accumulate(list1.begin(), list1.end(), 0.0f);
	cout << "list를 이용한 accumuate 결과 : " << sum1 << endl;
}