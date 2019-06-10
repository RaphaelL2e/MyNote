
/*【输入输出数据格式】
输入格式：输入的第一行包含一个整数 n，表示学生的数量，学生的学号由 1 到 n 编号。第二行包含
一个整数 m，表示调整的次数。接下来 m 行，每行两个整数 p, q，如果 q 为正，表示学号为 p 的同学向后
移动 q，如果 q 为负，表示学号为 p 的同学向前移动-q。 1 ≤ n，m ≤ 1000
输出格式: 输出一行，包含 n 个整数，相邻两个整数之间由一个空格分隔，表示最终从前向后所有学
生的学号。
样例数据输入:
8
3
3 2
8 -3
3 -2
样例数据输出:
1 2 4 3 5 8 6 7
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int size =0;
	int time =0;
	int p,q,f,j;
	int i =0;
	scanf("%d",&size);
	scanf("%d",&time);
	int line[size];
	for(i=0;i<size;i++){
		line[i]=i+1;	
	}

	for(j=0;j<time;j++){
		scanf("%d %d",&f,&q);
		int k;
		int p,l;
		p=0;
		for(l=0;l<size;l++){
			p++;
			if(line[l]==f){
				break;
			}
		}
		
		
		if(q>0){
			i = 0;
			for(i=0;i<q;i++){	
			k = line[p-1+i];
			line[p-1+i] = line[p+i];
			line[p+i] = k;
			
			}
		}else{
			i = 0;
			q= -q;
			for(i=0;i<q;i++){	
			k = line[p-1-i];
			line[p-1-i] = line[p-2-i];
			line[p-2-i] = k;
			
			}
		}
	
	}
		for(i=0;i<size;i++){
		printf("%d",line[i]);
		}
	

} 
