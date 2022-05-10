#include<bits/stdc++.h>
#define int int64_t
#define pb emplace_back
using namespace std;


void solve(string op, string ip){

	//base condition : when input is zero we get a output.

	if(ip.size() == 0){
		cout<<op<<"\n";
		return;
	}

	//hypothesis : we iterate over the input string and select 
	//one character and we have a remaining string which does
	//not incl. that letter. for our next recursive call we 
	//iterate over the remaining string which is then called 
	//the input and then select a character from that string 
	//and push it to the output and reduce the input string.


	//Can be better understood by drawing a recursive tree.

	for(int i=0; i<ip.size(); i++){
		string op1 = op;
		op1.push_back(ip[i]);
		string tmp = ip;
		tmp.erase(tmp.begin()+i);
		solve(op1, tmp);
	}

}


int32_t main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin>>s;

	solve("", s);

	return 0;
}