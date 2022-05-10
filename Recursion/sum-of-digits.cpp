#include<bits/stdc++.h>
#define int int64_t
#define pb emplace_back
using namespace std;


int digit_sum(int k){

	if(k <= 0){
		return 0;
	}

	return digit_sum(k/10) + k%10;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin>>n;

	cout<<digit_sum(n)<<endl;
	return 0;
}