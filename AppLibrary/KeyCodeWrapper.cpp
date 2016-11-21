#include "stdafx.h"
#include "KeyCodeWrapper.h"
#include <boost/algorithm/string.hpp>

KeyCodeWrapper::KeyCodeWrapper()
{
}


KeyCodeWrapper::~KeyCodeWrapper()
{
	//this->keys.clear();
	//delete this;
}

KeyCodeWrapper::KeyCodeWrapper(string value)
{
	vector<string> str; 
	vector<uint> data;
	boost::split(str, value, boost::is_any_of("+"));
	for (string s :  str)
	{
		if (s != str.back())
		data.push_back(codes[s]);
	}
	//string lst{ str.back() };
	Action act = this->action[str.back()];
	keys[act] = data;
	str.erase(str.begin(), str.end());
}

