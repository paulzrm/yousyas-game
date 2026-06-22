#ifndef __end_cpp_
#define __end_cpp_
#include "includes.h"
void End(int endId){
	die=1;
	if(endId==0){
		slowPrint("那个声音：怎么，你连打木偶都能被木偶反杀？我真的找了个"),slowPrint("勇者",BLUE),slowPrint("吗？\n");
		Sleep(2000); 
		slowPrint("达成结局0：找错人了\n");
		haveEnd[0]=1;
		saveFile();
//		exit(0);
	}
	if(endId==1){
		slowPrint("那个声音：就这点智商，怎么能当上"),slowPrint("勇者",BLUE),slowPrint("？菜就多练吧。\n");
		haveEnd[1]=1;
		slowPrint("达成结局1：技不如人\n");
		saveFile();
//		exit(0);
	}
	if(endId==2){
		slowPrint("你被"),slowPrint("魔物",RED),slowPrint("击杀了。任务中道崩殂，这个世界依旧存活于水深火热之中。\n");
		Sleep(2000); 
		slowPrint("达成结局2：出师未捷身先死\n");
		haveEnd[2]=1;
		saveFile();
//		exit(0);
	}
	if(endId==3){
		haveEnd[3]=1;
		saveFile();
//		exit(0);
	}
	if(endId==4){
		haveEnd[4]=1;
		saveFile();
//		exit(0);
	}
	if(endId==5){
		haveEnd[5]=1;
		saveFile();
//		exit(0);
	}
	if(endId==6){
		haveEnd[6]=1;
		saveFile();
//		exit(0);
	}
	if(endId==7){
		haveEnd[7]=1;
		saveFile();
//		exit(0);
	}
	system("pause");
}
void viewEndings(){
	if(haveEnd[0])slowPrint("达成结局0：找错人了\n");
	else slowPrint("████████████████\n");
	if(haveEnd[1])slowPrint("达成结局1：技不如人\n");
	else slowPrint("████████████████\n");
	if(haveEnd[2])slowPrint("达成结局2：出师未捷身先死\n");
	else slowPrint("████████████████\n");
	if(haveEnd[3]);
	else slowPrint("████████████████\n");
	if(haveEnd[4]);
	else slowPrint("████████████████\n");
	if(haveEnd[5]);
	else slowPrint("████████████████\n");
	if(haveEnd[6]);
	else slowPrint("████████████████\n");
	if(haveEnd[7]);
	else slowPrint("████████████████\n");
	system("pause");
}
#endif
