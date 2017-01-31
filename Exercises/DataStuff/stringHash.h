#pragma once

class stringHash
{
	const static int TBSIZE = 128;
	class pair
	{
	public:
		string key;
		int value;
		bool isSet = false;
	};

};