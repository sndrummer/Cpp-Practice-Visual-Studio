#pragma once
#include <string>

class Callback
{
public:
	typedef void (*CallbackType) (const std::string& name, void* data);
	void setCallback(CallbackType cb, void* data);

	void invokeCallback();

private:
	CallbackType mCallback;
	void* mClosure;
};

