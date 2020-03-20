/*
ID: lakshit4
PROG: camelot
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

ifstream in("camelot.in");
ofstream out("camelot.out");

int R,C;

vector<pair<int,int>> knights;
pair<int,int> king;

int knightDis[31][27][31][27];
int cost[31][27];

int delta(int a,int b){
  if(a==b)return 0;
  return max(a,b) - min(a,b);
}

void BFS(int a,int b){
  int Count = 0;
    bool visited[31][27];
    for(int i=0;i<=C;i++)
      for(int j=0;j<=R;j++){
        knightDis[a][b][i][j] = INT_MAX;
        visited[i][j] = false;
      }
    list<pair<int,int>> q;
    visited[a][b] = true;
    q.push_back({a,b});
    knightDis[a][b][a][b] = true;
    knightDis[a][b][a][b] = 0;
    while(!q.empty()){
       pair<int,int> p = q.front();
       q.pop_front();
       int x,y;
       int r,c;
       int Count = 0;
       for(x = -2;x<=2;x++)
        for(y = -2;y<=2;y++){
          if(x==0 || y==0)continue;
          if(x==y || x*-1==y)continue;
          int r = p.first +x;
          int c = p.second +y;
          // Count ++;
          if(r<=R && c<=C && r>=1 && c>=1 && !visited[r][c]){
            // cout << r << "<>" << c << endl;
            q.push_back({r,c});
            visited[r][c] = true;
            knightDis[a][b][r][c] = knightDis[a][b][p.first][p.second] + 1;
            cost[r][c] += knightDis[a][b][r][c];
            Count ++;
          }
        }
        // cout << Count << endl;
    }
    cout << Count << endl;
    // for(int i=1;i<=R;i++)
    //   for(int j=1;j<=C;j++){
    //     cout << i << "<>" << j << endl;
    //     cout << visited[i][j]<< endl;
    //   }
}

int main(){
  in >> R >> C;
  char c;
  int r;
  in >>c;
  in >>r;
  king = {r,c-'A'+1};
  while(in >> c){
    in >> r;
    knights.push_back({r,c-'A'+1});
  }
  for(int fr=1;fr<=R;fr++)
    for(int fc=1;fc<=C;fc++)
    for(int i=1;i<=R;i++)
    for(int j=1;j<=C;j++)
    knightDis[i][j][fr][fc] = INT_MAX;
  // cout << r << c << endl;

  for(int i=1;i<=R;i++)
  for(int j=1;j<=C;j++)
    BFS(i,j);

    int MIN = INT_MAX-10;
    for(int fr=1;fr<=R;fr++)
      for(int fc=1;fc<=C;fc++){
        int D=0;
        int z = 0;
        int k = 0;
        // cout << "+++++++++++++++++++=" << endl;
        for(pair<int,int> knight : knights){
          // if(knightDis[knight.first][knight.second][fr][fc]==0){
          //   z++;
          //   if(z!=1){
          //     D = INT_MAX;
          //     break;
          //   }
          // }
          k++;
          D += knightDis[knight.first][knight.second][fr][fc];
          // cout << knightDis[knight.first][knight.second][fr][fc] << endl;
        }
        // cout << D << endl;
        if(D>MIN)
          continue;

        // cout << fr << " " << fc << endl;
        // continue;
        for(int pr=1;pr<=R;pr++)
          for(int pc=1;pc<=C;pc++){
            int d;
            int e;
            int localMin = INT_MAX;
            for(int i=0;i<knights.size();i++){
              d = D - knightDis[knights.at(i).first][knights.at(i).second][fr][fc];
              e = knightDis[knights.at(i).first][knights.at(i).second][pr][pc] + knightDis[pr][pc][fr][fc] + max(abs(king.first-pr),abs(king.second-pc));
              localMin = min(localMin,d+e);
            }
            if(knights.size()==0)localMin = max(abs(king.first-pr),abs(king.second-pc));
            if(localMin<0)continue;
            MIN = min(MIN,localMin);
          }
      }
    out << MIN << endl;
}
