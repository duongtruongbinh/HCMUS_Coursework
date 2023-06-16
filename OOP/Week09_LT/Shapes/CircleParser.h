#include "IParsable.h"
#include "Circle.h"
class CircleParser;

class CircleParser : public IParsable
{
public:
    Object *parse(string);
    string toString();
};