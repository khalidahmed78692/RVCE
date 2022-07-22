#include <iostream>
using namespace std;

int count=0;

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void Heapify(int a[],int n,int i){
	int left=2*i,right=left+1,highest;
	count++;
	if(left<=n && a[left]>a[i])
		highest=left;
	else
	    highest=i;
	count++;
	if(right<=n && a[right]>a[highest])
		highest=right;
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
	int m=n,a[n],i;
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
	for(i=1;i<=m;i++)
		cout<<a[i]<<" ";
}
