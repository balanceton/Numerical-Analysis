#include<stdio.h>
#include <math.h>

float hesapla(float arr[10],float kok,int derece){ // fonksiyon deðeri hesaplama
	int i;
	float toplam = 0;
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
	int toplam = 0;
	float katsayilar[10];
	printf("Denklemin derecesini giriniz:");
	scanf("%d",&derece);
	for(i=0;i<=derece;i++){
		printf("Buyukten kucuge katsayilari giriniz:");
		scanf("%f",&katsayilar[i]);
	}	
	
	float kok1,kok2,sonuc1,sonuc2;
	
	do {
		printf("Kok araligini giriniz!");
		scanf("%f %f",&kok1,&kok2);
		sonuc1 = hesapla(katsayilar,kok1,derece);
		sonuc2 = hesapla(katsayilar,kok2,derece);
	}while( sonuc1 * sonuc2 >= 0);
	
	int iterasyon = 0;
	float yenikok,sonuc;
	
    do{
    	iterasyon++;
    	yenikok = (kok1*hesapla(katsayilar,kok2,derece) - kok2*hesapla(katsayilar,kok1,derece)) / (hesapla(katsayilar,kok2,derece) - hesapla(katsayilar,kok1,derece));
    	sonuc = hesapla(katsayilar,yenikok,derece);
    	printf("%f\n",sonuc);
    	sonuc1 = hesapla(katsayilar,kok1,derece);
    	printf("%f\n",sonuc1);
		sonuc2 = hesapla(katsayilar,kok2,derece);
		printf("%f\n",sonuc2);
		if(sonuc*sonuc1 < 0){
			kok2 = yenikok;
		}else if(sonuc*sonuc2 < 0){
			kok1 = yenikok;
		}
		printf(" %f ",kok2-kok1);
	}while(abs(kok2 - kok1)/pow(2,iterasyon) > hata);
	
	printf("En yakin kok degeri:%f",yenikok);
	
	
	return 0;
}
