#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#include <conio.h>

LinkStack L;

int keyDown(int *type){
	printf("                 LinkStack              \n");
	printf("                1.初始化栈              \n");
	printf("                2.判断栈是否为空        \n");
	printf("                3.得到栈顶元素          \n");
	printf("                4.清空栈                \n");
	printf("                5.销毁栈                \n");
	printf("                6.检测栈长度            \n");
	printf("                7.入栈                  \n");
	printf("                8.出栈                  \n\n\n");
	
	char ch=getch();
	switch(ch){
		case '1':
			if(initLStack(&L)){
				printf("初始化成功！");
			}else{
				printf("初始化失败！");
			}
			break;
		case '2':
			isEmptyLStack(&L);
			break;
		case '3':
			{
			ElemType e;
			getTopLStack(&L,&e);
			break;
			}
		case '4':
			clearLStack(&L);
			break;
		case '5':
			destroyLStack(&L);
			type=0;
			break;
		case '6':
			{
			int length;
			LStackLength(&L,&length);
			break;
			}
		case '7':
			{
			printf("请输入你要存储的数据：\n");
			int data;
			scanf("%d",&data);
			pushLStack(&L,data);
			break;
			}
		case '8':
			{
			int data;
			popLStack(&L,&data);
			break;
			}
		default:
			printf("你的输入有误！");
			break;
	}
}

int main(){
	int type=1;
	while(type){
		system("cls");
		keyDown(&type);
		printf("输入任意键继续...");
		getch();
	}
	return 0;
}
