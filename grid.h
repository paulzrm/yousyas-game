#ifndef __grid__h_
#define __grid__h_
#include<bits/stdc++.h>
using namespace std;
struct Grid{
	int n,m;
	int c[133][133];
	string name;
	void init(){
		name="";
		n=128,m=128;
		gridN=n,gridM=m;
		memset(c,0,sizeof(c));
	}
	void init(int N,int M){
		n=N,m=M;
		gridN=n,gridM=m;
		memset(c,0,sizeof(c));
	}
	void test(){
		for(int t=1;t<=128;++t){
			int tx=rand()%n+1,ty=rand()%m+1;
			if(abs(tx-64)+abs(ty-64)>5)c[tx][ty]=-1;
		}
		for(int t=1;t<=64;++t){
			int tx=rand()%n+1,ty=rand()%m+1;
			if(abs(tx-64)+abs(ty-64)>5 and c[tx][ty]==0)c[tx][ty]=6;
		}
	}
	void generateEmpty(){
		for(int i=1;i<=n;++i)c[i][1]=c[i][m]=-1;
		for(int i=1;i<=m;++i)c[1][i]=c[n][i]=-1;
	}
	void generate(){
		for(int i=1;i<=n;++i)c[i][1]=c[i][m]=-1;
		for(int i=1;i<=m;++i)c[1][i]=c[n][i]=-1;
		test();
	}
	void genCoin(){
		int cnt=16;
		if(inTut)cnt=6;
		for(int t=1;t<=cnt;++t){
			int tx=rand()%n+1,ty=rand()%m+1;
			if(abs(tx-player.x)+abs(ty-player.y)>5 and c[tx][ty]==0)c[tx][ty]=6;
		}
	}
	void remove(Player p){
		c[p.x][p.y]=0;
		c[p.x+dx[p.dir]][p.y+dy[p.dir]]=0;
	}
	void add(Player p){
		if(c[p.x][p.y]==6)player.money+=10;
		if(c[p.x+dx[p.dir]][p.y+dy[p.dir]]==6)player.money+=10;
		c[p.x][p.y]=1;
		if(p.dir%2==0)c[p.x+dx[p.dir]][p.y+dy[p.dir]]=2;
		else c[p.x+dx[p.dir]][p.y+dy[p.dir]]=3;
	}
	void set(int x,int y,int d){
		c[x][y]=d;
	}
}grid;
void shit();
char trans(int x);
bool ablePoint(int x,int y);
bool able(Player p);
void drawEnemy(Enemy enemy);
void eraseEnemy(Enemy enemy);
void print(Grid g,Player p);
bool enoughCoin(Grid g);
#endif
