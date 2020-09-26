#include "stdio.h"
#include "math.h"
#define true 1
#define false 0



float a, b, x, fx, h;

void print(){
	printf("|%-5.2f | %-10f|\n", x, fx);
}
void header(){
	printf("====================\n");
	printf("|%-5s | %-10s|\n", "x", "f(x)");
	printf("====================\n");
}
float f(float xx) {
	float e = 2.719;
    fx = powf(e, xx);
    fx -= (5 * (powf(xx, 2)));
}
int main(){	
	printf("Masukan nilai batas atas     : ");
	scanf("%f", &a);
	printf("Masukan nilai batas bawah    : ");
	scanf("%f", &b);
	printf("Masukan nilai kenaikan : ");
	scanf("%f", &h);
	
	header();
	for(a; a <= b; a+=h){
		x = a;
		f(x);
		print();
	}
	x = a;
	f(x);
	print();
	printf("====================\n");
}
