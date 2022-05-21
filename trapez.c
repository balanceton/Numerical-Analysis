#include<stdio.h>
#include <math.h>
 

float hesapla(float arr[10],float kok,int derece){ // fonksiyon degeri hesaplama
	int i;
	float toplam = 0.0;
	for(i=0;i<derece;i++){
		toplam += arr[i]*pow(kok,derece-i);
	} 
	toplam += arr[derece];
	return toplam;
}



int main(){
	int derece,i,n;
    float delta,kok1,kok2;
	float katsayilar[10];
	printf("Denklemin derecesini giriniz:");
	scanf("%d",&derece);
	for(i=0;i<=derece;i++){
		printf("Buyukten kucuge katsayilari giriniz:");
		scanf("%f",&katsayilar[i]);
	}	
	printf("Kok araligini giriniz:");
    scanf("%f %f",&kok1,&kok2);
    printf("Aralik sayisini giriniz:");
    scanf("%d",&n);
    delta = (kok2-kok1)/n;
    printf("\nkok1:%f\n",kok1);
    printf("\nkok2:%f\n",kok2);
    printf("\ndelta:%f\n",delta);
    float toplam = 0.0;
    for(i=1;i<=n-1;i++){
        toplam += hesapla(katsayilar,kok1+i*delta,derece);
        printf("%f\n",toplam);
    }
    
    toplam += (hesapla(katsayilar,kok1,derece)+hesapla(katsayilar,kok2,derece))/2;
    toplam *= delta;
	
    printf("Sonuc:%f",toplam);

	
		return 0;
}
