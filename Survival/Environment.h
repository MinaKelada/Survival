#ifndef ENVIRONMENT_
#define ENVIRONMENT_
#include"Species.h"
class Environment{
	int food_;
	int capacity_;
	int type_; //0 for tundra, 1 for forest, 2 for plains, 3 for mountains
	char typeName_[20];
public:
		void setEnv();
		void giveEnvironment(Species []);
		void display();

};
#endif