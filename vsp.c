#include<stdio.h>
#include<time.h>
void merge(int arr[],int left,int mid,int right){
	int n1=mid-left+1;
	int n2=right-mid;
	int leftarr[n1],rightarr[n2];
	for(int i=0;i<n1;i++){
		leftarr[i]=leftarr[left+i];
	}
	for(int j=0;j<n2;j++){
		rightarr[j]=rightarr[mid=+1+j];
	}
	int i=0,j=0,k=left;
	while(i<n1 &&j<n2){
		if(leftarr[i]<=rightarr[j]){
			arr[k]=leftarr[i];
			i++;
		}
		else
		{
			arr[k]=rightarr[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k]=leftarr[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=rightarr[j];
		j++;
		k++;
	}
}
void mergesort(int a[],int left,int right){
	if(left<right){
		int mid=left+(right-left)/2;
		mergesort(a,left,mid);
		mergesort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}

	
void printArray(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(){
	int n;
	printf("Enter the size\n");
	scanf("%d",&n);
	int a[n],l=0,h=n-1;
	printf("Enter the array elements\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	clock_t start=clock();
	mergesort(a,l,h);
	clock_t end=clock();
	printArray(a,n);
	double t=((double)(end-start)/CLOCKS_PER_SEC);
	printf("time taken is %f sec",t);
	return 0;
}
