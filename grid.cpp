#ifndef __grid__cpp_
#define __grid__cpp_
#include "includes.h"
bool ablePoint(int x,int y){
	if(x<1 or y<1 or x>grid.n or y>grid.m)return 0;
	if(grid.c[x][y]==-1)return 0;
	return 1;
}
bool able(Player p){
	if(ablePoint(p.x,p.y) and ablePoint(p.x+dx[p.dir],p.y+dy[p.dir]))return 1;
	return 0;
}
bool ablePointEnemy(int x,int y){
	if(x<1 or y<1 or x>grid.n or y>grid.m)return 0;
	if(grid.c[x][y]==0 or grid.c[x][y]==1 or grid.c[x][y]==2 or grid.c[x][y]==3 or grid.c[x][y]==4)return 1;
	return 0;
}
bool able(Enemy p){
	if(ablePointEnemy(p.x,p.y) and ablePointEnemy(p.x+dx[p.dir],p.y+dy[p.dir]))return 1;
	return 0;
}
char trans(int x){
	if(x==-1)return '#';
	if(x==0)return ' ';
	if(x==1 or x==7)return 'O';
	if(x==2 or x==8)return '|';
	if(x==3 or x==9)return '-';
	if(x==4)return 'P';
	if(x==5)return '*';
	if(x==6)return '$';
	exit(-1);
}
void eraseEnemy(Enemy enemy){
	grid.c[enemy.x][enemy.y]=0;
	grid.c[enemy.x+dx[enemy.dir]][enemy.y+dy[enemy.dir]]=0;
}
void drawEnemy(Enemy enemy){
	grid.c[enemy.x][enemy.y]=7;
	if(enemy.dir%2==0)grid.c[enemy.x+dx[enemy.dir]][enemy.y+dy[enemy.dir]]=8;
	else grid.c[enemy.x+dx[enemy.dir]][enemy.y+dy[enemy.dir]]=9;
}
void shit(){
	for(int i=1;i<=grid.n;++i){
		for(int j=1;j<=grid.m;++j){
			int c=grid.c[i][j];
			if(c==7 or c==8 or c==9)grid.c[i][j]=0;
		}
	}
	for(const Enemy& enemy:enemies){
		if(enemy.alive==0)continue;
		drawEnemy(enemy);
	}
} 
void print(Grid g,Player p) {
	g.remove(p);
	g.add(p);
    static const string clear_screen = "\033[H"; // ANSI 光标回到左上角
    cout << clear_screen; // 直接将光标移动到屏幕左上角，而不是清空整个屏幕
    int sx = max(1, p.x - 8), sy = max(1, p.y - 10);
    int ex = min(g.n, max(sx+16,p.x + 8)), ey = min(g.m, max(sy+20,p.y + 10));
	sx = max(1, min(sx,ex-16)), sy = max(1, min(sy,ey-20));
	shit();
	if(g.name!="")cout<<g.name<<'\n'; 
    for (int i = sx; i <= ex; ++i) {
        for (int j = sy; j <= ey; ++j) {
        	int c=g.c[i][j];
            if(c==1 or c==2 or c==3) {
                cout << yousyaColor << trans(c) << "\033[0m"; 
			}else if(c==4){
            	cout << "\033[32m" << trans(c) << "\033[0m"; 
			}else if(c==5){
				cout << "\033[37m" << trans(c) << "\033[0m"; 
			}else if(c==6){
				cout << "\033[33m" << trans(c) << "\033[0m"; 
			}else if(c==7 or c==8 or c==9){
				cout << enemyColor << trans(c) << "\033[0m"; 
			}else{
                cout << trans(c);
	        }
    	}
        cout << '\n';
    }
    cout<<"你的坐标："<<"("<<player.x<<","<<player.y<<")";
    cout<<"                               \n"; 
    if(player.left){
    	cout<<"信标坐标： "<<"("<<player.leftx<<","<<player.lefty<<")"; 
	}else cout<<"未设置信标";cout<<"                               \n"; 
    cout<<"金币: "<<player.money;cout<<"                               \n"; 
    cout<<"生命："<<player.hp;cout<<"                                \n";
    cout.flush(); // 立即刷新缓冲区
}
bool enoughCoin(Grid g){
	int cnt=0;
	for(int i=1;i<=g.n;++i)
		for(int j=1;j<=g.m;++j)
			if(g.c[i][j]==6)++cnt;
	return cnt>=maxCoin;
}
#endif
