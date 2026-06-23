#ifndef __enemy__cpp_
#define __enemy__cpp_
#include "includes.h"
int dist(Enemy a,Player b){
	return ceil(sqrt(abs(a.x-b.x)*abs(a.x-b.x)+abs(a.y-b.y)*abs(a.y-b.y)));
}
bool tooNear(Enemy a,Player b){
	if(inTut){
		if(dist(a,b)<3)return 1;
	}else if(dist(a,b)<10)return 1;
	return 0;
}
void newSpecialEnemy(int x,int y,int d){
	Enemy rt;rt.generate(30);
	rt.x=x,rt.y=y,rt.dir=d;
	enemies.push_back(rt);
	drawEnemy(rt);
}
void newEnemy(int eyesight=15){
	if(specialRule)return; 
	Enemy rt;rt.generate(eyesight);
	while(!able(rt) or tooNear(rt,player))rt.generate(eyesight);
	rt.moveable=mov;
	enemies.push_back(rt);
	drawEnemy(rt);
}
bool canSee(Enemy a,Player b){
	if(specialRule)a.sight=0;
	if(dist(a,b)>a.sight) return 0;
	int vx=b.x-a.x,vy=b.y-a.y;
	int ex=dx[a.dir],ey=dy[a.dir];
	int dot=(vx*ex+vy*ey);
	// 120-degree field of view: the target must be in front of the enemy
	// and at most 60 degrees away from its facing direction.
	if(dot<=0)return 0;
	ld norm_v=vx*vx+vy*vy;
	ld norm_e=ex*ex+ey*ey;
	return (ld)dot*dot*eyeSightAngle>=norm_v*norm_e;
}
int getDir(Enemy a,Player b){
	if(!canSee(a,b))return -1;
	int bestDir=-1,minDist=dist(a,b);
	for(int d=0;d<4;d++){
		int nx=a.x+dx[d],ny=a.y+dy[d];
		Enemy nextPos=a;nextPos.setPos(nx,ny,d);
		eraseEnemy(a);
		if(!able(nextPos)){
			drawEnemy(a);
			continue;
		}
		drawEnemy(a);
		int newDist=dist(nextPos,b);
		if(newDist<minDist){
			minDist=newDist;
			bestDir=d;
		}
	}
//	if(dist(a,b)<5){
//		cerr<<"en "<<a.x<<' '<<a.y<<'\n';
//		cerr<<"pl "<<b.x<<' '<<b.y<<'\n';
//		cerr<<"GETDIR: "<<bestDir<<'\n';
//		system("pause");		
//	}
	return bestDir;
}
void move(Enemy&enemy){
	int t=getDir(enemy,player);
	enemy.lastmove=standardClock;
	if(t!=-1){
		eraseEnemy(enemy);
		enemy.x+=dx[t];
		enemy.y+=dy[t];
		enemy.dir=t;
		drawEnemy(enemy);
		return;
	}
	if(enemy.step==0){
		if(rand()%enemyStopTime)return;
		vector<int>vdir;vdir.clear();
		for(int d=0;d<4;++d){
			Enemy nextPos=enemy;
			nextPos.dir=d;
			eraseEnemy(enemy);
			if(able(nextPos))vdir.push_back(d);
			drawEnemy(enemy);
		}
		if(vdir.size()==0)return;
		int id=rand()%(int)(vdir.size());
		eraseEnemy(enemy);
		enemy.dir=vdir[id];
		enemy.step=rand()%enemyStep+enemyStep;
		drawEnemy(enemy);
	}else{
		Enemy nextPos=enemy;
		nextPos.x+=dx[nextPos.dir],nextPos.y+=dy[nextPos.dir];
		eraseEnemy(enemy);
		if(able(nextPos)){
			eraseEnemy(enemy);
			enemy=nextPos;
			drawEnemy(enemy);
		}else{
			
		}
		drawEnemy(enemy);
		--enemy.step;
	}
}
void updateEnemy(){
	for(Enemy& enemy:enemies){
		if(enemy.alive==0)continue;
		if(standardClock-enemy.lastmove<enemySpeed)continue;
//		eraseEnemy(enemy); 
		move(enemy);
//		drawEnemy(enemy);
	}
}
void updateEnemyList(){
	vector<Enemy>newList;newList.clear();
	for(const Enemy& enemy:enemies)if(enemy.alive)newList.push_back(enemy);
	enemies=newList;
}
void clearEnemies(){
	for(Enemy& enemy:enemies)enemy.alive=0,eraseEnemy(enemy);
	updateEnemyList();
} 
#endif 
