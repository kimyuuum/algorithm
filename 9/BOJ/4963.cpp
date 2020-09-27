//섬의 개수
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 51;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int ans = 0;
int w,h;
int dirX[8] = {-1,-1,-1,0,0,1,1,1};
int dirY[8] = {-1,0,1,-1,1,-1,0,1};

void bfs(int x,int y){

  queue<pair<int,int>> q;
  q.push(make_pair(x,y));
  visited[x][y] = true;

  while(!q.empty()){
    int curX = q.front().first;
    int curY = q.front().second;

    q.pop();

    for(int i=0; i<8; i++){
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if(nextX < 0 || nextX >= h || nextY < 0 || nextY >= w){
        continue;
      }

      if(!visited[nextX][nextY] && arr[nextX][nextY] == 1){
        q.push(make_pair(nextX,nextY));
        visited[nextX][nextY] = true;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  while(1){
    memset(arr,0,sizeof(arr));
    memset(visited,false,sizeof(visited));

    ans = 0;
    cin>>w>>h;
    if(w == 0 && h == 0){
      break;
    }

    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        cin>>arr[i][j];
      }
    }

    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        if(arr[i][j] == 1 && !visited[i][j]){
          bfs(i,j);
          ans++;
        }
      }
    }
    cout<<ans<<"\n";
  }


  return 0;
}