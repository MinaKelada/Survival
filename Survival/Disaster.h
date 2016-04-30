#ifndef DISASTER_
#define DISASTER_
#include"Species.h"
class Disaster{
	int strength_;
	int speed_; //speed used to see if species can outrun disaster
	char typeName_[20];
public:
	Disaster();
	void reset();
	void setType(const Species& C);
	void affect(Species&);
};
#endif