#include<bits/stdc++.h>
using namespace std;
struct point
{
           int x,y;
};
struct node
{
           point pt;
           int dist;
};
const int row=9,col=10;
int row_num[]={-1,0,0,1};
int col_num[]={0,-1,1,0};
bool is_valid(int Row,int Col)
{
           return (Row>=0 && Row<row && Col>=0 && Col<col);
}
int shortest_path(int place[][col],point src,point dest)
{
           if(!place[src.x][src.y] || !place[dest.x][dest.y])
                      return -1;
           bool visited[row][col];
           memset(visited,false,sizeof visited);
           visited[src.x][src.y]=true;
           queue<node>q;
           node s={src,0};
           q.push(s);
           while(!q.empty())
           {
                      node curr=q.front();
                      point pt=curr.pt;
                      q.pop();
                      if(pt.x==dest.x && pt.y==dest.y)
                                 return curr.dist;
                      for(int i=0;i<4;i++)
                      {
                                 int row=pt.x+row_num[i];
                                 int col=pt.y+col_num[i];
                                 if(is_valid(row, col) && place[row][col] && !visited[row][col])
                                 {
                                            visited[row][col]=true;
                                            node next_cell={{row, col},curr.dist+1};
                                            q.push(next_cell);
                                 }
                      }
           }
           return -1;
}
int main()
{
           int place[row][col] ={{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },{ 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
           point src={0,0},dest={3,4};
           int ret=shortest_path(place,src,dest);
           if(ret==-1)
                      cout<<"Shortest path does not exist!!";
           else
                      cout<<"Shortest path:"<<ret;
           return 0;
}
