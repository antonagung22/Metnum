/*
=========================================================
=		Nama  	: I Gusti Nyoman Anton Surya Diputra
=		NIM   	: 1915051027
=		Kelas 	: PTI 3 A
=========================================================
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0

/* 
=================================
=      Program Sederhana        =
=				            	=
=        Newton Raphson         =
=								=				
=   Rumus : 					=
=								=
=   xn+1 = xn - f(xn)/f'(xn)    =
=   f'(xn) != 0					=
=								=
=================================
*/

float a, x, xbef, selisih;
float const error = 0.01;
int i;


float Fungsi(float x){
	// fx = x^2-x-6
	x = (x*x) - x - 6;
	
	return x;
}

float turunanFungsi(float x){
	// fx = 2x - 1
	x = (2 * x) - 1;
	
	return x;
}


void get(float aa){
	i = 0;
	x = a;
	printf("|%-3d| %-7.4f | %-13s |\n", i, x, "---");	
	do{
		i++;
		xbef = x;
		x = x - (Fungsi(x)/turunanFungsi(x));
		selisih = fabs(x-xbef);
		printf("|%-3d| %-7.4f | %-13.4f |\n", i, x, selisih);	
	}while(selisih > error);	
}

void info(){ 
	printf("===============\n");
	printf("= Anton S. <3 =\n");
	printf("===============\n");
}


int main(){
	int ch;
	
	printf("Newton Raphson\n");
	printf("-----------------");
	printf("\n\n");
	
	
	printf("Fungsi :  f(x)  = x^2-x-6\n");
	printf("\t  f'(x) = 2x-1\n\n");
	
	input:
	printf("Masukan Nilai : ");
	scanf("%f", &a);
	
	printf("\n\n");
	printf("-------------------------------\n");
	printf("|%-3s| %-7s |  %-8s  |\n", "i", "Xr", "|Xr+1 - Xr|");
	printf("|%-3s| %-7s |  %-8s  |\n", "---", "---", "-----------");
	get(a);
	
	printf("-------------------------------\n\n");
	printf("Nilai Persamaan  : %.4f\n", x);
	printf("Nilai errornya   : %.4f", selisih);
	printf("\n\n");
	
	ask:
	printf("\n\n\n");
	printf("-----------------------------\n");
	printf("Masukan proses selanjutnya? \n");
	printf("1. Uji lagi\n");
	printf("2. Exit");
	printf("\n");
	printf("Masukan pilihan :");
	scanf("%d", &ch);
	printf("\n");
	switch(ch){
		case 1:
			goto input;
			break;
		case 2:
			goto exit;
			break;
		default:
			system("cls");
			goto ask;
	}

	exit:
		printf("Sekian pengujian Metode Newton Raphson, terima kasih :) \n");
		info();
		exit;
	
	return 0;
}
