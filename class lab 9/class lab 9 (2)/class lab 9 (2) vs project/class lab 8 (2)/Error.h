#pragma once

class Error
{
private:

	const char* msg = "Unknown error";
public:

	Error(const char* msg)
	{
		this->msg = msg;
	}
	const char* what()
	{
		return this->msg;
	}
};
