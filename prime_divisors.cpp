#include<bits/stdc++.h>
using namespace std;
vector<int>sieve(int n){  //return prime factors upto sqrt(n)
  vector<int>res;
  int s=sqrt(n);
  vector<int>visited(s,0);
  for(int i=2;i<=s;i++){
    if(visited[i])continue;
    res.push_back(i);
    for(int j=2*i;j<=s;j+=i)visited[j]++;
  }
  return res;
}
vector<pair<int,int>>prime_div(int n){   //returns pairs{prime divisor , power of prime divisor}
  vector<pair<int,int>>vec;
  vector<int>div=sieve(n);
  int i=0,size=div.size();
  while(n&&i<size){
    if(div[i]>n)break;
    if(n%div[i]!=0){
      i++;
      continue;
    }
    int val=0;
    while(n%div[i]==0){
      val++;
      n/=div[i];
    }
    vec.push_back({div[i],val});
    i++;
  }
}
int main(){
  






return 0;
}