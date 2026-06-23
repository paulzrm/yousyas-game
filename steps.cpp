#ifndef __steps_cpp_
#define __steps_cpp_
#include "includes.h"
void slowPrint(string s){
	for(int i=0;i<s.size();++i){
		cout<<s[i];
		Sleep(20);
	}
}
void slowPrint(string s,string COLOR){
	cout<<COLOR;
	for(int i=0;i<s.size();++i){
		cout<<s[i];
		Sleep(50);
	}
	cout<<ORIGINAL;
}
void slowestPrint(string s,string COLOR){
	cout<<COLOR;
	for(int i=0;i<s.size();++i){
		cout<<s[i];
		Sleep(1000);
	}
	cout<<ORIGINAL;
}
void step0(){
	printTitle();
	Sleep(1000);
	slowPrint("\n\n                       Author:  paulzrm\n");
}
void step1(){
//	if(Stage>=5)return;
	maxCoin=64;
	slowPrint("���ڿ�ʼ��Ϸ\n");
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
	slowPrint("�㣺...��\n");
	Sleep(2000);
	slowPrint("�����Ķ�...��\n");
	Sleep(2000);
	slowPrint("...\n");
	Sleep(2000);
	slowPrint("...\n");
	Sleep(4000);
	slowPrint("��ʱ��һ�����������������\n");
	Sleep(1000);
	slowPrint("�����ˣ�");slowPrint("����",BLUE),slowPrint("��\n");
	Sleep(2000);
	slowPrint("...\n");
	Sleep(4000);
	slowPrint("�㣺...");slowPrint("����",BLUE),slowPrint("...��\n");
	Sleep(2000);
	slowPrint("�Ǹ��������ǵġ�����"),slowPrint("����",BLUE),slowPrint("�����ٻ����������硣����Ҫ��������"),slowPrint("ħ��",RED),slowPrint("��\n");
	Sleep(2000);
	slowPrint("�㣺...");slowPrint("ħ��",RED),slowPrint("...��\n");
	Sleep(2000);
	slowPrint("�Ǹ��������ǵġ�����֮ǰ����������������������������ս����ʽ�ɡ�\n");
	Sleep(2000);
	slowPrint("������� W/A/S/D ����/��/��/���ߡ�\n");
	Sleep(2000);
	slowPrint("ע�⵽�����ϵĽ�����������ü��̵���/��/��/�Ҽ�ȥ�������ķ���\n");
	Sleep(2000);
	slowPrint("��ͼ�ϵ�#���ϰ�������Ľ����޷���������\n");
	Sleep(2000);
	slowPrint("��ͼ�ϻ�����"),slowPrint("$",YELLOW),slowPrint("��������ң�����Լ�������һ��"),slowPrint("$",YELLOW),slowPrint("��ֵ 10 ö��ҡ�\n");
	Sleep(2000);
	slowPrint("�����������ɡ�\n");
	Sleep(2000);
	slowPrint("�����ռ�160ö��ҡ�\n",GREEN);
	Sleep(2000);
	slowPrint("׼�����˾Ͱ��������ʼ��\n");
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
	slowPrint("�Ǹ��������õġ��������Ѿ����������ƶ��ˣ�"),slowPrint("����",BLUE),slowPrint("��\n");
	Sleep(2000);
	slowPrint("��"),slowPrint("ħ��",RED),slowPrint("���쵼�£�"),slowPrint("ħ��",RED),slowPrint("�ṥ���㡣\n");
	slowPrint("ħ��",RED),slowPrint("Ҳ���������������������������ǵ������������壬��ô���Ǿͻ�"),slowPrint("����",RED),slowPrint("��\n");
	Sleep(2000);
	slowPrint("��֮�����"),slowPrint("ħ��",RED),slowPrint("��������������������������壬��ô�������ֵ�ͻ���١���Ȼ����Ҳ�����"),slowPrint("����",RED),slowPrint("�����������Բ���ֵ�ã��԰ɡ�\n");
	Sleep(2000);
	slowPrint("����ж���Զ��"),slowPrint("ħ��",RED),slowPrint("��ǰ��\n");
	Sleep(2000);
	slowPrint("���Ժ�"),slowPrint("ħ��",RED),slowPrint("ս���ɡ�\n");
	Sleep(2000);
	slowPrint("���񣺻�ɱ 10 ֻ���ƶ���ħ�\n",GREEN);
	Sleep(2000);
	slowPrint("׼�����˾Ͱ��������ʼ��\n");
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
		cout<<"��ǰ��ɱ��"<<countKill<<"    \n";
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
	slowPrint("�Ǹ��������õģ��������Ѿ��ṥ���ˡ�\n");
	Sleep(2000);
	slowPrint("�������������У�"),slowPrint("ħ��",RED),slowPrint("�ǻ��ƶ��ġ�������һ����Ұ��Χ��ÿֻ�����ܲ�һ����\n");
	Sleep(2000);slowPrint("ħ��",RED),slowPrint("�ܱ����泯����������������ķ���������ĳֻ"),slowPrint("ħ��",RED),slowPrint("�ľ���С�ڵ���������Ұ��Χ�����㴦�����泯����ƫ��60�ȵ�ƫ��60�ȵķ�Χ�ڣ���ô��ͻᱻ��������\n");
	Sleep(2000);slowPrint("����㴦��ĳֻ"),slowPrint("ħ��",RED),slowPrint("����Ұ��Χ�ڣ���ô���ͻᾶֱ���������������ܱ��������ƿ��ϰ���������ס�Ͳ��ᶯ�ˡ�\n");
	Sleep(2000);slowPrint("û������Ұ��"),slowPrint("ħ��",RED),slowPrint("��ͣ�»�������߶���\n");
	Sleep(2000);slowPrint("���Ժ�"),slowPrint("ħ��",RED),slowPrint("ս���ɡ���С�ġ�\n");
	slowPrint("���񣺻�ɱ 10 ֻ�ƶ���ħ�\n",GREEN);
	Sleep(2000);
	slowPrint("׼�����˾Ͱ��������ʼ��\n");
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
		cout<<"��ǰ��ɱ��"<<countKill<<"    \n";
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
	slowPrint("�Ǹ��������õģ��������Ѿ����ԱȽ������ĺ�"),slowPrint("ħ��",RED),slowPrint("ս����\n");
	Sleep(2000);
	slowPrint("��Ϊ"),slowPrint("����",BLUE),slowPrint("����һЩ���ܡ�\n");
	slowPrint("����泯����Ϊ��Ľ��ķ��򡣰��� c ����������������һ�������ϰ�����ܹ�ͨ������ͨ��ʱ�����������"),slowPrint("ħ��",RED),slowPrint("�ᱻ�赲 ��\n");
	Sleep(2000);
	slowPrint("����һ���ϰ�����Ҫ���� 3 ö��ҡ�\n");
	Sleep(2000);
	slowPrint("������������ܰɡ�\n");
	Sleep(2000);
	slowPrint("���񣺴��һ���ӡ�\n",GREEN);
	Sleep(2000);
	slowPrint("׼�����˾Ͱ��������ʼ��\n");
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
		cout<<"��ʣ��"<<rem<<" ��   \n";
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
	slowPrint("�Ǹ��������㻹��һ�����ܡ���û�������ű�ʱ���㰴�� f ��������һ���űꡣ\n");
	Sleep(2000);
	slowPrint("�����ű�ʱ���� f �����̴��͵��ű��λ�ò���������\n");
	Sleep(2000);
	slowPrint("�����ű���ߴ��;���Ҫ���� 5 ö��ҡ�\n");
	Sleep(2000);
	slowPrint("������������ܰɡ�\n");
	Sleep(2000);
	slowPrint("���񣺻�ɱ3�����ˡ���ʱ����͵��˵���������һ������Ҳ����ʧ����\n",GREEN);
	Sleep(2000);
	slowPrint("׼�����˾Ͱ��������ʼ��\n");
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
		cout<<"��ǰ��ɱ��"<<countKill<<"    \n";
		++standardClock;
		Sleep(100);
		if(countKill>=3)break;
		if(enemies.size()==0)End(1);
	}
	slowPrint("�Ǹ��������õģ��������Ѿ��Ƚ���Ϥ��������ˡ�ȥս���ɣ�\n");
	slowPrint("�̳�      ��\n");
	EndStage5:;Stage=max(Stage,5);
	specialRule=0;
	clearEnemies();
	saveFile();
	maxCoin=12;
	saveFile();
	system("pause");
	return;
}
void prePlot(){
	if(Stage>=6)return;
	system("cls");
    slowPrint("������ ����˹ ���������������������������ߨ�����������ħ��������������������������������������������\n");
    Sleep(2000);
    slowPrint("�Ǹ���������ӭ��������˹���磬");slowPrint("����",BLUE);slowPrint("����������ħ���ĵ����̣�Ҳ��������ע����ս����\n");
    Sleep(2000);
    slowPrint("�㣺����...������Щ��ɫ����...��\n");
    Sleep(1500);
    slowPrint("�Ǹ�������������������Щ����");slowPrint("ħ��",RED);slowPrint("����÷��צ�������ǲ�ʳ���Ĵ��½������Ҫ���ġ���\n");
    Sleep(1800);
    slowPrint("�㣺����ϣ��Ĵ��½��\n");
    Sleep(1000);

    slowPrint("�Ǹ��������������и����Ŀ鷢���½��\n");
    slowPrint("�{�{�{ ���֮�� - ȼ��������ҵ���ս��\n");
    slowPrint("��ӡ�š��׺ˡ�������֮�����ػ�������֮��\n\n");
    Sleep(1500);
    slowPrint("�{�{�{ ˪����ԭ - ʱ������ļ����س�\n");
    slowPrint("�����š�˪�ġ�������˪Ů��������ݶ�����\n\n");
    Sleep(1500);
    slowPrint("�{�{�{ �����ѹ� - �ױ�����ͣϢ����Ԩ\n");
    slowPrint("�����š����Ʊ��������ɷ籩�����ѳֵ�������װ\n\n");
    Sleep(1500);
    slowPrint("�{�{�{ ӰԨʥ�� - ���޷��ִ�Ľ�������\n");
    slowPrint("��˯�š����֮�ڡ�������Ӱ�����ػ�����������\n");
    Sleep(2000);

    slowPrint("�㣺��Щʥ��...�ܳ�������");slowPrint("ħ��",RED);slowPrint("��\n");
    Sleep(1200);
    slowPrint("�Ǹ���������������ζ���Ц������Ȼ������ʥ�����֮ʱ����\n");
    Sleep(1000);
    slowPrint("������ͻȻŤ�������ֳ�������������\n");
    slowPrint("�ǽ����¼�Ԫ�Ŀ��ˡ�\n");
    Sleep(1800);

    slowPrint("��ע�⵽������");slowPrint("ħ��",RED);slowPrint("���ϵ���������\n");
    slowPrint("���ǿ���÷����ӡ�����ǻ����ᵽѪ�ȵ������׷���㡣\n");
    Sleep(1500);
    slowPrint("����ס����������в��������α�Ƶ����...\n");
    Sleep(2000);
    slowPrint("������ͻȻ��ʧ��\n");
    slowPrint("�Ǹ���������ʱ���ˣ�");slowPrint("����",BLUE);slowPrint("��\n");

    slowPrint("������ ��ǰĿ�� ���� ��� �� �ռ� �� ���� ������������������������������������������\n");
    Sleep(1500);
    slowPrint("׼�����������ϸ�ǰ����һ����½�����֮�ء��ˡ�\n",GREEN);
    Sleep(1500);
    slowPrint("\n\n      Y ���Ѿ�׼�����ˣ�\n");
    slowPrint("\n\n      N �һ�û��׼����...\n");
	while(1){if(die)return;
    	if(GetAsyncKeyState(VK_Y)){
			Stage=6;
			saveFile();
			return;
		}
		if(GetAsyncKeyState(VK_N)){
			slowPrint("����������ɣ���������\n");
			Sleep(5000);
			slowPrint("׼��������\n");
		}
	}
	Stage=6;
	saveFile();
	return;
}
void step2(){
	system("cls");
	if(Stage>=7)return;
	maxCoin=6;countKey=0;enemyEyesight=5;
	if(!skipPlot){
		skipPlot=1;
	    slowPrint("�{�{�{ ���֮�� - ȼ��������ҵ���ս��\n");
		slowPrint("��ӡ�š��׺ˡ�������֮�����ػ�������֮��\n\n");
	    Sleep(1500);
	    slowPrint("���׺ˡ�λ�ڳ��ʥ���ͼ���� S ��ǡ�����ʥ����Ҫ���� 4 ��Կ�ף��� K ��ǣ��ֲ��ڵ�ͼ�С�����Ҫ�������ǲ��ܽ���ʥ�\n");
		Sleep(1500);
		slowPrint("�����ػ��棬�����ϰ��ͽ�Ҷ����١�");slowPrint("�����"),slowPrint("ħ��"),slowPrint("����֮���ˣ��ٶȽ�������ӦҲ�Ƚϳٶۡ�\n");
		slowPrint("����",BLUE),slowPrint("����ѡ��������Ϊ��һ�������㣬�Ǻ����ǵľ�����\n");
		for(int i=0;i<10;++i)slowPrint("."),Sleep(1000);
		slowPrint("���ǵ��ˡ�");slowPrint("����",BLUE),slowPrint("���£���С��ӭ�С�\n");
		system("pause");
		system("cls");
		saveFile();
	}
	clearEnemies();
	grid.init();
	player.init();
	player.setPos(40,40);
	grid.name="�����֮�ء�";
	grid.generate();
	grid.add(player);
	for(int i=0;i<4;++i)grid.genKey();attackWaitTime=2;nKey=4;
	grid.genPalace();enemyLimit=72;enemyEyesight=5;
	for(int i=0;i<64;++i)newEnemy(enemyEyesight);
	print(grid,player);touchPalace=0;countKey=0;
	while(1){
		if(die)return;
		update();
		if(checkCrash())End(2);
		updateEnemy();
		if(checkCrash())End(2);
		print(grid,player);
		cout<<"��ǰ�ҵ���Կ�������� "<<countKey<<'\n';
		if(countKey==4 and touchPalace==1)break;
		++standardClock;
		Sleep(100);
	}Stage=7;
	skipPlot=0;
	saveFile();
}
void step3(){
	system("cls");
	if(Stage>=8)return;enemyEyesight=5;
	if(!skipPlot){
		skipPlot=1;
		slowPrint("��Կ�ײ�����ͭ���ŵ�˲�䣬�ض�ɽҡ��\n");
		slowPrint("����µ��ҽ�ͻȻ���ڣ�񷶥����ȼ�յľ�ʯ��\n");
		for(int i=0;i<3;i++) slowPrint("��",RED),Sleep(500);
		slowPrint("\n�Ǹ����������ȥ���kҪ�����ˡ���\n");
		for(int i=0;i<5;++i)slowPrint("."),Sleep(1000);
		slowPrint("���������ͻȻ���ߴ���һ�����죬��ͭ���ź����ˡ�\n");
		slowPrint("��δ������Ӧ��ǰ�ĺڰ����������ͻȻ������һ����档���㿴������ʱ���ŷ������ѱ���֮��������Χ��\n");
		Sleep(1000);
		slowPrint("�Ǹ��������������������"),slowPrint("����",BLUE),slowPrint("������Ҫ���90�룬���ܻ�á��׺ˡ���\n");
		slowPrint("�㻷�����ܣ���û�з����κ���·����������ò��Ҳû�������ϰ��\n");
		slowPrint("���ﻹ���緢���ҽ����������һ��λ��ͣ������ 6 �룬��ô�ͻ��ܵ��˺���\n");
		slowPrint("û�취��ֻ�����ˣ�\n");
		Sleep(1000);
		system("pause");
		system("cls");
	}
	clearEnemies();cantStop=1;
	grid.init(16,16);ableC=0;
	player.init();
	player.setPos(8,8);
	grid.name="�����֮�ء�����ʥ��";
	grid.generateEmpty();
	grid.add(player);enemyLimit=12;attackWaitTime=2;
	for(int i=0;i<12;++i)newEnemy(enemyEyesight);
	print(grid,player);lastMove=clock();
	clock_t st;
	st=clock();
	while(1){if(die)return;
		while(enemies.size()<6)newEnemy(enemyEyesight);
		update();
		if(checkCrash())End(2);
		updateEnemy();
		if(checkCrash())End(2);
		print(grid,player);
		int rem=90-(clock()-st)/CLOCKS_PER_SEC;
		int stay=6-(clock()-lastMove)/CLOCKS_PER_SEC;
		cout<<"��ʣ��"<<rem<<" ��   \n";
		cout<<"��ͣ�� "<<stay<<" ��ͻ��ܵ��˺�\n";
		if(stay==0){
			--player.hp;
			lastMove=clock();
			if(player.hp==0)End(2);
		}
		if(rem<=0)break;
		++standardClock;
		Sleep(100);
	}
	Stage=8;ableC=1;
	skipPlot=0;
	saveFile();
	slowPrint("���ڣ����������ˡ�\n");
	slowPrint("������������ �׺˹��� ����������������������������������������������������������\n");
	slowPrint("�������׾���ͻȻ��ֱ�������ҽ������̳��\n");
	for(int i=0;i<3;i++) slowPrint("��",RED),Sleep(500);
	slowPrint("\n���׺ˡ��������䵽�����ģ���ʹ�д����������ů\n");
	slowPrint("���׺˱���ͻȻӳ����ĵ�Ӱ��");
	slowPrint("˫�۷��ź��",RED);slowPrint("��\n");
	slowPrint("�����������úܺ�...��213�š�����...\n",DARKGRAY);
	Sleep(1500);
	slowPrint("???\n");
	Sleep(1500);
	slowPrint("û���㷴Ӧ�������Ǹ������ֳ����ˡ�\n");
	slowPrint("�Ǹ����������ڸ�ǰ����˪����ԭ����\n");
	slowPrint("�{�{�{ ˪����ԭ - ʱ�侲ֹ�ļ����س�\n");
	slowPrint("��ӡ���ܹ��������ġ�˪�ġ����ɱ�˪Ů���ػ�\n\n");
    slowPrint("׼�����������ϸ�ǰ���ڶ�����½��˪����ԭ���ˡ�\n",GREEN);
    Sleep(1500);
    slowPrint("\n\n      Y ���Ѿ�׼�����ˣ�\n");
    slowPrint("\n\n      N �һ�û��׼����...\n");
	while(1){if(die)return;
    	if(GetAsyncKeyState(VK_Y)){
			Stage=8;
			saveFile();
			return;
		}
		if(GetAsyncKeyState(VK_N)){
			slowPrint("����������ɣ���������\n");
			Sleep(5000);
			slowPrint("׼��������\n");
		}
	}
}
void step4(){
	system("cls");
	if(Stage>=9)return;
	maxCoin=6;countKey=0;touchPalace=0;
	if(!skipPlot){
		skipPlot=1;
	    slowPrint("�{�{�{ ˪����ԭ - ʱ�侲ֹ�ļ����س�\n");
		slowPrint("��ӡ�š�˪�ġ����ɱ�˪Ů���ػ��ı�˪֮��\n\n");
	    Sleep(1500);
	    slowPrint("��˪�ġ�λ��˪��ʥ���ͼ���� S ��ǡ�����ʥ����Ҫ���� 6 ��Կ�ף��� K ��ǣ��ֲ��ڵ�ͼ�С�����Ҫ�������ǲ��ܽ���ʥ�\n");
		Sleep(1500);
		slowPrint("�����ر������ϰ�������������Թ��ĵ�ͼ��");slowPrint("�����"),slowPrint("ħ��"),slowPrint("�Ǳ�˪Ů�ף���Ұ�Ϲ㵫�������١�\n");
		slowPrint("����",BLUE),slowPrint("���£������úõ��ΰɡ�\n");
		for(int i=0;i<10;++i)slowPrint("."),Sleep(1000);
		slowPrint("���ǵ��ˡ�");slowPrint("����",BLUE),slowPrint("���£���С��ӭ�С�\n");
		system("pause");
		system("cls");
		saveFile();
	}
	clearEnemies();
	grid.init();
	player.init();
	player.setPos(40,40);
	grid.name="��˪����ԭ��";
	grid.init();
	player.init();
	grid.generateMaze(6);
	player.setPos(40,40);enemyLimit=48;
	grid.add(player);enemyEyesight=12;attackWaitTime=2;
	for(int i=0;i<32;++i)newEnemy(enemyEyesight);
	for(int i=0;i<4;++i)grid.genCoin();
	while(1){
		if(die)return;
		update();
		if(checkCrash())End(2);
		updateEnemy();
		if(checkCrash())End(2);
		print(grid,player);
		cout<<"��ǰ�ҵ���Կ�������� "<<countKey<<'\n';
		if(countKey==6 and touchPalace==1)break;
		++standardClock;
		Sleep(100);
	}Stage=9;
	skipPlot=0;
	saveFile();
}
void step5(){
    system("cls");
    if(Stage>=10)return;enemyEyesight=12;
    if(!skipPlot){
        skipPlot=1;
        slowPrint("��Կ�ײ���������ŵ�˲�䣬�̹ǵĺ����Х������\n");
        slowPrint("����µı���ͻȻ���ѣ�񷶥׹�·����ı�׶��\n");
        for(int i=0;i<3;i++) slowPrint("��",CYAN),Sleep(500);
        slowPrint("\n�Ǹ����������ţ����ȥ���k������Ҫ����һ�С���\n");
        for(int i=0;i<5;++i)slowPrint("."),Sleep(1000);
        slowPrint("\n��̤��ʥ���ɲ�ǣ�����ı��ź�Ȼ�պϡ�\n");
        slowPrint("����ɫ�ı�����ǽ�������������������������Ĺ⡣�����и��ֳ���ʮ���ֱֳ��ȵĲ԰���Ӱ��\n");
        Sleep(1000);
        slowPrint("�Ǹ��������Ż��죺���Ǻ�����������"),slowPrint("����",BLUE),slowPrint("���ڼ����д��90�룬���ܻ�á�˪�ġ���\n");
        slowPrint("�㷢�ֵ��渲���ű���ı��㣬�κ������ϰ��ﶼ�ᱻ�������ѡ�\n");
        slowPrint("�����ļӳ��£�ʥ������ʱ���ܳ���һЩ��Ȼ�ϰ������Ҳ��ͻȻ��ʧ��\n");
        slowPrint("�̹ǵ��Ϻ�������ʴ�㡣�����ͬһλ��ͣ������6�룬��˪�ͻ����������֫��\n");
        slowPrint("û����·��Ψ��ǰ�У�\n");
        Sleep(1000);
        system("pause");
        system("cls");
    }
	clearEnemies();cantStop=1;
	grid.init(16,16);ableC=0;
	player.init();
	player.setPos(8,8);
	grid.name="��˪����ԭ������ʥ��";
	grid.generateEmpty();
	grid.add(player);enemyLimit=12;attackWaitTime=2;
	for(int i=0;i<12;++i)newEnemy(enemyEyesight);
	print(grid,player);lastMove=clock();
	clock_t st;
	st=clock();
	while(1){if(die)return;
		while(enemies.size()<6)newEnemy(enemyEyesight);
		update();
		if(checkCrash())End(2);
		updateEnemy();
		if(checkCrash())End(2);
		print(grid,player);
		grid.updateObstacle();
		int rem=90-(clock()-st)/CLOCKS_PER_SEC;
		int stay=6-(clock()-lastMove)/CLOCKS_PER_SEC;
		cout<<"��ʣ��"<<rem<<" ��   \n";
		cout<<"��ͣ�� "<<stay<<" ��ͻ��ܵ��˺�\n";
		if(stay==0){
			--player.hp;
			lastMove=clock();
			if(player.hp==0)End(2);
		}
		if(rem<=0)break;
		++standardClock;
		Sleep(100);
	}
    Stage=10;ableC=1;
    skipPlot=0;
    saveFile();
    slowPrint("���ڣ��̹ǵĺ���ͣϢ�ˡ�\n");
    slowPrint("������������ ˪�Ĺ��� ����������������������������������������������������������\n");
    slowPrint("�����б�˪Ů��ͻȻ���ѣ���������Ʈ���̳��\n");
    for(int i=0;i<3;i++) slowPrint("?",CYAN),Sleep(500);
    slowPrint("\n��˪�ġ���������������ģ�������͸�����˲���������\n");
    slowPrint("��˪���ڲ�������ĵ�Ӱ��");
    slowPrint("���ҽ�������",CYAN);slowPrint("��\n");
    slowPrint("���������ϸ���...��213�š�����...\n",DARKGRAY);
    Sleep(1500);
    slowPrint("???\n");
    Sleep(1500);
    slowPrint("�Ǹ�����ǿ�д�������˼����\n");
    slowPrint("�Ǹ��������������ǡ������ѹȡ������籩����������\n");
    slowPrint("�{�{�{ �����ѹ� - ����ͣЪ���ױ���Ԩ\n");
    slowPrint("��˯���ܲٿ������ġ����Ʊ�������С�����Ŀ�ŭ\n\n");
    slowPrint("׼�������𣿼���ǰ����������֮�ء������ѹȡ���\n",GREEN);
    Sleep(1500);
    slowPrint("\n\n      Y ���Ѿ�׼�����ˣ�\n");
    slowPrint("\n\n      N �һ�û��׼����...\n");
	while(1){if(die)return;
    	if(GetAsyncKeyState(VK_Y)){
			Stage=10;
			saveFile();
			return;
		}
		if(GetAsyncKeyState(VK_N)){
			slowPrint("����������ɣ���������\n");
			Sleep(5000);
			slowPrint("׼��������\n");
		}
	}
}
void step6(){
	system("cls");
	if(Stage>=11)return;
	maxCoin=10;countKey=0;touchPalace=0;
	if(!skipPlot){
		skipPlot=1;
	    slowPrint("�{�{�{ �����ѹ� - ����ͣЪ���ױ���Ԩ\n");
		slowPrint("��ӡ�š����Ʊ�������������֮���ػ����ױ�ʥ��\n\n");
	    Sleep(1500);
	    slowPrint("�����Ʊ�����λ������ʥ���ͼ���� S ��ǡ�����ʥ����Ҫ���� 8 ��Կ�ף��� K ��ǣ��ֲ��ڵ�ͼ�С�����Ҫ�������ǲ��ܽ���ʥ�\n");
		Sleep(1500);
		slowPrint("�����"),slowPrint("ħ��"),slowPrint("������֮�飬�����ͷ�Ӧ���쵫��Ұ��խ��\n");
		slowPrint("����",BLUE),slowPrint("���£������úõ��ΰɡ�\n");
		for(int i=0;i<10;++i)slowPrint("."),Sleep(1000);
		slowPrint("���ǵ��ˡ�");slowPrint("����",BLUE),slowPrint("���£���С��ӭ�С�\n");
		system("pause");
		system("cls");
		saveFile();
	}
	clearEnemies();
	grid.init();
	player.init();
	player.setPos(40,40);
	grid.name="�������ѹȡ�";
	grid.init();
	player.init();
	grid.generateMaze(8);
	player.setPos(40,40);enemyLimit=54;
	grid.add(player);enemyEyesight=3;
	for(int i=0;i<36;++i)newEnemy(enemyEyesight);
	for(int i=0;i<4;++i)grid.genCoin();
	enemyStopTime=1;attackWaitTime=0;
	while(1){
		if(die)return;
		update();
//		cout<<"END update player\n";
//		system("pause");
		if(checkCrash())End(2);
//		cerr<<"END check crash\n";
//		system("pause");
		updateEnemy();
//		cerr<<"END update enemy\n";
//		system("pause");
		if(checkCrash())End(2);
//		cerr<<"END check crash\n";
//		system("pause");
		print(grid,player);
		cout<<"��ǰ�ҵ���Կ�������� "<<countKey<<'\n';
		if(countKey==8 and touchPalace==1)break;
		++standardClock;
		Sleep(100);
//		system("pause");
//		system("cls");
	}Stage=11;
	skipPlot=0;
	saveFile();
}
void step7(){
    system("cls");
    if(Stage>=12)return;enemyEyesight=3;enemyStopTime=1;attackWaitTime=0;
    if(!skipPlot){
      	 skipPlot=1;
        slowPrint("��Կ�ײ����������ŵ�˲�䣬���۵��׹⻮����ʣ�\n");
        slowPrint("����µĵ��濪ʼ�����񷶥���¿񱩵����磡\n");
        for(int i=0;i<3;i++) slowPrint("!",YELLOW),Sleep(500);
        slowPrint("\n�Ǹ��������ٵغ��������ȥ���籩�����Ѿ����������Ĵ��ڣ�\n");
        for(int i=0;i<5;++i)slowPrint("."),Sleep(1000);
        slowPrint("\n�����ʥ���ɲ�ǣ�����ľ��ű��������顣\n");
        slowPrint("�����������ų�������ζ�����ܵ������и��ֳ������ֳ���ǹ������֮�顣\n");
        Sleep(1000);
        slowPrint("�Ǹ��������ŵ�����Ļ��죺����������������"),slowPrint("����",BLUE),slowPrint("�����ױ��д��90�룬���ܻ�á����Ʊ�������\n");
        slowPrint("�㷢�ֵ��沼���˵���Ľ�����·���κ��ϰ��ﶼ�ᱻ�׻����顣\n");
        slowPrint("�ױ�����������ʥ�������λ�ã��� x ��ʾ�������ͻ���ʧ����ֵ���������ϵ�װ�����Ա�֤�����ھ�����2���������ɡ�\n");
        slowPrint("�񱩵ĵ������ڸ�������ж��������ͬһλ��ͣ������6�룬�ͻᱻ�׵�������\n");
        slowPrint("Ψ��ֱ��籩������ͨ��������\n");
        Sleep(1000);
        system("pause");
        system("cls");
    }
	clearEnemies();cantStop=1;
	grid.init(16,16);ableC=0;
	player.init();
	player.setPos(8,8);
	grid.name="�������ѹȡ�����ʥ��";
	grid.generateEmpty();enemyLimit=9;
	grid.add(player);enemyEyesight=3;enemyStopTime=1;attackWaitTime=0;
	for(int i=0;i<6;++i)newEnemy(enemyEyesight);
	print(grid,player);lastMove=clock();
	clock_t st;
	st=clock();
	while(1){if(die)return;
		while(enemies.size()<4)newEnemy(enemyEyesight);
		grid.updateLightening();
		update();
		if(player.hp==0)End(2);
		if(checkCrash())End(2);
		updateEnemy();
		if(checkCrash())End(2);
		print(grid,player);
		int rem=90-(clock()-st)/CLOCKS_PER_SEC;
		int stay=6-(clock()-lastMove)/CLOCKS_PER_SEC;
		cout<<"��ʣ��"<<rem<<" ��   \n";
		cout<<"��ͣ�� "<<stay<<" ��ͻ��ܵ��˺�\n";
		if(stay<=0){
			--player.hp;
			lastMove=clock();
			if(player.hp==0)End(2);
		}
		if(rem<=0)break;
		++standardClock;
		Sleep(100);
	}
	Stage=12;ableC=1;
    skipPlot=0;
    saveFile();
    slowPrint("���ڣ��񱩵�������ɢ�ˡ�\n");
    slowPrint("������������ ���ƹ��� ����������������������������������������������������������\n");
    slowPrint("����������֮��ͻȻ���⣬�������������̳��\n");
    for(int i=0;i<3;i++) slowPrint("?",YELLOW),Sleep(500);
    slowPrint("\n�����Ʊ�������������������ֱ��ϣ������д�������ս��������\n");
    slowPrint("����������ӳ����ĵ�Ӱ��");
    slowPrint("���������׹�",YELLOW);slowPrint("��\n");
    slowPrint("�������������...��213�š�����...\n",DARKGRAY);
    Sleep(1500);
    slowPrint("???\n");
    Sleep(1500);
    slowPrint("�Ǹ������ٴ����𣬵������ж���һ˿������\n");
    slowPrint("�Ǹ���������ϲ��ͨ����ȫ��������\n");
    slowPrint("�����������һվ������ӰԨʥ������\n");
    slowPrint("�{�{�{ ӰԨʥ�� - ���޷��ִ�Ľ�������\n");
    slowPrint("�����˯������ʥ�����ȴ�����ĵ�����\n\n");
    slowPrint("׼�������𣿼���ǰ������֮�ء�ӰԨʥ������\n",GREEN);
    Sleep(1500);
    slowPrint("\n\n      Y ���Ѿ�׼�����ˣ�\n");
    slowPrint("\n\n      N �һ�û��׼����...\n");
	while(1){if(die)return;
    	if(GetAsyncKeyState(VK_Y)){
			Stage=12;
			saveFile();
			return;
		}
		if(GetAsyncKeyState(VK_N)){
			slowPrint("����������ɣ���������\n");
			Sleep(5000);
			slowPrint("׼��������\n");
		}
	}
}
void step8() {
	if(Stage>=13)return;
    system("cls");
    slowPrint("������������ ӰԨʥ�� ����������������������������������������������������������\n");
    slowPrint("��̤��ʥ����˲�䣬�㷢�����С�ʥ������ʼ������Ͷ������۵İ׹⣩\n");
    slowPrint("�Ǹ�����������...�ȵ���һ����...\n", DARKGRAY);
    Sleep(1500);

    // �����ʾ�׶�
    slowPrint("�׹��и��ֳ�����ս���طţ���Щ����նɱ�ġ�ħ�",RED);
    slowPrint("��ȥ��ɫ��ǣ�¶���������ʵ��ò��\n");
    for(int i=0;i<3;i++) slowPrint("?",YELLOW),Sleep(500); // �����η��ű�ʾ������Ƭ
    slowPrint("\n��е������֪�������ѽ������ѡ��213�š�\n",DARKGRAY);
    Sleep(1000);

    slowPrint("�㣺��Щ...�������ࣿ��\n");
    slowPrint("X-0ϵͳ��׼ȷ��˵����������ѡ�ߡ�\n");
    slowPrint("ħ����÷����ʵ���ѹ������������������Ϸ��ֻ��Ϊ��ѡ���µ�ħ����");
    slowPrint("ħ������������е�������Ϊֻ������Ķ���ܼ�Ԧħ���������\n");
    slowPrint("��Щ��ɫ�������֪����������������Ϊ�Լ���նɱħ�\n",DARKGRAY);
    Sleep(1500);

    slowestPrint("ϲ�������Ϸ��\n",L_RED);
    Sleep(3000);

    slowPrint("������ͻȻŤ�����Σ���¶����ʵ��̬����һ������������׵�Ȩ�ȣ�\n");
    slowPrint("X-0ϵͳ��������ġ�ս������");
    slowPrint(to_string(countKill).c_str(), countKill>50?RED:YELLOW);
    slowPrint("����Ч��ɱ\n");
    slowPrint("��Щ��������ħ��֮������Դ��\n",DARKGRAY);
    Sleep(2000);

    // ���ȳ�������
    yousyaColor=WHITE;
    grid.init(5,15);
    grid.generateEmpty();
    player.setPos(3,8);
    grid.name="�����ɻ��ȡ�";
    for(int y=1;y<=5;y++){
        grid.set(y,1,-2);    // ����ɫ���򣨵�����Ѫ����
        grid.set(y,2,-2);
        grid.set(y,15,-3);   // �Ҳ���ɫ���򣨵������Ѻۣ�
        grid.set(y,14,-3);
    }

    // ����ϸ��
    slowPrint("��������������������������������������������������������������������������������\n");
    slowPrint("���ĺ�ɫ���Ų������׺�Ѫ������鹿��š����꼴���ԡ���\n");
    slowPrint("�Ҳ����ɫ�������ƾ�������ᣬ�������š���������������\n");
    slowPrint("��ɫ���ȵĵ���������������Ѫ�����ֱ�ͨ����������\n");

    // ѡ������
    slowPrint("������������ ��������ѡ�� ��������������������������������������������������\n");
    slowPrint("[��ɫ����]",RED);slowPrint(" ���Իع��������\n");
    slowPrint(" - ������������֮���ܳ�Խ���\n");
    slowPrint(" - ����Ҫ����Լ����������",RED);slowPrint(to_string(countKill));slowPrint("����ɱ\n");
    slowPrint("[��ɫ����]",BLUE);slowPrint(" ����ħ������\n");
    slowPrint(" - ������ͬ����������౾��\n");
    slowPrint(" - �����ͳ��",RED);slowPrint("����",DARKGRAY);slowPrint("��",BLUE);slowPrint("ħ��",DARKGRAY);slowPrint("��˫��Ȩ��\n");
    slowPrint("\n�ƶ��������ˣ�A/���������  D/��ѡ��Ȩ��\n",WHITE);

    // ��̬������ʾ
    if(countKill > 500){
        slowPrint("��Ȩ���ϵ�����������Ц������Ũ���Ѵ�");
        slowPrint("97%",RED);slowPrint("��\n");
        slowPrint("X-0ϵͳ������������������ĺ�ѡ�ߡ�\n",GREEN);
    }else if(countKill < 100){
        slowPrint("��Ȩ���ϵ�������Ŀ���ᣬ����Ũ�Ƚ�");
        slowPrint("12%",CYAN);slowPrint("��\n");
        slowPrint("X-0ϵͳ��������ʴȻẦ���㡣\n",DARKGRAY);
    }
    Sleep(5000);
    system("pause");
    system("cls");
    // �ȴ�����
    print(grid,player);skipPlot=0;
    while(true){
        update();
        print(grid,player);
        if(player.y <= 2){ // ��ɫ����
            slowPrint("��������ŷ����룬�����������Ϣ��                        \n",CYAN);
            slowPrint("ȷ��Ҫ�������������ƣ�[Y/N]                      \n");
            if(GetAsyncKeyState('Y')){
                slowPrint("���棺������ܾ����ܣ��㽫����������                \n",RED);
                slowPrint("ȷ��Ҫ�������������ƣ�[Y/N]                      \n");
                if(GetAsyncKeyState('Y')){
	                Stage=14;
	                return;
				}
				system("cls");
            }
        }
        else if(player.y >= 14){ // ��ɫȨ��
            slowPrint("������������������������                      \n",DARKGRAY);
            slowPrint("ȷ��Ҫ��Ϊ��108��ħ����[Y/N]                               \n");
            if(GetAsyncKeyState('Y')){
                slowPrint("��֤ͨ������ʼ����ͳ��ģ��...\n",BLUE);
                Stage=13;
                return;
            }
        }
        Sleep(1000);
    }
}
void step9() {
	yousyaColor=BLUE;
	enemyColor=RED;
    system("cls");
    slowPrint("������������ ħ������ ����������������������������������������������������������\n");
    slowPrint("����̤����ɫ������˲�䣬�����ӵ������𣬲��������֫��\n");
    slowPrint("X-0ϵͳ����ʼ����ħ��Ȩ����֤...\n", DARKGRAY);
    Sleep(1500);

    // ������ʽ
    slowPrint("�������ͷų����۵����⣬������忪ʼ�����仯��\n");
    slowPrint("X-0ϵͳ����⵽����Ũ�ȣ�");
    slowPrint(to_string(countKill).c_str(), countKill > 200 ? RED : YELLOW);
    slowPrint("������ħ����׼��\n");
    Sleep(1000);

    slowPrint("������������ױ��Σ�����һ�����ƺ�ɫ�����Ȩ�ȣ�\n");
    slowPrint("X-0ϵͳ����ӭ����108��ħ����\n", BLUE);
    Sleep(1500);

    // ����Χ�˵ľ���
    slowPrint("��ͻȻ��������Χ����Ļ��˸����ʾ��һ֧�Ӵ�ľ��ӣ�\n");
    slowPrint("X-0ϵͳ�����棡��⵽�����������ڼ��ᡣ\n", RED);
    Sleep(1000);

    slowPrint("�������У�������Ӹ߾����ģ�������д�š��ַ�ħ������\n");
    slowPrint("X-0ϵͳ�������ѵ�֪��ļ��ᣬ���ǲ�������ħ���Ĵ��ڡ�\n");
    slowPrint("X-0ϵͳ��������һ��ħ���Ѿ������ܾã�ħ��ٷϴ��ˣ����������ɵı㹥���˴�\n");
    slowPrint("����"),slowPrint("ħ��",BLUE),slowPrint("���������󣬻��������������½��������\n");
    Sleep(1500);

    // ���վ�ս��ʾ
    slowPrint("������������ ���վ�ս ����������������������������������������������������������\n");
    slowPrint("���������ѵִ�ӰԨʥ����Χ��ս��������ʼ��\n");
    slowPrint("���Ŀ���ǻ�����������������ħ��Ȩ����\n", RED);
    Sleep(1000);

	slowPrint("ħ��",BLUE),slowPrint("���£������ˡ�\n");
	Sleep(1000);
	system("pause");

	system("cls");
	clearEnemies();cantStop=1;
	grid.init(31,31);ableC=1;ableF=1;
	player.init();
	player.setPos(16,16);
	grid.name="ӰԨʥ��";
	grid.generateEmpty();enemyLimit=18;
	grid.add(player);enemyEyesight=8;enemyStopTime=2;attackWaitTime=2;
	generateLimit=100;
	for(int i=0;i<9;++i)newEnemy(enemyEyesight);
	print(grid,player);lastMove=clock();
	clock_t st;
	st=clock();
	while(1){if(die)return;
		while(enemies.size()<6 and generateLimit>0)newEnemy(enemyEyesight);
		update();
		if(checkCrash())End(3);
		updateEnemy();
		if(checkCrash())End(3);
		print(grid,player);
		int stay=6-(clock()-lastMove)/CLOCKS_PER_SEC;
		cout<<"��ͣ�� "<<stay<<" ��ͻ��ܵ��˺�\n";
		cout<<"��ʣ "<<generateLimit<< "�����˼�������ս��\n";
		if(stay<=0){
			--player.hp;
			lastMove=clock();
			if(player.hp==0)End(3);
		}
		if(generateLimit+enemies.size()<=0)break;
		++standardClock;
		Sleep(100);
	}
	system("cls");system("cls");
	slowPrint("һ�ж������ˡ�\n");
	End(4);
}
void step10(){
    yousyaColor=RED;  // �����ɫ��Ϊ��ɫ��ԭ���෽��ɫ��
    enemyColor=BLUE;  // ħ����ɫ��Ϊ��ɫ
    int originalKills = countKill; // ����ԭʼ��ɱ��

    system("cls");
    slowPrint("������������ ����֮· ����������������������������������������������������������\n");
    slowPrint("����ת�������ɫ���ŵ�˲�䣬��������Ȼ����\n");
    slowPrint("X-0ϵͳ����⵽������Ϊ���������Э�飡\n", DARKGRAY);
    Sleep(1500);

    // ��������
    slowPrint("�������ʥ�ʼ��������ɫ������ӵص�ӿ����\n");
    slowPrint("X-0ϵͳ����⵽�����������");
    slowPrint(to_string(originalKills).c_str(), originalKills > 50 ? RED : YELLOW);
    slowPrint("��������ȼ�����߼�\n");
    Sleep(1000);

    slowPrint("���������ͻȻ��˸��⣬��������������̬��\n");
    slowPrint("X-0ϵͳ��������213�ţ�ϵͳ�����������������\n", BLUE);
    Sleep(1500);

    // ħ��׷ɱ����
    slowPrint("�������Ļ��ʾ������ɫħ�����ڼ��ᣩ\n");
    slowPrint("X-0ϵͳ�����ͷ�",BLUE);slowPrint("׷����ħ��",DARKGRAY);slowPrint("12��\n");
    slowPrint("���ǶԶ�������м������жȣ���������ƽ���\n", RED);
    Sleep(1000);

    // ����������ʾ
    slowPrint("������������ �������� ����������������������������������������������������������\n");
    slowPrint("������ֵ�����Ԯ���ִ���������׷���ߣ�\n");
    Sleep(1000);

    slowPrint("�Ǹ����������ܣ��������ˣ�\n");
    Sleep(1000);
    system("pause");

    // ս����ʼ��
    system("cls");
    clearEnemies();
    cantStop=1;
    grid.init(31,31);
    ableC=1;  // ���������ϰ�
    ableF=1;  // ��������
    player.init();
    player.setPos(16,16);
    grid.name="��ԭ����";
	grid.generateEmpty();enemyLimit=18;
	grid.add(player);enemyEyesight=8;enemyStopTime=2;attackWaitTime=2;
	generateLimit=100;
	for(int i=0;i<9;++i)newEnemy(enemyEyesight);
	print(grid,player);lastMove=clock();
	clock_t st;
	st=clock();
	while(1){if(die)return;
		while(enemies.size()<6 and generateLimit>0)newEnemy(enemyEyesight);
		update();
		if(checkCrash())End(5);
		updateEnemy();
		if(checkCrash())End(5);
		print(grid,player);
		int stay=6-(clock()-lastMove)/CLOCKS_PER_SEC;
		cout<<"��ͣ�� "<<stay<<" ��ͻ��ܵ��˺�\n";
		cout<<"��ʣ "<<generateLimit<< "�����˼�������ս��\n";
		if(stay<=0){
			--player.hp;
			lastMove=clock();
			if(player.hp==0)End(3);
		}
		if(generateLimit+enemies.size()<=0)break;
		++standardClock;
		Sleep(100);
	}

    system("cls");
    slowPrint(originalKills <= 200 ? "Ԯ����ʱ�ϵ��ˣ�\n" : "����ǿ�ӳ�����...\n");
    End(originalKills <= 200 ? 7 : 6); // ����ԭʼ��ɱ��ѡ����
}
void Play(){
	generateLimit=-1;
	int prevKill=countKill;
	step1();if(die==1)return;
	countKill=prevKill;touchPalace=0;
	prePlot();if(die==1)return;touchPalace=0;
	step2();if(die==1)return;touchPalace=0;
	step3();if(die==1)return;touchPalace=0;
	step4();if(die==1)return;touchPalace=0;
	step5();if(die==1)return;touchPalace=0;
	step6();if(die==1)return;touchPalace=0;
	step7();if(die==1)return;touchPalace=0;
	step8();saveFile();if(die==1)return;touchPalace=0;
	if(Stage==13)step9();
	else step10();
}
#endif
