#pragma once
#include "Observer.h"

class CSubject
{
public:

	CSubject()
	{
	}

	~CSubject()
	{
	}

	virtual void registerObsever(CObserver *) = 0;
	virtual void removeObserver(CObserver *) = 0;
	virtual void notifyObservers() = 0;
};

