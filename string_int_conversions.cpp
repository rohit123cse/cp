#include<bits/stdc++.h>
using namespace std;

string ntos(int x){
  string res="";
  while(x){
    res+=(x%10+'0');
    x/=10;
  }
  reverse(res.begin(),res.end());
  return res;
}

int ston(string s){
  int res=0;
  for(int i=0;i<s.size();i++){
    res*=10;
    res+=(s[i]-'0');
  }
  return res;
}

int main(){
  






return 0;
}