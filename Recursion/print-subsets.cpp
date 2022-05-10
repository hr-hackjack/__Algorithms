#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve(string op, string ip){

	//Base Condition : whenever ip becomes zero then only we
	//get an output.

	if(ip.length() == 0){
		cout<<op<<endl;
		return;
	}

	//either we add a character along with a space or we dont
	//then we separately call solve for both the cases.

	string op1 = op, op2 = op;
	op1.push_back('_');
	op1.push_back(ip[0]);

	op2.push_back(ip[0]);

	ip.erase(ip.begin()+0);

	//Recursive Nodes : we call the solve() for smaller inputs

	solve(op1, ip);
	solve(op2, ip);

}



int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string ip;
	cin>>ip;

	string op = "";



	op.push_back(ip[0]);
	ip.erase(ip.begin()+0);

	solve(op, ip);

	return 0;
}