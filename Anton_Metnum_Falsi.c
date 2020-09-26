#include <stdio.h>
#include <conio.h>
#include <math.h>

#define true 1 // boolean logika
#define false 0

float a,b,c,fa,fb,fc, err; // variabel yang digunakan dalam perhitungan
float tol, temp, konGalat;
const float epsilon = 0.0001;
int i = 0;

float Fungsi(float x){ //fungsi untuk mencari akar f(x) = x^2 - 12
	x *= x;
    x -= 12;
	return x;
}

void print(){ // fungsi cetak
	printf("|%-3d | %-10.5f| %-10.5f| %-10.5f| %-10.5f| %-10.5f| %-10.5f| %-10.5f|", i, a, b, c, fa, fb, fc, konGalat);
} 
void info(){ 
	printf("===============\n");
	printf("= Anton S. <3 =\n");
	printf("===============\n");
}

void getAll(float aa, float bb){ // fungsi untuk melakukan perhitungan

	fa = Fungsi(a); // variabel untuk menampung kembalian proses dari Fungsi fx
	fb = Fungsi(b);
	temp = fc * fb;
	err = tol * epsilon;

	if(fa*fb < 0){
		do{
		c = b-((fb)*(b-a))/(fb-fa); // rumus regula falsi
	
		fc = Fungsi(c); 
		konGalat = fabs(a-b); // menghitung lelaran yang didapat
	
		print();
		i++; // implementasi iterasi
	
		if ((fc*fa) < 0){ // jika fc * fa < 0 maka b = c, fb = fc 
			b = c;
			fb = fc;
		} else if((fc*fb) < 0){ // jika fc * fb < 0 maka a = c, fa = fc
			a = c;
			fa = fc;
		}
			
	/* Perulangan untuk menampilkan Selang baru */
	
		if ((fc*fa) < 0 && fabs(fc) > err){ 	
			printf("[a,b] \t|");
		} else if((fc * fb) < 0 && fabs(fc) > err){
			printf("[c,b] \t|");
		}else{
			printf("--- \t \t|");
		}

	/* Perulangan untuk menampilkan keterangan */
	
		if(fabs(fc) > err){
			printf("Iterasi Lanjut |");
		}else{
			printf("Iterasi Stop   |");
		}
		
		printf("\n");
		}while (fabs(fc) > err); // while abs(fc) > err, maka hentikan perulangan
	
		printf("\n");
		printf("Akar yang di dapat : %.5f", c); // menampilkan akar yang didapat

	}else{
		printf("Tidak ada akar yang didapat");
	}
	getchar();	
}

/* Main Program */

int main(){ 
	printf("Regula Falsi	 \n");
	printf("-----------------\n");
	printf("\n");
	printf("Input batas atas   : ");
	scanf("%f", &a);
	printf("Input batas bawah  : ");
	scanf("%f", &b);
	printf("Batas Toleransi    : ");
	scanf("%f", &tol);
	printf("\n");
	konGalat = a; // Variabel yang akan diproses oleh Fungsi getAll untuk mencari lelaran
	printf("|%-3s | %-10s| %-10s| %-10s| %-10s| %-10s| %-10s| %-10s| %-13s| %-14s|", "i", "a", "b", "c", "f(a)", "f(b)", "f(c)","Lelaran", "Selang Baru", "Keterangan");
	printf("\n");
	printf("|%-3s | %-10s| %-10s| %-10s| %-10s| %-10s| %-10s| %-10s| %-13s| %-14s|", "---", "---", "---", "---", "---", "---", "---","---", "---", "---");
	printf("\n");	
	getAll(a,b);
	printf("\n\n"); info(); //info_pembuat
	
	return 0;
}


