#include "Callback.h"

void Callback::setCallback(CallbackType cb, void* data)
{
	this->mCallback = cb;
	this->mClosure = data;
}

void Callback::invokeCallback()
{
	if (mCallback != nullptr)
	{
		(*mCallback) ("Hello World", mClosure);
	}
}
