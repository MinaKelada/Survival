#include<ctime>
#include<cstdlib>
#include"Life.h"
int main(void){
	srand(time(NULL));
	Life life;
	life.noUser();

	return 0;
}