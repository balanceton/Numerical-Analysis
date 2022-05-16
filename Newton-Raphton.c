#include<stdio.h>
#include <math.h>

float hesapla(float arr[10],float kok,int derece){ // fonksiyon deðeri hesaplama
	int i;
	float toplam = 0.0;
	for(i=0;i<derece;i++){
		toplam += arr[i]*pow(kok,derece-i);
	} 
	toplam += arr[derece];
	return toplam;
}

float turevhesapla(float arr[10],float kok,int derece){
	int i;
	for(i=0;i<derece;i++){
		arr[i] = arr[i] * (derece-i);
	}
	float toplam = 0;
	derece--;
	for(i=0;i<derece;i++){
		toplam += arr[i]*pow(kok,derece-i);
	} 
	toplam += arr[derece];
	return toplam;
}

int main(){
	int derece,i;
	float hata;
	printf("Hata duzeyini giriniz:");
	scanf("%f",&hata);
	float katsayilar[10];
	printf("Denklemin derecesini giriniz:");
	scanf("%d",&derece);
	for(i=0;i<=derece;i++){
		printf("Buyukten kucuge katsayilari giriniz:");
		scanf("%f",&katsayilar[i]);
	}	
	
	float kok1,kok2,sonuc1,sonuc2;
	
	printf("Kok araligini giriniz!");
	scanf("%f %f",&kok1,&kok2);

	

	float sonuc,eskikok,a;
	
    do{
    	a = kok1;
    	kok1 = kok1 - hesapla(katsayilar,kok1,derece)/turevhesapla(katsayilar,kok1,derece);
        eskikok = a;
    	
	}while( kok1 - eskikok  > hata);
	
	printf("En yakin kok degeri:%f",kok1);
	
	
	return 0;
}
