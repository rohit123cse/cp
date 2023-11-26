vector<int>sieve(int n){  //return prime factors upto sqrt(n)
  vector<int>res;
  int s=sqrt(n);
  vector<int>visited(s+1,0);
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
int number_of_divisors(int n){
  vector<int>div=sieve(n);
  int res=1;
  for(int i=0;i<div.size();i++){
    if(!n||div[i]>n)break;
    int val=0;
    while(n%div[i]==0){
      n/=div[i];
      val++;
    }
    if(val)res*=(val+1);
  }
  return res;
}
