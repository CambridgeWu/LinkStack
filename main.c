#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#include <conio.h>

LinkStack L;

int keyDown(int *type){
	printf("                 LinkStack              \n");
	printf("                1.��ʼ��ջ              \n");
	printf("                2.�ж�ջ�Ƿ�Ϊ��        \n");
	printf("                3.�õ�ջ��Ԫ��          \n");
	printf("                4.���ջ                \n");
	printf("                5.����ջ                \n");
	printf("                6.���ջ����            \n");
	printf("                7.��ջ                  \n");
	printf("                8.��ջ                  \n\n\n");
	
	char ch=getch();
	switch(ch){
		case '1':
			if(initLStack(&L)){
				printf("��ʼ���ɹ���");
			}else{
				printf("��ʼ��ʧ�ܣ�");
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
			printf("��������Ҫ�洢�����ݣ�\n");
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
			printf("�����������");
			break;
	}
}

int main(){
	int type=1;
	while(type){
		system("cls");
		keyDown(&type);
		printf("�������������...");
		getch();
	}
	return 0;
}
