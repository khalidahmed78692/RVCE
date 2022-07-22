#include <iostream>
using namespace std;

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void Heapify(int a[],int n,int i){
	int left=2*i,right=left+1,highest;
	if(left<=n && a[leftv]>a[right])
		highest=left;
	else
		highest=right;
	if(right<=n && a[i]>a[highest])
		highest=i;
	if(highest!=i){
		swap(&a[highest],&a[i]);
		Heapify(a,n,highest);
	}
}
	

void heapify(int a[],int n){
	for(int i=n/2;i>=1;i--)
		Heapify(a,n,i);
}

int main(){
	int n;
	cout<<"Enter the size of the heap: ";
	cin>>n;
	int m=n;
	int a[n],i;
	cout<<"Enter the elements of the heap: ";
	for(i=1;i<=n;i++)
		cin>>a[i];
	heapify(a,n);
	for(i=1;i<=m;i++){
		swap(&a[1],&a[n]);
		n--;
		Heapify(a,n,1);
	}
	cout<<"Heap sorted array is: ";
	for(i=0;i<m;i++)
		cout<<a[i]<<" ";
}
	
