#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int getHash(string s ){
  int power=1,val=0;
  for(char c:s){
    val = val+ (c-'a'+1)*power % mod;
    power=(power*31)%mod;
  }
  return val;
}

int main () {
  
    string s;
    cin>>s;
    cout<<getHash(s)<<endl;
}

// ==============================================================================================

#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int dp[1000006];
int inv[1000006];

int power( int a, int n){
    int result = 1;
    while(n){
        if(n&1)result = (result*a)%mod;
        n>>=1;
        a=(a*a)%mod;;
    }
    return result;
}

void init(string input_string){
    int p= 31;
    int p_power=1;
    inv[0]=1;
    dp[0]=(input_string[0]-'a'-1);
    for(int i=1;i<input_string.size();i++){
        char ch = input_string[i];
        p_power=(p_power*p)%mod;
        inv[i]=power(p_power,mod-2);
        dp[i]=(dp[i-1]+(ch-'a'+1)*p_power)%mod;
    }
}

int substringHash(int l,int r){
    int result = dp[r];
    if(l>0)result-=dp[l-1];
    result = (result *inv[l])%mod;
    return result;
}

int main () {
    string input_string;
    int tc,l,r;
    cin>>input_string;
    init(input_string);

    cin>>tc;
    while(tc--){
        cin>>l>>r;
        cout<<substringHash(l,r)<<endl;
    }
}