#include<bits/stdc++.h>
using namespace std;

class count{
  vector<int>tree;
  int size,val;
  void buildtree(int index,int low,int high,vector<int>&vec){
    if(low==high){
      tree[index]=(vec[low]==val);
      return;
    }
    int mid=(low+high)/2;
    buildtree(2*index+1,low,mid,vec);
    buildtree(2*index+2,mid+1,high,vec);
    tree[index]=tree[2*index+1]+tree[index*2+2];
    return;
  }
  public:
  count(vector<int>&vec){
    int n=vec.size();
    tree.resize(4*n+1);
    buildtree(0,0,n-1,vec);
    size=n;
  }
  void newtree(vector<int>&vec,val){
    tree.clear();
    size=vec.size();
    this->val=val;
    buildtree(0,0,vec.size()-1,vec);
  }
  int q_helper(int index,int low,int high,int const &reqlow,int const &reqhigh){
    if(low==high){
      if(reqlow<=low&&reqhigh>=low)return (tree[index]==val);
      else return 0;
    }
    if(reqlow<=low&&reqhigh>=high)return (tree[index]==val);
    if(high<reqlow||low>reqhigh)return 0;
    int mid=(low+high)/2;
    return q_helper(2*index+1,low,mid,reqlow,reqhigh)+q_helper(2*index+2,mid+1,high,reqlow,reqhigh);
  }
  int query(int low,int high){
    return q_helper(0,0,size-1,low,high);
  }
  void puh(int const &updateindex,int index,int low,int high,int const &value){
    if(low==high){
      if(updateindex==low)tree[index]=(val==value);
      return;
    }
    if(updateindex>high||updateindex<low)return;
    int mid=(low+high)/2;
    puh(updateindex,2*index+1,low,mid,val);
    puh(updateindex,2*index+2,mid+1,high,val);
    tree[index]=tree[index*2+1]+tree[index*2+2];
    return;
  }
  void pointupdate(int updateindex,int value){
    puh(updateindex,0,0,size-1,value);
  }
};