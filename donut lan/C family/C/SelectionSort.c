#include <stdlib.h>
#include <stdio.h> 

//Silvanus Prihantono
//20081010223

//unfinished

int a[]={32,75,69,58,21,40};
int pos,c,y,z,min;
int isi=sizeof(a)/sizeof(a[0]);


swap();

//bug olgorithm
void selsot(){
int min=a[0];

for(pos=0;pos<isi-1;pos++){
	min=a[pos];
		for(y=0;y<isi;y++){
			if(a[y]<a[min]){
			
			}
		
		}
		swap();
	}
}



int swap(){
if (pos!=min){
				int dumb=a[min];
				a[min]=a[pos];
				a[pos]=dumb;
	}
}



int main() {
	
	prin();
	selsot();
	prin();
 
system("pause");
	return 0;
}




int prin(){
	int i;
	for(i=0;i<isi;i++){
	printf(" [%d] ", a[i]);
	}printf("\n\n");
}