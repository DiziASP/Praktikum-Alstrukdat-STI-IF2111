
/*
Nama  : Raden Dizi Assyafadi Putra
NIM   : 18221155
Kelas : 01
*/
#include <stdio.h>

int main(){
	int sec, j, m, d;
	scanf("%d", &sec);
	
	j = (sec/3600); 
	m = (sec-(3600*j))/60;
	d = (sec-(3600*j)-(m*60));
	
	printf("%d detik = %d jam %d menit %d detik\n",sec,j,m,d);
	
	return 0;
}
