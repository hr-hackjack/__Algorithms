#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve(string op, string ip){

	//Base Condition : when the input field is empty you will
	//get the output. This logic can be seen by making the 
	//recursive tree.

	if(ip.length() == 0){
		cout<<op<<endl;
		return;
	}

	//Logic : creating two op strings one will contain the upper
	//case of first letter of input and the other will contain 
	//the lower case.

	string op1 = op, op2 = op;
	char c = ip[0];

	op1.push_back(toupper(c));
	op2.push_back(c);

	ip.erase(ip.begin()+0);

	//We will call the function for the two different op strings.

	solve(op1, ip);
	solve(op2, ip);

}



int main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string ip;
	cin>>ip;

	string op = "";

	solve(op, ip);

	return 0;
}