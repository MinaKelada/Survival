#ifndef ENVIRONMENT_
#define ENVIRONMENT_
class Species;
class Environment{
	//food and capacity may be used at a later date to increase pressure on species objects
	int food_;
	int capacity_;
	int type_; //0 for tundra, 1 for forest, 2 for plains, 3 for mountains
	char typeName_[20];
public:
		Environment();
		void setEnv();
		int getType() const;
		void giveEnvironment(Species& spec);
		void display();
		Environment& operator=(const Environment&);

};
#endif