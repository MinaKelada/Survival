#include<iostream>
#include"Species.h"
#include "Environment.h"
using namespace std;
Species::Species(){
	lifespan_ = rand() % 101;
	health_ = rand()% 101;
	gender_ = rand()% 2;
	strength_ = rand()% 101;
	speed_ = rand()% 101;
	intelligence_ = rand() % 21;
}
void Species::drastic(){

}
void Species::breed(Species&){

}
void Species::mutate(){

}
void Species::fight(Species&){

}
int Species::farm(){
	return 0;

}
int Species::feed(){
	return 0;

}
void Species::change(){
	
}
void Species::injury(){

}
void Species::heal(){

}
void Species::setEnvo(Environment& env){
	envo_ = env;
}
void Species::dead(){
	lifespan_ = 0;
	health_ = 0;
	strength_ = 0;
	speed_ = 0;
}
void Species::displayName(){
	cout << name_ << " ";
}
void Species::displayAtt(){
	cout << lifespan_ << " " << health_ << gender_ << strength_ << speed_ << intelligence_;
}
void Species::displayEnvo(){
	envo_.display();
}