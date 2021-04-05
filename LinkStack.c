#include "LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

//链栈
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
		printf("栈为空！");
		return ERROR;
	}
	printf("栈不为空！");
	return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top->next==NULL){
		printf("栈为空！");
		return ERROR;
	}
	*e=s->top->next->data;
	printf("栈顶元素的数据为：%d",*e);
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
	printf("销毁成功");
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length){
	*length=s->count;
	printf("栈的长度为：%d",*length);
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
	printf("该栈的数据为：%d",*data);
	return SUCCESS;
}




