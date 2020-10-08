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

#define true 1 // boolean logika
#define false 0

float a, x, fx, xbef, selisih;
float const error = 0.01;
int i;



float Fungsi1(float x){	
/* I.S = terdefinisi (a)
   F.S = Pengembalian nilai dari 
   x = sqrt(x+6) 
*/   
	x = sqrt(x+6);
	
	return x;
}

float Fungsi2(float x)
/* I.S = terdefinisi (a)
   F.S = Pengembalian nilai dari 
	x = x^2-6
*/
{	
	x = ((x*x)-6);
	
	return x;
}

float Fungsi3(float x)
/* I.S = terdefinisi (a)
   F.S = Pengembalian nilai dari 
	x = 6/(x-1)
*/
{
	x = 6/(x-1);
	return x;
}

void get(float aa){
	i = 0;
	x = a;
	printf("|%-3d| %-5.4f | %-13s |\n", i, x, "---");	
	do{
		i++;	
		xbef = x;
		x = Fungsi1(x);
		ceil(selisih = fabs(x-xbef));
		printf("|%-3d| %-5.4f | %-13.4f |\n", i, x, selisih);
	}while(selisih > error);	
}

void get1(float aa){
	i = 0;
	x = a;
	printf("|%-3d| %-7.4f | %-10s |\n", i, x, "---");	
	do{
		i++;
		xbef = x;
		x = Fungsi2(x);
		selisih = fabs(x-xbef);
		printf("|%-3d| %-5.4f | %-10.4f |\n", i, x, selisih);	
	}while(selisih > error);	
}

void get2(float aa){
	i = 0;
	x = a;
	printf("| %-3d| %-6.4f  | %-11s |\n", i, x, "---");
	do{
		i++;
		xbef = x;
		ceil(x = Fungsi3(x));
		ceil(selisih = fabs(x-xbef));
		printf("| %-3d| %-7.4f | %-11.4f |\n", i, x, selisih);	
	}while(selisih > error);	
}

void info(){ 
	printf("===============\n");
	printf("= Anton S. <3 =\n");
	printf("===============\n");
}


int main(){

int ch;
	
printf("Lelaran Titik Tetap.exe\n");
printf("---------------------\n\n\n");
input:
printf("Pilih metode dibawah ini : \n");
printf("1. Bentuk 1 (x = sqrt(x+6))\n");
printf("2. Bentuk 2 (x = x^2 - 6) \n");
printf("3. Fungsi 3 (x = 6/(x-1)))\n");

printf("Masukan pilihan : ");
scanf("%d", &ch);


printf("\n");
printf("--------------------------\n");

if(ch!=1 && ch!=2 && ch!=3) goto input;
else
	if(ch == 1){
		printf("Masukan nilai x : ");
		scanf("%f", &a);
		printf("-------------------------\n\n");
		printf("Tabel 2. Hasil lelaran fungsi \nx = g(x) -> x = sqrt(x+6) \n\n");
		printf("-----------------------------\n");
		printf("|%-3s| %-6s |  %-8s  |\n", "i", "x(i)", "x(i)+1-x(i)");
		printf("|%-3s| %-6s |  %-8s  |\n", "---", "---", "-----------");
		//pemanggilan fungsi bentuk ke 1
		get(a);	
		printf("------------------------------\n\n");
		printf("Nilai Persamaan  : %.4f\n", x);
		printf("Nilai errornya   : %.4f", selisih);
		
	}else if(ch == 2){
		printf("Masukan nilai x : ");
		scanf("%f", &a);
		printf("-----------------------\n\n");
		printf("Tabel 3. Hasil lelaran fungsi \nx = g(x) -> x = x^2-6 \n\n");
		printf("----------------------------\n");
		printf("|%-3s| %-7s | %-6s|\n", "i", "x(i)", "x(i)+1-x(i)");
		printf("|%-3s| %-7s | %-6s|\n", "---", "---", "-----------");
		//pemanggilan fungsi bentuk ke 2
		get1(a);	
		printf("----------------------------\n\n");
		printf("Nilai Persamaan  : %.4f\n", x);
		printf("Nilai errornya   : %.4f", selisih);
	}else if(ch==3){
		printf("Masukan nilai x : ");
		scanf("%f", &a);
		printf("-----------------------\n\n");
		printf("Tabel 4. Hasil lelaran fungsi \nx = g(x) -> x = 6 / (x-1) \n\n");
		printf("-----------------------------\n");
		printf("|%-3s | %-7s | %-7s |\n", "i", "x(i)", "x(i)+1-x(i)");
		printf("|%-3s | %-7s | %-7s |\n", "---", "---", "-----------");
		//pemanggilan fungsi bentuk ke 3
		get2(a);	
		printf("-----------------------------\n\n");
		printf("Nilai Persamaan  : %.4f\n", x);
		printf("Nilai errornya   : %.4f", selisih);
	}

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
		printf("Sekian pengujian lelaran titik tetap, terima kasih :) \n");
		info();
		exit;

return 0;
}
