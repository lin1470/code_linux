#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int z=1100;
int dp[z],p[z];
int main(){
	int n,i,j,m;
	while(cin>>n&&n!=0){
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++){
			cin>>p[i];}
		sort(p,p+n);
		cin>>m;
		if(m<5){
			cout<<m<<endl;
			continue;}
		else{
			m=m-5;
			for(i=0;i<n-1;i++){
				for(j=m;j>=p[i];j--){
					dp[j]=(dp[j-p[i]]+p[i]) > dp[j] ? (dp[j-p[i]]+p[i]):dp[j];
				}
			}
			cout<<m+5-dp[m]-p[n-1]<<endl;}}
	return 0;
}