#include "OneSpaceOnly.h"

string OneSpaceOnly::toString()
{
	return "OneSpaceOnly";
}

string OneSpaceOnly::rename(string name)
{
	while (name[0] == ' ' ) name.erase(name.begin());
	for (int i = 1; i < name.length(); i++)
	{
		if (name[i - 1] == ' '&&name[i]==' ')
		{
			name.erase(i,1);
			i--;
		}
	}
	return name;
}