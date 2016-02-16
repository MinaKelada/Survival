#include<time.h>
#include<stdlib.h>
#include"Life.h"
int main(void){
	srand(time(NULL));
	Life Era;
	Era.start();
	return 0;
}