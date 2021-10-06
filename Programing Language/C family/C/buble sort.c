#include <stdio.h>
#include <stdlib.h>

int a[]={22,10,15,3,8,2};
int b,c,y;

void ascsort(){

for(b=0;b<6-1;b++){
		for(y=0;y<6-1;y++){
			if (a[y+1]<a[y]){
				int dumb=a[y];
				a[y]=a[y+1];
				a[y+1]=dumb;
			}
		}
	}
}



int main() {
	
	prin();
	ascsort();
	prin();

printf ("Hello Donut Burger");
system("pause");
	return 0;
}


int prin(){
	int i;
	for(i=0;i<=5;i++){
	printf(" [%d] ", a[i]);
	}printf("\n\n");
}

