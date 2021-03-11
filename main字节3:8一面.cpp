#include <iostream>
#include <bits/stdc++.h>
using namespace std;


const int MAX=110;

int w,q;
int m,n;

//访问记录，表示i,j这个点是否访问过
bool inq[MAX][MAX]={false};

//结果矩阵
int ans[MAX][MAX]={100};

int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};

struct node
{
    int i,j;
    int value;
};
node Map[MAX][MAX];


bool judge(int x,int y)
{
    if(x>=m||x<0||y>=n||y<0||inq[x][y]==true) return false;
    return true;
}


int Manhattan(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}

void bfs(int x,int y)
{
    queue<node> q;
    q.push(Map[x][y]);
    inq[x][y]= true;

    //x,y代表本身，直接返回
    if(Map[x][y].value==0)
    {
        ans[x][y]=0;
        return;
    }
    while(!q.empty())
    {
        node now=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            int newX=now.i+X[i];
            int newY=now.j+Y[i];
            if(judge(newX,newY))
            {
                int temp=Manhattan(x,y,newX,newY);

                //如果搜索到的点为陆地，且到当前点x,y的距离最小，直接设置为ans矩阵的值，并返回
                if(Map[newX][newY].value==0 && temp<ans[x][y])
                {
                    ans[x][y]=temp;

                    return;
                }
                q.push(Map[newX][newY]);
                inq[newX][newY]= true;
            }
        }



    }


}
void init()
{
    for(int i=0;i<m;i++) {
        for (int j = 0; j < n; j++) {
            inq[i][j]=false;
        }
    }
}


int main()
{

    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>w;
            node a;
            a.i=i;
            a.j=j;
            a.value=w;
            Map[i][j]=a;

            //辅助测试，一开始要把ans矩阵的值赋值为一个很大的值
            ans[i][j]=100;
        }
    }
    for(int i=0;i<m;i++) {
        for (int j = 0; j < n; j++) {
            //必须对inq每次都初始化
            init();
            bfs(i,j);
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {

            cout<<ans[i][j]<<" ";

        }
        cout<<endl;
    }





    return 0;
}
