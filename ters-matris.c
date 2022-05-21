#include<stdio.h>
#include <math.h>

int minor(int x,int y,int arr[3][3]){
	int i,j;
	int minor[4];
	int minor2[2][2];
	int q = 0;
	for(i=0;i<3;i++){
		if(i != x){
		for(j=0;j<3;j++){
			if(j != y){
        minor[q] = arr[i][j];
		q++;
			}
		}
		}
	}
	q = 0;
    for(i=0;i<2;i++){
		for(j=0;j<2;j++){
            minor2[i][j] = minor[q];
			q++; 
		}
	}
     return minor2;
}

int determinant2(int arr[2][2]){
	int toplam=0;
	toplam += arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0];
	return toplam;
}

int determinant3(int x,int arr[x][x]){ //determinant hesaplama 
	int i;
	int det = 0;
	for(i=0;i<3;i++){
		det += pow(-1,i)*determinant2(minor(1,i,arr));
	}
	return det;
}

int transpoz(int x,int arr[x][x]){
	int i,j,a;
	for(i=0;i<x;i++){
		for(j=i;j<x;j++){
          a = arr[i][j];
		  arr[i][j] = arr[j][i];
		  arr[j][i] = a;
		}
	}
	return arr;
}

int main(){
	int x,i,j,determinant;
	printf("matrisinizin buyuklugunu giriniz:");
	scanf("%d",&x);
	int mat[x][x];
	int minormat[x][x];
	printf("Matris elemanlarini giriniz:\n");
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
	    	scanf(" %d",&mat[i][j]);
	  }
	    	printf("\n");
	}
	
	// 1-)Transpozu al
    transpoz(x,mat);

	// 2-)Determinantı hesapla
    determinant = determinant3(x,mat);
    printf("\ndeterminant:%d \n",determinant);

	// 3-) Her bir 2x2 minor için det bul
     for(i=0;i<x;i++){
		for(j=0;j<x;j++){
	    	minormat[i][j] = determinant2(minor(i,j,mat));
	  }
	}

	// 4-) Kofaktör matrisi oluştur
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
	    	if((i+j) % 2 != 0){
				minormat[i][j] *= -1;
			}
	  }
	}

	// 5-) Her bir elemanı determinanta böl

	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
	    	minormat[i][j] = minormat[i][j] / determinant;
	  }
	}

    for(i=0;i<x;i++){
		for(j=0;j<x;j++){
	    	 printf(" %d ",minormat[i][j]);
	  }
	  printf("\n");
	}
	

	
	
	
	
	return 0;
	}