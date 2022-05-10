#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve(string op, int ones, int zeroes, int total){

	//Base Condition : When no of digits remaining are zero 
	//we will get our output.

	if(total == 0){
		cout<<op<<"\n";
		return;
	}

	//Logic : there is no restriction on adding '1' to 
	//output so we have to add '1' everytime. The restriction is
	//however with '0'. we can add '0' only when no of '1' are 
	//greater '0' because only then prefix will have more '1' or
	//at max equal '1' as compared to '0'.

	string op1 = op;
	op1.push_back('1');
	solve(op1, ones+1, zeroes, total-1);

	if(ones > zeroes){
		string op1 = op;
		op1.push_back('0');
		solve(op1, ones, zeroes+1, total-1);
	}

}



int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin>>n;

	string op = "";
	solve(op, 0, 0, n);

	return 0;
}