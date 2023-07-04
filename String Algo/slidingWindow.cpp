#include<bits/stdc++.h>
using namespace std;

int main(){
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
    for(int i=0;i+pattern.length()-1<=text.length();i++){
      int j=0,k=i;
      for(j=0;j<pattern.length();j++){
        if(pattern[j]!=text[k]){
          break;
        }else {
          k++;
        }
      }
      if(j==pattern.length()){
        cout<<i<<endl;
      }
    }

}