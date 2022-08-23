#include<iostream>
#include <fstream>
using namespace std;
int main() {
	int n,k;
	cin>>n>>k;
	int *a=new int[n];
	for(int i=0; i<n; i++) {
		a[i]=i+1;
	}
	int num=n;
	int j=1;//±¨Êý
	int xb=0;
	while(num!=1) {
		if(a[xb]!=0) {
			if(j%k==0||j%10==k) {
				j++;
				a[xb]=0;
				num--;
			} else {
				j++;
				xb=(xb+1)%n;
				continue;
			}
		} else {
			xb=(xb+1)%n;
		}
	}
	for(int i=0; i<n; i++) {
		if(a[i]!=0) {
			cout<<a[i];
		}
	}
	return 0;
}

