#include "stdio.h"
#include "math.h"
#define true 1
#define false 0



float a, b, c,fa, fb,fc, cBef = 0, konGalat;
int last = true;
int i = 0;

double galat = 0.04;

float fx(float x) {
    x *= x;
    x -= 12;

    return x;
}
void print(){
	printf("|%-3d | %-10f| %-10f| %-10f| %-10f| %-10f| %-10f| %-10f|\n", i, a, b, c, fa, fb, fc, konGalat);
}

void getAll(float aa, float bb){
	c = (a + b) / 2;
	fa = fx(a);
	fb = fx(b);
	fc = fx(c);
	    
	print();
	i++;
	konGalat =konGalat / 2;
	cBef = c;
	if (fa * fc > 0) a = c;
	else b = c;
	if(konGalat > galat) {
		getAll(a, b);
	}else if(last){
		last = false;
		getAll(a, b);
	}
}
int main(){
	printf("Masukan nilai atas: ");
	scanf("%f", &a);
	printf("Masukan nilai bawah: ");
	scanf("%f", &b);
	konGalat = a;

	printf("|%-3s | %-10s| %-10s| %-10s| %-10s| %-10s| %-10s| %-10s|\n", "i", "a", "b", "c", "f(a)", "f(b)", "f(c)","Lelaran");
	getAll(a, b);
	printf("Akar yang di dapat : %f", c);
	printf("galat : %lf", galat);
	
	
}


