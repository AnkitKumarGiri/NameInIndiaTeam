#include <bits/stdc++.h>

using namespace std;

#define reset(x) memset(x,0,sizeof(x))
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back 

const string players[15]={"RohitSharma","ShikharDhawan","ViratKohli","KedarJadhav","VijayShankar","HardikPandya","RavindraJadeja","LokeshRahul","MahendraSinghDhoni","DineshKarthik","KuldeepYadav","YuvzendraChahal","MohammedShami","JaspritBumrah","BhuvneshwarKumar"};
const int N =15;
vector<int> alpha_p[26];

void kata(){
	cout<<"There is no team India in you :(\n";
	exit(0);
}

int getnum(char c){
	if(c>='a')return (int)(c-'a');
	return (int)(c-'A');
}

bool getorder(int pos,string &name,vector<int> &order,bool *used)
{

	if(pos>=name.size())return true;
	if(name[pos]==' ')return getorder(pos+1,name,order,used);

	int alpha_no=getnum(name[pos]);
	for(int i=0;i<alpha_p[alpha_no].size();i++){
		int v=alpha_p[alpha_no][i];
		if(used[v])continue;
		order[pos]=v;
		used[v]=true;
		if(getorder(pos+1,name,order,used)){
			return true;
		}
		order[pos]=-1;
		used[v]=false;
	}
	return false;	
}

void display(vector<int> &v,string &name){
	int pad[name.size()];
	reset(pad);
	int pos[name.size()];
	int mx=0;
	for(int i=0;i<name.size();i++){
		if(name[i]==' '){
			pos[i]=0;continue;
		}
		int j=0;
		while(getnum(players[v[i]][j])!=getnum(name[i]))j++;
		pos[i]=j;
		mx=max(mx,j);
	}
	rep(i,0,name.size())pad[i]=mx-pos[i]+1;
	for(int i=0;i<name.size();i++){
		if(name[i]==' '){
			cout<<endl;continue;
		}
		for(int j=0;j<pad[i];j++)cout<<" ";
		for(int j=0;j<pos[i];j++)cout<<(char)tolower(players[v[i]][j]);
		cout<<" "<<(char)toupper(players[v[i]][pos[i]])<<" ";
		for(int j=pos[i]+1;j<players[v[i]].size();j++)cout<<(char)tolower(players[v[i]][j]);
		cout<<endl;
	}
}

int main(){
	cout<<"Enter your name: \n"<<endl;
	string name;
	getline(cin,name);
	// name=remove_spaces(name);
// 	if(name.size()>N)kata();
// 	if(name.size()==0)kata();

	rep(i,0,N){
		rep(j,0,players[i].size()){
			alpha_p[getnum(players[i][j])].pb(i);
		}
	}
	vector<int> order(name.size(),-1);
	bool used[N];
	reset(used);
	bool hua=getorder(0,name,order,used);
	
	if(!hua)kata();

	display(order,name);

	return 0;
}	
