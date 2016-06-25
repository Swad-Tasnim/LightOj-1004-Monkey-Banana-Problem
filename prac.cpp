#include <bits/stdc++.h>
#define ll   long long int
#define mem(x,y) memset(x,y,sizeof(x))
#define M   10000
using namespace std;

int dp[201][201];
vector<int>a[201];
  int n,v;
int call(int i, int j)
{     if(i>=0 && i<2*n-1 && j>=0 && j<a[i].size())
      {    //cout<<a[i].size();
            if(dp[i][j]!=-1)
            return dp[i][j];

         int p=-1;
         p=max(p,call(i+1,j)+a[i][j]);
        if(i<n-1)
        p=max(p,call(i+1,j+1)+a[i][j]);
        else if(i>=n-1)
        p=max(p,call(i+1,j-1)+a[i][j]);



            return dp[i][j]=p;
}

      else
      return 0;

}

int main()
{    int m;
     scanf("%d",&m);
     for(int q=1; q<=m; q++)
    {mem(dp,-1);
           scanf("%d",&n);

       for(int i=0; i<n; i++)
       {    a[i].clear();
             for(int j=0; j<=i; j++)
       {

              scanf("%d",&v);
       a[i].push_back(v);
       }}
       int l=n-1;
       for( int i=n; i<2*n-1; i++)
       {        a[i].clear();
             for(int j=0; j<l; j++)
             {
                       scanf("%d",&v);
                   a[i].push_back(v);
             }
             l--;
       }
      printf("Case %d: %d\n",q,call(0,0));


       }

}
