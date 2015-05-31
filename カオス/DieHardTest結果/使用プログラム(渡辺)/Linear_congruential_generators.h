#include <cmath>

void LCGs(unsigned int sn, int num, int* date){
	int x[2] = {sn, 0};
	int A = 1103515245, B = 12345, M = 2147483648;
	for(int i = 0 ; i < num; i++){
		x[1] = (A * x[0] + B) % M;
		x[0] = x[1];
		date[i] = x[1];
	}
}