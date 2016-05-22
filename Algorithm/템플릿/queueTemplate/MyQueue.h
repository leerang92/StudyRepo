#pragma once
template <typename T>

class CMyQueue
{
	T *queue;
	int front, rear;
	int max, size;

public:
	CMyQueue(int Max = 100) : front(0), rear(0), max(Max), size(0){
		queue = new T[Max];
	}
	~CMyQueue() { 
		if(queue)
			delete[] queue; 
	}
	void enQueue(T item);
	T deQueue();
	bool isFull() { return size == max; }
	bool isEmpty() { return size == 0; }
};
#include "MyQueue.inl"

