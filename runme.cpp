#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 

using namespace std;
#define md 1000000007
#define itn int
#define pb push_back
#define mp make_pair
#define ull unsigned long long int
#define ll long long int
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define all(x) x.begin(),x.end()
#define ff first	
#define lb lower_bound
#define ub upper_bound
#define ss second
#define inf 1e9
#define enld '\n'
#define cuot cout
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define trace(v) for(auto it=v.begin();it!=v.end();it++)cerr<<*it<<" ";cerr<<endl;
#define linf 1e18
#define reset(x) memset(x,0,sizeof(x))
#define rep(i,a,b) for(int i=a;i<b;i++)
 
using namespace __gnu_pbds; 
 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    oset;

void fastio(){	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const string players[15]={"RohitSharma","ShikharDhawan","ViratKohli","KedarJadhav","VijayShankar","HardikPandya","RavindraJadeja","LokeshRahul","MahendraSinghDhoni","DineshKarthik","KuldeepYadav","YuvzendraChahal","MohammedShami","JaspritBumrah","BhuvneshwarKumar"};
const int N =15;
vector<int> alpha_p[26];

void kata(){
	cout<<"There is no team India in you :(\n";
	exit(0);
}

// string remove_spaces(string &name){
// 	string ret="";
// 	rep(i,0,name.size()){
// 		if((name[i]>='A' && name[i]<='Z') || (name[i]>='a' && name[i]<='z'))ret+=name[i];
// 	}
// 	return ret;
// }
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
// char toUpper()
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
void solve(){
	cout<<"Enter your name: \n"<<endl;
	string name;
	getline(cin,name);
	// name=remove_spaces(name);
	if(name.size()>N)kata();
	if(name.size()==0)kata();

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
	
	// for(auto x:order)cout<<players[x]<<endl;
	display(order,name);

}

int main(){
	fastio();
	#ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("in.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("out.txt", "w", stdout); 
  
	#endif 
	int t;
	t=1;
	
	for(int i=1;i<=t;i++){		
		solve();
	}	
	return 0;
}	