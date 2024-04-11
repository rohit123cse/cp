 #include<bits/stdc++.h>
using namespace std;
//when to use segment trees : when affecting a particular value affects results over a range of values/indexes
class maxrangeds{
  vector<int>tree;
  int size;
  void buildtree(int index,int low,int high,vector<int>&vec){
    if(low==high){
      tree[index]=vec[low];
      return;
    }
    int mid=(low+high)/2;
    buildtree(2*index+1,low,mid,vec);
    buildtree(2*index+2,mid+1,high,vec);
    tree[index]=max(tree[2*index+1],tree[index*2+2]);
    return;
  }
  public:
  maxrangeds(vector<int>&vec){
    int n=vec.size();
    tree.resize(4*n+1);
    buildtree(0,0,n-1,vec);
    size=n;
  }
  void newtree(vector<int>&vec){
    tree.clear();
    size=vec.size();
    buildtree(0,0,vec.size()-1,vec);
  }
  int q_helper(int index,int low,int high,int const &reqlow,int const &reqhigh){
    if(low==high){
      if(reqlow<=low&&reqhigh>=low)return tree[index];
      else return INT_MAX;
    }
    if(reqlow<=low&&reqhigh>=high)return tree[index];
    if(high<reqlow||low>reqhigh)return INT_MAX;
    int mid=(low+high)/2;
    return max(q_helper(2*index+1,low,mid,reqlow,reqhigh),q_helper(2*index+2,mid+1,high,reqlow,reqhigh));
  }
  int query(int low,int high){
    return q_helper(0,0,size-1,low,high);
  }
  void pointupdate(int const &updateindex,int index,int low,int high,int const &val){
    if(low==high){
      if(updateindex==low)tree[index]=val;
      return;
    }
    if(updateindex>high||updateindex<low)return;
    int mid=(low+high)/2;
    pointupdate(updateindex,2*index+1,low,mid,val);
    pointupdate(updateindex,2*index+2,mid+1,high,val);
    tree[index]=max(tree[index*2+1],tree[index*2+2]);
    return;
  }
};
class minrangeds{
  vector<int>tree;
  int size;
  void buildtree(int index,int low,int high,vector<int>&vec){
    if(low==high){
      tree[index]=vec[low];
      return;
    }
    int mid=(low+high)/2;
    buildtree(2*index+1,low,mid,vec);
    buildtree(2*index+2,mid+1,high,vec);
    tree[index]=min(tree[2*index+1],tree[index*2+2]);
    return; 
  }
  public:
  minrangeds(vector<int>&vec){
    int n=vec.size();
    tree.resize(4*n+1);
    buildtree(0,0,n-1,vec);
    size=n;
  }
  void newtree(vector<int>&vec){
    tree.clear();
    size=vec.size();
    buildtree(0,0,vec.size()-1,vec);
  }
  int q_helper(int index,int low,int high,int const &reqlow,int const &reqhigh){
    if(low==high){
      if(reqlow<=low&&reqhigh>=low)return tree[index];
      else return INT_MAX;
    }
    if(reqlow<=low&&reqhigh>=high)return tree[index];
    if(high<reqlow||low>reqhigh)return INT_MAX;
    int mid=(low+high)/2;
    return min(q_helper(2*index+1,low,mid,reqlow,reqhigh),q_helper(2*index+2,mid+1,high,reqlow,reqhigh));
  }
  int query(int low,int high){
    return q_helper(0,0,size-1,low,high);
  }
  void pointupdate(int const &updateindex,int index,int low,int high,int const &val){
    if(low==high){
      if(updateindex==low)tree[index]=val;
      return;
    }
    if(updateindex>high||updateindex<low)return;
    int mid=(low+high)/2;
    pointupdate(updateindex,2*index+1,low,mid,val);
    pointupdate(updateindex,2*index+2,mid+1,high,val);
    tree[index]=min(tree[index*2+1],tree[index*2+2]);
    return;
  }
};