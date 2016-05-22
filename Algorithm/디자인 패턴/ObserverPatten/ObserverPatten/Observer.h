#pragma once
class CObserver
{
public:

	CObserver()
	{
	}

	~CObserver()
	{
	}

	virtual void update(int temp, int humidity, int pressure) = 0;
};

