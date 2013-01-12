#ifndef _FILE_H_
#define _FILE_H_

class file
{
public:
	friend ifstream& operator>>(ifstream& in,int num)
	{
		in >> num;
		return in;
	}
};

#endif