#include<ctime>
#include<cstdlib>
#include"Life.h"
#include"Tester.h" //will be removed after completion
int main(void){
	srand(time(NULL));
	Tester Joe;
	//Joe.genTest();
	//Joe.feedTest();
//	Joe.deadBreed();
	Joe.fightTest();

	return 0;
}