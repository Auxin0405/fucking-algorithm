#include <iostream>
#include<cstdio>
#include<set>
using namespace std;
//map 版本来处理但是没有
typedef long long ll;
typedef struct Node{
    int val;
    int num;//为了区分键值一样的内容；
}N;
int NUM;
set<N> s;
ll ans;
bool operator<(N x,N y)
{
    if(x.val!=y.val)
        return x.val<y.val;
    else
        return x.num<y.num;
}
int main()
{
    scanf("%d",&NUM);
    for(int i=0;i<NUM;i++)
    {
        N temp;
        scanf("%d",&temp.val);
        temp.num=i;
        s.insert(temp);
    }
    if(NUM<2)
    {
        cout<<s.begin()->val;
        return 0;
    }
    int q=NUM;
    while(NUM>1)
    {
        int  temp=s.begin()->val;
        s.erase(s.begin());
        temp+=s.begin()->val;
        s.erase(s.begin());
        ans+=temp;
        NUM--;
        N tqm;
        tqm.num=q++;
        tqm.val=temp;
        s.insert(tqm);
    }
    cout<<ans;
    //cout << "Hello world!" << endl;
    return 0;
}
