#include<iostream>
#include"Environment.h"
#include"Species.h"
using namespace std;
Environment::Environment(){
	setEnv();
}
void Environment::setEnv(){
	capacity_ = rand() % 1001+100;
	type_ = rand() % 4;
	switch(type_){
	case 0:
		strcpy(typeName_, "Tundra");
		food_ = rand() % 30;
		break;
	case 1:
		strcpy(typeName_, "Forest");
		food_ = rand() % 101;
		break;
	case 2:
		strcpy(typeName_, "Plains");
		food_ = rand() % 101;
		break;
	case 3:
		strcpy(typeName_, "Mountains");
		food_ = rand() % 40; 
		break;
	}
	
}
void Environment::giveEnvironment(Species& spec){
	spec.setEnvo(*this);

}
void Environment::display(){
	cout << "in environment: " << typeName_ << endl;
}
Environment& Environment::operator=(const Environment& other){
	food_ = other.food_;
	type_ = other.type_;
	strcpy(typeName_, other.typeName_);
	return *this;
}
int Environment::getType() const{
	return type_;
}
