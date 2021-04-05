#include "LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

//��ջ
Status initLStack(LinkStack *s){
	s->top=(StackNode*)malloc(sizeof(StackNode));
	if(!(s->top))
	return ERROR;
	s->top->next=NULL;
	s->count=0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s){
	if(s->count==0){
		printf("ջΪ�գ�");
		return ERROR;
	}
	printf("ջ��Ϊ�գ�");
	return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top->next==NULL){
		printf("ջΪ�գ�");
		return ERROR;
	}
	*e=s->top->next->data;
	printf("ջ��Ԫ�ص�����Ϊ��%d",*e);
	return SUCCESS;
}

Status clearLStack(LinkStack *s){
	StackNode *p,*q;
	p=s->top;
	while(s->top->next){
		q=s->top->next;
		p->next=q->next;
		free(q);
		s->count--;
	}
	return SUCCESS;
}

Status destroyLStack(LinkStack *s){
	StackNode* q;
	while(s->top->next){
		q=s->top->next;
		s->top->next=q->next;
		free(q);
	}
	printf("���ٳɹ�");
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length){
	*length=s->count;
	printf("ջ�ĳ���Ϊ��%d",*length);
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data){
	StackNode* p=(StackNode*)malloc(sizeof(StackNode));
	p->data=data;
	p->next=s->top->next;
	s->top->next=p;	
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data){
	StackNode* p=s->top->next;
	*data=p->data;
	s->top->next=p->next;
	free(p);
	s->count--;
	printf("��ջ������Ϊ��%d",*data);
	return SUCCESS;
}




