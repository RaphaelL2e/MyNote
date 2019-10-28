#include <iostream>
#include "stdio.h"
#include "math.h"
#include "conio.h"

int test(int x,int y,int z) {
int k = 0, j = 0;
if ((x>0)&&(z<10)) {
		   k = x*y-1;
		   j = sqrt(k);
		}
	if((x==4)||(y>5))
		    j = x*y+10;
j = j % 3;
	   printf("%d ", k);
	   return j;
}

int main(){
	
		int x, y, z;
int n;
	printf("«Î“¿¥Œ ‰»Î x y z");
scanf("%d %d %d", &x, &y, &z);
n = test(x, y, z);
printf("%d",n);
getch();
return 0; 
	

}

