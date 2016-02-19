#ifndef DISEASE_
#define DISEASE_
#include"Species.h"
class Disease{
	int strength_;
	int contagious_;
	int affects_; //what attribute will it affect
	char affectH_[20];
public:
		Disease();
		Species& infect(Species& C);
		void display();
};
#endif