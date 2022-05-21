#include<stdio.h>
#include <math.h>


float altucgen(int x,float arr[x][x],float r[x]){
	int i,j,z,w;
	float q;
	for(j=0;j<x;j++){
		z = 1;
		for(i=0;i<x;i++){
			if(i != j && i>j){
					q = arr[i][j]/arr[i-z][j];
					r[i] -= r[i-z]*q;
					for(w=0;w<x;w++){
						arr[i][w] -= arr[i-z][w]*q;
					}	
					z++;
				}
			
			}
		}
		
	
	}
	
	
	float  coz(int x, float arr[x][x], float r[x]){ // birim matrisi çözme
		int i,j;
		float kokler[x];
		
		for(i=x-1;i>=0;i--){
			for(j=i+1;j<x;j++){
				r[i] -= arr[i][j] * kokler[j];
			}
			kokler[i] = r[i]/arr[i][i];
		}
		
		printf("Sirasiyla kokler:");
	    for(i=0;i<x;i++){
	       	printf("%f ",kokler[i]);
	          }
		
	}
	

int main(){
	int x,i,j;
	printf("Bilinmeyen sayisi:");
	scanf("%d",&x);
	float mat[x][x];
	float sonuc[x];
	float kokler[x];
	printf("Denklemleri girin\n");
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
	      	printf("Sirayla bilinmeyenlerin katsayilari:");
	      	scanf("%f",&mat[i][j]);
	}
	printf("\nSonucu giriniz:");
	scanf("%f",&sonuc[i]);
	}
	
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
	      	printf(" %f ",mat[i][j]);
	}
	printf("   |%f|",sonuc[i]);
	printf("\n");
	}
	
	altucgen(x,mat,sonuc);
	printf("\n");
	printf("\n");
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
	      	printf(" %f ",mat[i][j]);
	}
	printf("   |%f|",sonuc[i]);
	printf("\n");
	}
	printf("\n");
	printf("\n");
    coz(x,mat,sonuc);

	
	return 0;
}