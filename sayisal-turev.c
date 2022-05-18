#include<stdio.h>
 #include<math.h>
 

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
	int x,y,kok;
	printf("Merkezi fark icin-->1\n");
	printf("Ýleri fark icin-->2\n");
	printf("Geri fark icin-->3\n");
	scanf("%d",x);
	int derece,i;
	float katsayilar[10];
	printf("Denklemin derecesini giriniz:");
	scanf("%d",&derece);
	for(i=0;i<=derece;i++){
		printf("Buyukten kucuge katsayilari giriniz:");
		scanf("%f",&katsayilar[i]);
	}	
	printf("Koku giriniz:");
	scanf("%d",&kok);
	
	
	printf("Degisim oranini giriniz:");
	scanf("%d",&y);
	
	float a,b;
	if(x==1){        
	a=hesapla(katsayilar,kok+y,derece);
	b=hesapla(katsayilar,kok-y,derece);
	printf("Degeriniz:%d",(a-b)/(2*y));
	}else if(x==2){
	a=hesapla(katsayilar,kok+y,derece);
	b=hesapla(katsayilar,kok,derece);
	printf("Degeriniz:%d",(a-b)/(y));
	}else if(x==3){
	a=hesapla(katsayilar,kok,derece);
	b=hesapla(katsayilar,kok-y,derece);
	printf("Degeriniz:%d",(a-b)/(y));
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
