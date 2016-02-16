#ifndef DISEASE_
#define DISEASE_
#include"Species.h"
class Disease{
	int strength_;
	int contagious_;
	int affects_; //what attribute will it affect
public:
		void set();
		int infect(Species&);

};
#endif