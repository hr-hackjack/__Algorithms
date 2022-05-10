#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve(string op, int open, int close){

	//Base Condition : it remains the same as any other IP-OP
	//problem. we get output when input is zero.

	if(!open && !close){
		cout<<op<<endl;
		return;
	}

	//equal condition means that already the subset of brackets
	//are balanced and the only option is to start a new set of 
	//brackets by adding '(' bracket.

	if(open == close){
		string op1 = op;
		op1.push_back('(');
		solve(op1, open-1, close);
	}

	//when all open brackets are gone, we can only add closing 
	//brackets.

	if(!open){
		string op1 = op;
		op1.push_back(')');
		solve(op1, open, close-1);
	}

	//for rest of the cases there are two options either add a
	//closing bracket or adding an opening bracket.

	if(close > open && open){

		string op1=op, op2=op;
		op1.push_back('(');
		solve(op1, open-1, close);

		op2.push_back(')');
		solve(op2, open, close-1);
	}

}



int main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin>>n;

	string op = "";
	solve(op, n, n);

	return 0;
}