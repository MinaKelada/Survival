#include<iostream>
#include"Disaster.h"
#include"Species.h"
using namespace std;
Disaster::Disaster(){
	reset();
}
void Disaster::affect(Species& C){
	//safely affects the species object based on the environment that it is in
	if (C.isNotDead()){
		setType(C);
		if (C.getSpeed() < speed_){
			cout << C.displayName() << " was caught in " << typeName_ << endl;
			cout << "This reduced " << C.displayName() << "'s health by " << strength_ << endl;
			C.reduceStats(0, strength_);
			C.injury(strength_);
		}
	}
}
void Disaster::setType(const Species& C){
	//sets type based on species' environment
	switch (C.getType()){
	case 0:
		strcpy(typeName_, "an avalanche");
		break;
	case 1:
		strcpy(typeName_, "a forest fire");
		break;
	case 2:
		strcpy(typeName_, "an earthquake");
		break;
	case 3:
		strcpy(typeName_, "a land slide");
		break;
	}
}
void Disaster::reset(){
	//resets disaster so that it can be continously used in loop
	strength_ = rand() % 31;
	speed_ = rand() % 51;
}