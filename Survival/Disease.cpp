#include<iostream>
#include"Disease.h"
#include"Species.h"
	void Disease::set(){
		strength_ = rand() %101;
		contagious_ = rand() % 101;
		affects_ = rand() % 3; //0 = health, 1 = strength, 2 = speed
	}
	int Disease::infect(Species&){

	}