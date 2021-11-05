//
//  2573.cpp
//  
//
//  Created by 김유민 on 2020/01/02.
//
//

#include <iostream>
#include <algorithm>
#include <cstring> //memset

using namespace std;
const int MAX = 300;

typedef struct

{

        int y, x;

}Dir;

 

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

 

int N, M;

int graph[MAX][MAX];

bool visited[MAX][MAX];

 
void melt(void){
        int copy[MAX][MAX]; //기존의 빙산 복사
        for (int y = 0; y < N; y++)
                 for (int x = 0; x < M; x++)
                         copy[y][x] = graph[y][x];

        for(int y = 1; y < N - 1; y++)
                 for(int x = 1; x < M - 1; x++)
                         if (copy[y][x]){
                                 int cnt = 0;
                                 for (int i = 0; i < 4; i++){
                                          int nextY = y + moveDir[i].y;
                                          int nextX = x + moveDir[i].x;
                                          if (copy[nextY][nextX] == 0)
                                              cnt++;
                                 }

                                graph[y][x] = copy[y][x] - cnt;
                                if(graph[y][x] < 0)
                                    graph[y][x] = 0;
                         }
}


void DFS(int y, int x){

        visited[y][x] = true;

        for (int i = 0; i < 4; i++){
                 int nextY = y + moveDir[i].y;
                 int nextX = x + moveDir[i].x;

                 if (1 <= nextY && nextY < N - 1 && 1 <= nextX && nextX < M - 1)
                         if (graph[nextY][nextX] && !visited[nextY][nextX])
                                 DFS(nextY, nextX);
        }
}

 
int main(void){
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        cin >> N >> M;

        for (int i = 0; i < N; i++)
                 for (int j = 0; j < M; j++)
                         cin >> graph[i][j];

        int year = 0;
        while (1){
                 memset(visited, false, sizeof(visited));
                 bool result = false;
                 int cnt = 0;

                 for (int y = 1; y < N - 1; y++)
                         for (int x = 1; x < M - 1; x++)
                                 if (graph[y][x] && visited[y][x] == false){
                                          cnt++;
                                          if (cnt == 2){
                                                  result = true;
                                                  break;
                                          }
                                          DFS(y, x);
                                 }
                 if (result)
                         break;

                 if (cnt == 0){
                         year = 0;
                         break;
                 }

            melt();
            year++;
        }

        cout << year << "\n";

        return 0;

}
