#include <iostream>
using namespace std;
double findMedianSortedArrays(int A[],int m,int B[],int n){
	if(m==0){
		if(n%2==1){
			return (double)B[n/2];
		}else{
			return ((double)B[n/2-1]+(double)B[n/2])/2;
		}
	}
	if(n==0){
		if(m%2==1){
			return (double)A[m/2];
		}else{
			return ((double)A[m/2-1]+(double)A[m/2])/2;
		}
	}
	int *p= new int[m+n];
	int ai=0;
	int bi=0;
	for(int i=0;i<m+n;++i){
		if(ai==m&&bi<n){
			while(i<m+n){
				p[i++]=B[bi++];
			}
			break;
		}
		if(bi==n&&ai<m){
			while(i<m+n){
				p[i++]=A[ai++];
			}
			break;
		}
		if(A[ai]<B[bi]){
			p[i]=A[ai++];
		}else{
			p[i]=B[bi++];
		}
	}
	if((m+n)%2==1){
		return (double)p[(m+n)/2];
	}else{
		return ((double)p[(m+n)/2-1]+(double)p[(m+n)/2])/2;
	}

}

int main(){
	int A[]={1};
	int B[]={1};
	cout<<findMedianSortedArrays(A,1,B,1)<<endl;
}
