#include "MyQueue.h"

template <typename T>
void CMyQueue<T>::enQueue(T item) {
	if (!isFull()) {
		size++;
		front = (front + 1) % max;
		queue[front] = item;
	}
}

template <typename T>
T CMyQueue<T>::deQueue() {
	if (!isEmpty()) {
		size--;
		rear = (rear + 1) % max;
		return queue[rear];
	}
	return -1;
}