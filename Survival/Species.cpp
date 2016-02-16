#include<iostream>
#include"Species.h"
#include "Environment.h"
void Species::set(){
	lifespan_ = rand() % 101;
	health_ = rand()% 101;
	gender_ = rand()% 2;
	strength_ = rand()% 101;
	speed_ = rand()% 101;
	
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

}
int Species::feed(){

}
void Species::change(){

}
void Species::injury(){

}
void Species::heal(){

}
void Species::setEnvo(Environment& env){
	envo = env;
}
void Species::dead(){
	lifespan_ = 0;
	health_ = 0;
	strength_ = 0;
	speed_ = 0;
}