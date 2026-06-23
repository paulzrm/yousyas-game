#ifndef __end_cpp_
#define __end_cpp_
#include "includes.h"
void End(int endId){
//	print(grid,player);
	die=1;
	if(endId==0){
		slowPrint("�Ǹ���������ô��������ľż���ܱ�ľż��ɱ����������˸�"),slowPrint("����",BLUE),slowPrint("��\n");
		Sleep(2000);
		slowPrint("��ɽ��0���Ҵ�����\n");
		haveEnd[0]=1;
		saveFile();
//		exit(0);
	}
	if(endId==1){
		slowPrint("�Ǹ���������������̣���ô�ܵ���"),slowPrint("����",BLUE),slowPrint("���˾Ͷ����ɡ�\n");
		haveEnd[1]=1;
		slowPrint("��ɽ��1����������\n");
		saveFile();
//		exit(0);
	}
	if(endId==2){
		slowPrint("�㱻"),slowPrint("ħ��",RED),slowPrint("��ɱ�ˡ������е����㣬����������ɴ����ˮ�����֮�С�\n");
		Sleep(2000);
		slowPrint("��ɽ��2����ʦδ��������\n");
		haveEnd[2]=1;
		saveFile();
//		exit(0);
	}
	if (endId == 3) {
	    slowPrint("���㱻���������������Χ��Ȩ�ȴ����л��䣩\n");
	    slowPrint("�������䣺�������ν��ħ���������Ǹ����������ɵĿ�������ˡ�\n");
	    Sleep(1500);

	    slowPrint("���㵹�ڵ��ϣ���������X-0ϵͳ�������ʾ��\n");
	    slowPrint("X-0ϵͳ����108��ħ�������ڣ�3�졣\n", DARKGRAY);
	    slowPrint("ϵͳ�������Իٳ����������ݽ���10������...\n", RED);
	    Sleep(1000);

	    slowPrint("��������۾������ߴ�������Ļ�������\n");
	    slowPrint("�������䣺ħ������������ʤ���ˣ�\n");
	    Sleep(2000);

	    slowPrint("��ɽ��3��ħ������\n");
	    slowPrint(" - ���ͳ����꼻�һ�֣������ٴ�֤�������ǵ���ǿ��\n");
	    slowPrint(" - ����������Ӳ�δ��ʧ���µ�ħ���ս�����...\n", DARKGRAY);

	    haveEnd[3] = 1;
	    saveFile();
	}

	if (endId == 4) {
	    slowPrint("���������������ĵ��£����ĵֿ��߱�ħ�����ɣ�\n");
	    slowPrint("X-0ϵͳ����⵽�о�ȫ�����ܣ�ħ��Ȩ�����ȹ̡�\n", BLUE);
	    Sleep(2000);

	    slowPrint("����վ�����������ʬ���ԣ�Ȩ���ϵĺ�ɫ��������ȼ�գ�\n");
	    slowPrint("X-0ϵͳ����ϲ����108��ħ��������֤�����Լ��ļ�ֵ��\n", GREEN);
	    Sleep(1500);

	    slowPrint("����Ӷ�Ȩ�ȣ�ħ�������������������\n");
	    slowPrint("X-0ϵͳ���Ĵ��½�ѳ�������Ľ��£��������Ǹ���������;...\n", BLUE);
	    Sleep(1000);

	    slowPrint("��������Զ������Ǹ��ֳ�һ˿��Ц��\n");
	    slowPrint("�㣺��ֻ��һ����ʼ��\n");
	    Sleep(2000);

	    slowPrint("��ɽ��4��ħ������\n");
	    slowPrint(" - ��������ͳ�������磬������ħ��Գ��������Ȩ����\n");
	    slowPrint(" - ��Ȩ�����۷����ǹ¶��Ŀ�ʼ...\n", DARKGRAY);

	    haveEnd[4] = 1;

	    Stage=5;skipPlot=0;countKill=0;player.money=0;

	    saveFile();
	}

	if (endId == 5) {
	    slowPrint("������ͼ����ӰԨʥ������ħ������׷���ᣩ\n");
	    slowPrint("X-0ϵͳ�����棡��⵽��Ũ�ȶ��ⷴӦ��ħ�����������λ�á�\n", RED);
	    Sleep(2000);

	    slowPrint("���㱻ħ���Χ�����е������Ѷ��ѣ�\n");
	    slowPrint("ħ���ͽ...�������...\n", DARKGRAY);
	    Sleep(1500);

	    slowPrint("���㵹��Ѫ���У���������X-0ϵͳ�������ʾ��\n");
	    slowPrint("X-0ϵͳ����ѡ��213�ţ���ʧȥ����������\n");
	    slowPrint("ϵͳ��������������������ݽ���10�������...\n", RED);
	    Sleep(1000);

	    slowPrint("�������ʶ��ģ�������Ļ�����ħ����������ף�\n");
	    slowPrint("ħ�����Ǳ��ѵĴ���...\n", DARKGRAY);
	    Sleep(2000);

	    slowPrint("��ɽ��5�������ߵ�ĩ·\n");
	    slowPrint(" - ����ͼ�ع����࣬��ħ�ﲻ��Ź���ͽ��\n");
	    slowPrint(" - ��ħ��������֮�䣬��ѡ���˵�����·��ȴ���˽��ɡ�\n", DARKGRAY);

	    haveEnd[5] = 1;
	    saveFile();
	}

	if (endId == 6) {
	    slowPrint("�������ڻص��������磬��ӭ����Ĳ��ǻ��������Ǳ����ǹ�ڣ�\n");
	    slowPrint("�������䣺վס�������˫��մ����Ѫ�Ĺ��\n");
	    Sleep(2000);

	    slowPrint("������ͼ���ͣ�������Ը��������\n");
	    slowPrint("����ʿ�������ǿ�������ġ�ս��������ɱ�˶���ͬ����\n", RED);
	    Sleep(1500);

	    slowPrint("���㱻Ѻ������̨�������ǡ����������\n");
	    slowPrint("���й٣����Ѳ��������࣬����ħ���ĺ�ѡ�ߡ�\n", DARKGRAY);
	    Sleep(1000);

	    slowPrint("���㱻�д����̣��̳��������˴��꣩\n");
	    slowPrint("�㣺��ֻ��...��ؼ�...\n");
	    Sleep(2000);

	    slowPrint("��ɽ��6���޴��ɹ�\n");
	    slowPrint(" - ����ͼ�ع����࣬����Ĺ�ȥ�ѳɼ�����\n");
	    slowPrint(" - ���������У������Ѳ���ͬ�ࡣ\n", DARKGRAY);

		Sleep(5000);

		slowestPrint("���ԣ���ΪʲôҪ���������أ�\n",RED);
		slowPrint("�����¼��ܣ��� V ��������\n",RED);
		ableV=1;

	    haveEnd[6] = 1;

	    Stage=5;skipPlot=0;countKill=0;player.money=0;

	    saveFile();
	}
	if (endId == 7) {
	    slowPrint("�������ڻص��������磬ӭ������Ǹ��ӵ�Ŀ�⣩\n");
	    slowPrint("�������䣺������˵����Ĺ���...��ѡ���˻ع顣\n");
	    Sleep(2000);

	    slowPrint("�������ͷ���ȴ����У�\n");
	    slowPrint("�������䣺���������������޷���Ĩȥ��\n", DARKGRAY);
	    Sleep(1500);

	    slowPrint("����Ⱥ�д�������˽������գ�����������֣�\n");
	    slowPrint("�������䣺����Ը�����һ�����ᣬ��Ϊ��ѡ�������ԡ�\n", GREEN);
	    Sleep(1000);

	    slowPrint("����ӹ����������ߡ��Ļ��£���ˮģ�������ߣ�\n");
	    slowPrint("�㣺��...������ġ�\n");
	    Sleep(2000);

	    slowPrint("��ɽ��7������������\n");
	    slowPrint(" - ��ѡ���˻ع����࣬���ܴ��۳��ء�\n");
	    slowPrint(" - �����ճ�Ϊ�������ġ����ߡ����ػ��������δ����\n", GREEN);

	    haveEnd[7] = 1;

	    Stage=5;skipPlot=0;countKill=0;player.money=0;

	    saveFile();
	}

	system("pause");
}
void viewEndings(){
	if(haveEnd[0])slowPrint("��ɽ��0���Ҵ�����\n");
	else slowPrint("��������������������������������\n");
	if(haveEnd[1])slowPrint("��ɽ��1����������\n");
	else slowPrint("��������������������������������\n");
	if(haveEnd[2])slowPrint("��ɽ��2����ʦδ��������\n");
	else slowPrint("��������������������������������\n");
	if(haveEnd[3])slowPrint("��ɽ��3��ħ������\n");
	else slowPrint("��������������������������������\n");
	if(haveEnd[4])slowPrint("��ɽ��4��ħ������\n");
	else slowPrint("��������������������������������\n");
	if(haveEnd[5])slowPrint("��ɽ��5�������ߵ�ĩ·\n");
	else slowPrint("��������������������������������\n");
	if(haveEnd[6])slowPrint("��ɽ��6���޴��ɹ�\n");
	else slowPrint("��������������������������������\n");
	if(haveEnd[7])slowPrint("��ɽ��7������������\n");
	else slowPrint("��������������������������������\n");
	system("pause");
}
#endif
