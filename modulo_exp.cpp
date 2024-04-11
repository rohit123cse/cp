#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
int pow(int base,int expo){
  if(expo==0)return 1;
  if(expo==1)return base;
    long long x=pow(base,expo/2); 
  if((expo&1)){
    return x*x*base%mod;
  }
  return x*x%mod;
}




