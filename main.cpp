#include "includes.cpp"
using namespace std;

void configureConsole(){
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	HANDLE output=GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode=0;
	if(output!=INVALID_HANDLE_VALUE && GetConsoleMode(output,&mode)){
		SetConsoleMode(output,mode|ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	}
}

int main(){
	configureConsole();
	srand(time(NULL));
	player.init();
	while(1){
		if(die){
			system("cls");
			step0();
			die=0;
		}
		bgn:;
		static const string clear_screen="\033[H";
		cout<<clear_screen;
		step0();
		slowPrint("\n      C 继续游戏\n");
		slowPrint("\n\n      L 读取存档\n");
		slowPrint("\n\n      N 新游戏\n");
		slowPrint("\n\n      V 查看已解锁结局\n");
		slowPrint("\n\n      E 退出游戏\n");
		while(1){
			if(GetAsyncKeyState(VK_L)){
				loadFile();
				Play();
			}
			if(GetAsyncKeyState(VK_C)){
				readFile();
				Play();
			}
			if(GetAsyncKeyState(VK_N)){
				newFile();
				Play();
			}
			if(GetAsyncKeyState(VK_V)){
				loadFile();
				viewEndings();
				system("cls");
				goto bgn;
			}
			if(GetAsyncKeyState(VK_E)){
//				saveFile();
				exit(0);
			}
			if(die)break;
		}
	}
//	grid.init();
//	player.init();
//	grid.generate();
//	player.setPos(64,64);
//	grid.add(player);
//	for(int i=0;i<128;++i)newEnemy(15);
//	while(1){
//		update();
//		if(checkCrash())End(1);
//		updateEnemy();
//		if(checkCrash())End(1);
//		print(grid,player);
//		++standardClock;
//		Sleep(100);
//	}
}
