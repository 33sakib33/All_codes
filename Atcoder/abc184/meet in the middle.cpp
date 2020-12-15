#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  vector<int> a(n,0);

  vector<int> subsets;
  for(int i=0;i<(2<<n);i++){
  	int temp=i;
  	int sum1=0;
  	for(int j=0;j<n;j++){
  		if(temp & 1){
  			sum1=sum1+a[j];
  		}
  		temp=temp>>2;
  	}
  	subsets.push_back(sum1);
  }
}
