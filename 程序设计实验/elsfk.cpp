#include<iostream>
#include<fstream>
using namespace std;
int arr[15][10];
int arr2[4][4]; 
int i,j,k,l;
int main (){
	
	
	ifstream file("elsfk.txt");
	//���ļ���ȡ15*10���� 
	for(i=0;i<15;i++){
		for(j=0;j<10;j++){
			file>>arr[i][j];
		}
	}
	//���ļ���ȡ4*4���� 
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			file>>arr2[i][j];
		}
	}
	//���ļ���ȡ���� 
	file>>k;
//	k-=1; 
	for(i=0;i<15;i++){
		for(j=0;j<10;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			cout<<arr2[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<k<<endl;
	
	int a=0;
	//�ж��Ƿ��������
	l=1; 
	while(l){
		
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
//				cout<<arr[i+a][j+k-1] <<" "
//				<<arr2[i][j]
//				<<" |";
				if(arr[i+a][j+k-1]+arr2[i][j]>1){

					l=0;	
				}
			}
		}
		a++;
		if(a==12){
			l=0;
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			arr[i+a][j+k-1]+=arr2[i][j];
		}
	}
	for(i=0;i<15;i++){
		for(j=0;j<10;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	 
	file.close();
	return 0;
} 


