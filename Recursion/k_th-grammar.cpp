#include<bits/stdc++.h>
#define ll long long
using namespace std;



int bitAt(int n, int k){

	//Base Condition :- this was already given in the question

	if(n == 1 && k == 1){
		return 0;
	}

	//Hypothesis :- our func bitAt() will return the bit at (n, k) 
	//position and induction is the return statement. 


	//Observation :- here we observe on each row the first half is equal 
	//to the last entire row and the second half is the inverse of 
	//entire last row. so we divide our question in 2 parts and solve it.
	int len = pow(2, n-1);
	int mid = len/2;

	if(k > mid){
		return !bitAt(n-1, k-mid);
	}else{
		return bitAt(n-1, k);
	}

}





int main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k; cin>>n>>k;
	cout<<bitAt(n, k);


	return 0;
}