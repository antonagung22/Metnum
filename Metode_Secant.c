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
==================================================
=      			Program Sederhana       		 =
=				            				     =
= 	       		 	  Secant      	   			 =
=											     =				
=   Rumus : 								     =
=												 =
=   Xr+1 = Xr - f(Xr)(Xr-Xr-1)/f(Xr)-f(Xr-1)     =
=							                     =
=												 =
==================================================
*/

float a, b, xn1, xn2, x, selisih;
float const error = 0.01;
int i,j;


float Fungsi(float x){
	// fx = x^2-x-6
	x = (x*x) - x - 6;
	
	return x;
}

void get(float aa, float bb){
	i = 0;
	j = 1;
	xn1 = a;
	xn2 = b;
	
	printf("|%-3d| %-7.4f | %-13s | Inisiasi Xr-1 = %-3.0f |\n", i=0, xn2, "---", xn2);	
	printf("|%-3d| %-7.4f | %-13.4f | Inisiasi Xr = %-5.0f |\n", i=1, xn1, fabs(xn2 - xn1), xn1);	
	do{
		i++;
		x = xn1 - ((Fungsi(xn1)*(xn1 - xn2)) / (Fungsi(xn1)  - Fungsi(xn2)));
		selisih = fabs (x - xn1);
		printf("|%-3d| %-7.4f | %-13.4f | Hasil iterasi ke-%-2d | \n", i, x, selisih, j);	
		xn2 = xn1;
		xn1 = x;
		j++;
	}while(selisih > error);	
}

void info(){ 
	printf("===============\n");
	printf("= Anton S. <3 =\n");
	printf("===============\n");
}


int main(){
	int ch;
	
	printf("Metode Secant\n");
	printf("-----------------");
	printf("\n\n");
	
	
	input:
	printf("Masukan Nilai xr - 1: ");
	scanf("%f", &b);
	
	
	printf("Masukan Nilai xr: ");
	scanf("%f", &a);

	
	printf("\n\n");
	printf("-----------------------------------------------------\n");
	printf("|%-3s| %-7s |  %-8s  | %-19s |\n", "i", "Xr", "|Xr+1 - Xr|", "Keterangan");
	printf("|%-3s| %-7s |  %-8s  | %-19s |\n", "---", "---", "-----------", "-----------");
	get(a,b);
	
	printf("-----------------------------------------------------\n\n");
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
		printf("Sekian pengujian Metode Secant, terima kasih :) \n");
		info();
		exit;
	
	return 0;
}
