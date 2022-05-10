#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(string op, string ip){

	//Base Condition : when input length is zero then we get the 
	//output. This can be visualised by creating its recursive
	//tree.

	if(ip.length() == 0){
		cout<<op<<endl;
		return;
	}


	//Logic : Here we have control the number of branches by 
	//using if-else block. if the char is a letter then
	//we call two times one including the lower case and the
	//other including upper case, if there is digit then we
	//simply add it as it is.

	char c = ip[0];

	if(c - '0' >= 49){
		string op1 = op, op2 = op;
		op1.push_back(tolower(c));
		op2.push_back(toupper(c));
		ip.erase(ip.begin()+0);

		solve(op1, ip);
		solve(op2, ip);
	}else{

		string op3 = op;
		op3.push_back(c);
		ip.erase(ip.begin()+0);

		solve(op3, ip);

	}

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