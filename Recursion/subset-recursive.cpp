#include<bits/stdc++.h>
#define ll long long
using namespace std;


//This is based on the recursive tree approach

void printSubset(string ip, string op){

	if(ip.size() == 0){
		cout<<"-> "<<op<<endl;
		return;
	}


	string op1, op2;
	op1 = op2 = op;

	op2.push_back(ip[0]);

	printSubset(ip.substr(1, ip.size()-1), op1);
	printSubset(ip.substr(1, ip.size()-1), op2);

}



int main(){


	//freopen("input.txt", "r", stdin);

	//freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string ip;
	cin>>ip;

	string op = "";

	printSubset(ip, op);

	



	return 0;

}