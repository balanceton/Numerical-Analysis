#include<stdio.h>
#include<math.h>
 

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
	int derece,i;
	float katsayilar[10];
	printf("Denklemin derecesini giriniz:");
	scanf("%d",&derece);
	for(i=0;i<=derece;i++){
		printf("Buyukten kucuge katsayilari giriniz:");
		scanf("%f",&katsayilar[i]);
	}	
	
	
	
	printf("Degisim oranini giriniz:");
	scanf("%d",&y);


	
		return 0;
}
