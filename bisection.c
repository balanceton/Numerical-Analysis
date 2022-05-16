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
	
	do {
		printf("Kok araligini giriniz!");
		scanf("%f %f",&kok1,&kok2);
		sonuc1 = hesapla(katsayilar,kok1,derece);
		sonuc2 = hesapla(katsayilar,kok2,derece);
	}while( sonuc1 * sonuc2 >= 0);
	
	float iterasyon = 0.0;
	float yenikok,sonuc;
	
    do{
    	iterasyon++;
    	yenikok = (kok1+kok2)/2;
    	printf("%f\n",yenikok);
    	sonuc = hesapla(katsayilar,yenikok,derece);
    	printf("sonuc:%f\n",sonuc);
    	sonuc1 = hesapla(katsayilar,kok1,derece);
    	printf("sonuc1:%f\n",sonuc1);
		sonuc2 = hesapla(katsayilar,kok2,derece);
		printf("sonuc2:%f\n",sonuc2);
		if(sonuc*sonuc1 < 0){
			kok2 = yenikok;
		}else if(sonuc*sonuc2 < 0){
			kok1 = yenikok;
		}
		printf("kok farklari: %f\n",kok2-kok1);
	}while((kok2 - kok1)/pow(2.0,iterasyon) > hata);
	
	printf("En yakin kok degeri:%f",yenikok);
	
	
	return 0;
}
