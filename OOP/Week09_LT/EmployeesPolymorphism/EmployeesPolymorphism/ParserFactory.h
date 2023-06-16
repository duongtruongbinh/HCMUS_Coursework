#pragma once
#include "Object.h"
#include "IParsable.h"
#include <map>
class ParserFactory : public Object {
private:
	map<string, IParsable*> _container;

public:
	void registerWith(IParsable* parser);
	IParsable* create(string type);
	string toString();
};

