#ifndef __steps_cpp_
#define __steps_cpp_
#include "includes.h"
void slowPrint(string s){
	for(size_t i=0;i<s.size();++i){
		cout<<s[i];
		Sleep(20);
	}
}
void slowPrint(string s,string COLOR){
	cout<<COLOR;
	for(size_t i=0;i<s.size();++i){
		cout<<s[i];
		Sleep(50);
	}
	cout<<ORIGINAL;
}
void step0(){
	printTitle();
	Sleep(1000);
	slowPrint("\n\n                       Writer:  paulzrm\n");
}
void step1(){
	maxCoin=64;
	slowPrint("正在开始游戏\n");
	system("cls");
	clock_t st;
	yousyaColor=BLUE;
	enemyColor=RED;
	inTut=1;
	grid.init(15,15);
	grid.generateEmpty();
	player.setPos(2,8);player.setDir(2); 
	grid.add(player);
	if(Stage!=0)goto EndStage1;
	print(grid,player);
	for(int i=1;i<=5;++i){
		Sleep(1000);
		grid.remove(player);
		player.x++;
		grid.add(player);
		print(grid,player);
	}
	Sleep(2000);
	slowPrint("你：...？\n");
	Sleep(2000);
	slowPrint("这是哪儿...？\n");
	Sleep(2000);
	slowPrint("...\n");
	Sleep(2000);
	slowPrint("...\n");
	Sleep(4000);
	slowPrint("此时，一个声音在你耳边响起：\n");
	Sleep(1000);
	slowPrint("你醒了，");slowPrint("勇者",BLUE),slowPrint("。\n");
	Sleep(2000);
	slowPrint("...\n");
	Sleep(4000);
	slowPrint("你：...");slowPrint("勇者",BLUE),slowPrint("...？\n");
	Sleep(2000);
	slowPrint("那个声音：是的。你是"),slowPrint("勇者",BLUE),slowPrint("被我召唤到了异世界。你需要打败这里的"),slowPrint("魔王",RED),slowPrint("。\n");
	Sleep(2000);
	slowPrint("你：...");slowPrint("魔王",RED),slowPrint("...？\n");
	Sleep(2000);
	slowPrint("那个声音：是的。在那之前，我先来教你在这个世界最基本的战斗方式吧。\n");
	Sleep(2000);
	slowPrint("你可以用 W/A/S/D 向上/下/左/右走。\n");
	Sleep(2000);
	slowPrint("注意到你手上的剑了吗？你可以用键盘的上/下/左/右键去控制它的方向。\n");
	Sleep(2000);
	slowPrint("地图上的#是障碍物，你和你的剑都无法穿过它。\n");
	Sleep(2000);
	slowPrint("地图上还会有"),slowPrint("$",YELLOW),slowPrint("，代表金币，你可以捡起它。一个"),slowPrint("$",YELLOW),slowPrint("价值 10 枚金币。\n");
	Sleep(2000);
	slowPrint("你先来动动吧。\n");
	Sleep(2000);
	slowPrint("任务：收集160枚金币。\n",GREEN); 
	Sleep(2000);
	slowPrint("准备好了就按任意键开始。\n");
	system("pause");
	system("cls");
	haveCoin=1;
	print(grid,player);
	grid.genCoin();
	while(1){if(die)return; 
		update();
		print(grid,player);
		++standardClock;
		Sleep(100);
		if(player.money>=160)break;
	}
	EndStage1:;
	Stage=max(Stage,1);saveFile();
	if(Stage>=2){if(die)return; 
		clearEnemies(); 
		mov=0;
		for(int i=0;i<6;++i)newEnemy(15);
		grid.genCoin();countKill=0;
		enemyLimit=6;
		goto EndStage2;
	}
	slowPrint("那个声音：好的。现在你已经可以熟练移动了，"),slowPrint("勇者",BLUE),slowPrint("。\n"); 
	Sleep(2000);
	slowPrint("在"),slowPrint("魔王",RED),slowPrint("的领导下，"),slowPrint("魔物",RED),slowPrint("会攻击你。\n");
	slowPrint("魔物",RED),slowPrint("也有武器。如果你的武器碰到了它们的武器或者身体，那么它们就会"),slowPrint("死亡",RED),slowPrint("。\n");
	Sleep(2000); 
	slowPrint("反之，如果"),slowPrint("魔物",RED),slowPrint("的武器或者身体碰到了你的身体，那么你的生命值就会减少。虽然它们也会因此"),slowPrint("死亡",RED),slowPrint("，但这对你而言并不值得，对吧。\n");
	Sleep(2000);
	slowPrint("你的行动永远比"),slowPrint("魔物",RED),slowPrint("提前。\n");
	Sleep(2000); 
	slowPrint("试试和"),slowPrint("魔物",RED),slowPrint("战斗吧。\n");
	Sleep(2000);
	slowPrint("任务：击杀 10 只不移动的魔物。\n",GREEN); 
	Sleep(2000);
	slowPrint("准备好了就按任意键开始。\n");
	system("pause");
	system("cls");
	clearEnemies();
	Sleep(2000);mov=0;
	for(int i=0;i<6;++i)newEnemy(15);
	print(grid,player);
	grid.genCoin();countKill=0;
	enemyLimit=6;
	while(1){if(die)return; 
		update();
		if(checkCrash())End(0);
		print(grid,player);
		cout<<"当前击杀："<<countKill<<"    \n";
		++standardClock;
		Sleep(100);
		if(countKill>=10)break;
	}
	Sleep(2000);
	EndStage2:;
	Stage=max(Stage,2);saveFile();
	if(Stage>=3){if(die)return; 
		mov=1;
		clearEnemies();
		for(int i=0;i<6;++i)newEnemy(15);
		grid.genCoin();countKill=0;
		enemyLimit=6;enemySpeed=2;
		goto EndStage3;
	}
	slowPrint("那个声音：好的，现在你已经会攻击了。\n");
	Sleep(2000);
	slowPrint("在真正的世界中，"),slowPrint("魔物",RED),slowPrint("是会移动的。它们有一个视野范围，每只都可能不一样。\n");
	Sleep(2000);slowPrint("魔物",RED),slowPrint("很笨，面朝方向就是它们武器的方向。如果你和某只"),slowPrint("魔物",RED),slowPrint("的距离小于等于它的视野范围，且你处于它面朝方向偏左60度到偏右60度的范围内，那么你就会被它看到。\n");
	Sleep(2000);slowPrint("如果你处于某只"),slowPrint("魔物",RED),slowPrint("的视野范围内，那么它就会径直向你走来。但它很笨，不会绕开障碍物，如果被卡住就不会动了。\n");
	Sleep(2000);slowPrint("没有你视野的"),slowPrint("魔物",RED),slowPrint("会停下或者随机走动。\n");
	Sleep(2000);slowPrint("试试和"),slowPrint("魔物",RED),slowPrint("战斗吧。请小心。\n");
	slowPrint("任务：击杀 10 只移动的魔物。\n",GREEN); 
	Sleep(2000);
	slowPrint("准备好了就按任意键开始。\n"); 
	system("pause");
	system("cls");
	Sleep(2000);mov=1;
	clearEnemies();
	for(int i=0;i<6;++i)newEnemy(15);
	print(grid,player);
	grid.genCoin();countKill=0;
	enemyLimit=6;enemySpeed=2;
	while(1){if(die)return; 
		update();
		if(checkCrash())End(0);
		updateEnemy();
		if(checkCrash())End(0);
		print(grid,player);
		cout<<"当前击杀："<<countKill<<"    \n";
		++standardClock;
		Sleep(100);
		if(countKill>=10)break;
	}
	Sleep(2000);
	EndStage3:;
	Stage=max(Stage,3);saveFile();
	if(Stage>=4){if(die)return; 
		clearEnemies(); 
		for(int i=0;i<12;++i)newEnemy(15);
		mov=1;ableC=1;
		player.hp=3;
		grid.genCoin();countKill=0;
		enemyLimit=12;enemySpeed=3;
		goto EndStage4;
	}
	player.money+=100;
	slowPrint("那个声音：好的，现在你已经可以比较熟练的和"),slowPrint("魔物",RED),slowPrint("战斗了\n");
	Sleep(2000);
	slowPrint("作为"),slowPrint("勇者",BLUE),slowPrint("你有一些技能。\n");
	slowPrint("你的面朝方向为你的剑的方向。按下 c 可以在你的身后放下一个人造障碍物。你能够通过它（通过时会清除），而"),slowPrint("魔物",RED),slowPrint("会被阻挡 。\n");
	Sleep(2000);
	slowPrint("放置一个障碍物需要花费 3 枚金币。\n");
	Sleep(2000);
	slowPrint("请试试这个技能吧。\n");
	Sleep(2000);
	slowPrint("任务：存活一分钟。\n",GREEN);
	Sleep(2000);
	slowPrint("准备好了就按任意键开始。\n"); 
	system("pause");
	system("cls");
	clearEnemies(); 
	for(int i=0;i<12;++i)newEnemy(15);
	print(grid,player);mov=1;ableC=1;
	player.hp=3;
	grid.genCoin();countKill=0;
	enemyLimit=12;enemySpeed=3;
	st=clock();
	while(1){if(die)return; 
		while(enemies.size()<12)newEnemy(15);
		update();
		if(checkCrash())End(1);
		updateEnemy();
		if(checkCrash())End(1);
		print(grid,player);
		int rem=60-(clock()-st)/CLOCKS_PER_SEC;
		cout<<"还剩："<<rem<<" 秒   \n";
		if(rem<=0)break;
		++standardClock;
		Sleep(250);
	}
	Sleep(2000);
	EndStage4:;Stage=max(Stage,4);
	saveFile();
	if(Stage>=5){if(die)return; 
		ableF=1;mov=1;countKill=0;
		goto EndStage5;
	}
	slowPrint("那个声音：你还有一个技能。在没有设置信标时，你按下 f 可以设置一个信标。\n");
	Sleep(2000); 
	slowPrint("在有信标时按下 f 会立刻传送到信标的位置并回收它。\n");
	Sleep(2000);
	slowPrint("设置信标或者传送均需要花费 5 枚金币。\n");
	Sleep(2000);
	slowPrint("请试试这个技能吧。\n");
	Sleep(2000);
	slowPrint("任务：击杀3个敌人。此时若你和敌人的武器碰到一起，则你也会损失生命\n",GREEN);
	Sleep(2000);
	slowPrint("准备好了就按任意键开始。\n"); 
	system("pause");
	system("cls");
	clearEnemies();
	grid.init(3,30);
	grid.generateEmpty();
	player.setPos(2,12);player.setDir(1);
	grid.add(player);
	ableF=1;mov=1;
	newSpecialEnemy(2,18,3);
	newSpecialEnemy(2,20,3);
	newSpecialEnemy(2,22,3);
	print(grid,player);
	specialRule=1;countKill=0;
	enemyLimit=3;enemySpeed=3;
	while(1){if(die)return; 
		update();
		if(checkCrash())End(1);
		updateEnemy();
		if(checkCrash())End(1);
		print(grid,player);
		cout<<"当前击杀："<<countKill<<"    \n";
		++standardClock;
		Sleep(100);
		if(countKill>=3)break;
		if(enemies.size()==0)End(1);
	}
	specialRule=0;
	clearEnemies();
	EndStage5:;Stage=max(Stage,5);
	saveFile();
	slowPrint("那个声音：好的，你现在已经比较熟悉这个世界了。去战斗吧！\n");
	slowPrint("教程      完\n");
	maxCoin=12;
	saveFile(); 
	system("pause");
	return;
}
void prePlot(){
	if(Stage>=6)return;
	system("cls");
    slowPrint("███ 艾瑞斯编年史 ███████████████████████████████████████████\n");
    Sleep(2000);
    slowPrint("那个声音：欢迎来到艾瑞斯世界，");slowPrint("勇者",BLUE);slowPrint("。这里是神魔博弈的棋盘，也是你命中注定的战场。\n");
    Sleep(2000);
    slowPrint("你：棋盘...？那这些红色的是...？\n");
    Sleep(1500);
    slowPrint("那个声音：正如所见，那些都是");slowPrint("魔王",RED);slowPrint("卡洛梅的爪牙。它们蚕食着四大古陆，而你要做的——\n");
    Sleep(1800);
    slowPrint("你：（打断）四大古陆？\n");
    Sleep(1000);
    
    slowPrint("那个声音：（幻象中浮现四块发光大陆）\n");
    slowPrint("▄▄▄ 赤烬之地 - 燃烧着永恒业火的战场\n");
    slowPrint("封印着「炎核」，由炎之巨人守护的熔岩之心\n\n");
    Sleep(1500);
    slowPrint("▄▄▄ 霜骸冰原 - 时间凝结的极寒坟场\n");
    slowPrint("冰封着「霜心」，被冰霜女巫诅咒的凛冬核心\n\n");
    Sleep(1500);
    slowPrint("▄▄▄ 雷鸣裂谷 - 雷暴永不停息的深渊\n");
    slowPrint("禁锢着「雷纹臂铠」，由风暴领主把持的雷霆武装\n\n");
    Sleep(1500);
    slowPrint("▄▄▄ 影渊圣所 - 光无法抵达的禁忌领域\n");
    slowPrint("沉睡着「虚空之冠」，被暗影贤者守护的终焉王冕\n");
    Sleep(2000);

    slowPrint("你：这些圣器...能彻底消灭");slowPrint("魔王",RED);slowPrint("？\n");
    Sleep(1200);
    slowPrint("那个声音：（发出意味深长的笑声）当然，当四圣器齐聚之时——\n");
    Sleep(1000);
    slowPrint("（幻象突然扭曲，浮现出倒悬的王座）\n");
    slowPrint("那将是新纪元的开端。\n");
    Sleep(1800);

    slowPrint("你注意到幻象中");slowPrint("魔物",RED);slowPrint("身上的纹章了吗？\n");
    slowPrint("那是卡洛梅的烙印，它们会像嗅到血腥的鲨鱼般追踪你。\n");
    Sleep(1500);
    slowPrint("但记住，真正的威胁往往戴着伪善的面具...\n");
    Sleep(2000);
    slowPrint("（幻象突然消失）\n");
    slowPrint("那个声音：是时候了，");slowPrint("勇者",BLUE);slowPrint("。\n");
    
    slowPrint("███ 当前目标 ██ 存活 → 收集 → 抉择 █████████████████████\n");
    Sleep(1500);
    slowPrint("准备好了吗？马上该前往第一个大陆「赤烬之地」了。\n",GREEN);
    Sleep(1500);
    slowPrint("\n\n      Y 我已经准备好了！\n");
    slowPrint("\n\n      N 我还没有准备好...\n");
	while(1){if(die)return; 
    	if(GetAsyncKeyState(VK_Y)){
			Stage=6;
			saveFile(); 
			return;
		}
		if(GetAsyncKeyState(VK_N)){
			slowPrint("那你再想想吧，好了再走\n");
			Sleep(5000);
			slowPrint("准备好了吗？\n"); 
		}
	}
	Stage=6;
	saveFile(); 
	return;
}
void step2(){
	system("cls");
	if(Stage>=7)return;
	inTut=0;
	maxCoin=6;
	if(!skipPlot){
		skipPlot=1;
	    slowPrint("▄▄▄ 赤烬之地 - 燃烧着永恒业火的战场\n");
		slowPrint("封印着「炎核」，由炎之巨人守护的熔岩之心\n\n");
	    Sleep(1500);
		slowPrint("这里遍地火焰，导致障碍和金币都较少。");slowPrint("这里的"),slowPrint("魔物"),slowPrint("速度较慢，反应也比较迟钝。\n");
		slowPrint("勇者",BLUE),slowPrint("阁下选择这里作为第一个征服点，是很明智的决定。\n");
		for(int i=0;i<10;++i)slowPrint("."),Sleep(1000);
		slowPrint("我们到了。");slowPrint("勇者",BLUE),slowPrint("阁下，请小心迎敌。\n");
		system("pause");
		system("cls");		
	}
	clearEnemies();
	grid.init();
	player.init();
	player.setPos(64,64);
	grid.name="「赤烬之地」";
	grid.generate();
	grid.add(player);
	// Keep the continent dangerous without filling the entire map with
	// enemies before the player can read the battlefield.
	enemyLimit=48;
	enemySpeed=4;
	for(int i=0;i<48;++i)newEnemy(10);
	print(grid,player);
	while(1){
		if(die)return; 
		update();
		if(checkCrash())End(2);
		updateEnemy();
		if(checkCrash())End(2);
		print(grid,player);
		++standardClock;
		Sleep(100);
	}
	skipPlot=0;
}
void Play(){
	step1();if(die==1)return;
	prePlot();if(die==1)return;
	step2();if(die==1)return;
}
#endif
