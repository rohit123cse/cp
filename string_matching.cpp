class kmp{
  public: 
  string s;
  int size;
  vector<int>vec;
  void lps(){
    int i=1,len=0;
        while(i<size){
            if(s[len] == s[i]){
                len++;
                vec[i] = len;
                i++;
            }else{
                if(len == 0){
                    vec[i]=0;
                    i++;
                }else{
                    len = vec[len-1];
                }
            }
        }
  }
    int find(int n){
    for(int i=n;i<size;i++){
      if(vec[i]==n)return i-2*n;
    }
    return -1;
  }
  void print(){
    for(auto it:vec)cout<<it<<" ";
  }
  kmp(string x){
    s=x;
    size=s.size();
    vec.resize(size,0);
  }

};
