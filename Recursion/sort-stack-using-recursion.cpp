#include<bits/stdc++.h>
#define ll long long
using namespace std;


void insert(stack<int> &st, int key){

	if(st.size() == 0 || key >= st.top()){
		st.push(key);
		return;
	}

	int item = st.top();
	st.pop();

	insert(st, key);

	st.push(item);
}


void sort(stack<int> &st){

	if(st.size() == 1){
		return;
	}

	int val = st.top();
	st.pop();

	sort(st);


	insert(st, val);

}

void printStack(stack<int> &st){

	if(st.size() == 1){
		cout<<st.top()<<" ";
		return;
	}

	int val = st.top();
	st.pop();

	printStack(st);

	cout<<val<<" ";

}



int main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n; cin>>n;

	stack<int> st;
	for(int i=0; i<n; i++){
		int a; cin>>a;
		st.push(a);
	}


	sort(st);


	printStack(st);

	return 0;
}