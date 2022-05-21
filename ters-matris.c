#include<stdio.h>
#include <math.h>


float birimyap(int x,float arr[x][x],float r[x][x]){
	int i,j,z,w;
	float q;
	// 1-) Alt üçgen haline getir
	for(j=0;j<x;j++){ 
		z = 1;
		for(i=0;i<x;i++){
			if(i != j && i>j){
					q = arr[i][j]/arr[i-z][j];
					for(w=0;w<x;w++){
						arr[i][w] -= arr[i-z][w]*q;
						r[i][w] -= r[i-z][w]*q;
					}	
					z++;
				}
			
			}
		}
	
	// 2-) Köşegenleri 1 yap
	for(i=0;i<x;i++){ 
		for(j=0;j<x;j++){
			if(i==j){
				q = arr[i][j];
					for(w=0;w<x;w++){
						arr[i][w] /= q;
						r[i][w] /= q;
					}	
					
				}
			
			}
		}
	
	// 3-) Üst üçgen matrise çevir
	for(j=x-1;j>=0;j--){ 
		z = 1;
		for(i=x-1;i>=0;i--){
			if(i != j && j>i){
					q = arr[i][j]/arr[i+z][j];
					for(w=0;w<x;w++){
						arr[i][w] -= arr[i+z][w]*q;
						r[i][w] -= r[i+z][w]*q;
					}	
					z++;
				}
			
			}
		}
		
		
		
		
	
	}
	
	

	
	

int main(){
	int x,i,j;
	printf("Bilinmeyen sayisi:");
	scanf("%d",&x);
	float birim[x][x];
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			if(i == j){
				birim[i][j] = 1;
			}else{
				birim[i][j] = 0;
			}
		}
	}
	float mat[x][x];
	float sonuc[x];
	float kokler[x];
	printf("Denklemleri girin\n");
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
	      	printf("Sirayla bilinmeyenlerin katsayilari:");
	      	scanf("%f",&mat[i][j]);
	}
	}
	
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
	      	printf(" %f ",mat[i][j]);
	}
	printf("\n");
	}
	
	birimyap(x,mat,birim);
	printf("\n");
	printf("\n");
	printf("Matrisinizin tersi:");
	printf("\n");
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
	      	printf(" %f ",birim[i][j]);
	}
	printf("\n");
	}
	
	
	

	
	return 0;
}