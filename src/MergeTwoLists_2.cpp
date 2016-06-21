/*********************************
*   日期：2013-11-23
*   作者：SJF0115
*   题号: 题目1519：合并两个排序的链表
*   来源：http://ac.jobdu.com/problem.php?pid=1519
*   结果：AC
*   来源：剑指Offer
*   总结：
**********************************/
#include<iostream>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
using namespace std;

typedef struct ListNode{
    int value;
    struct ListNode* next;
}ListNode;

//打印链表
void OutPut(ListNode*head){
    if(head == NULL){
        printf("NULL\n");
    }
    else{
        ListNode *p;
        p = head->next;
        while(p != NULL){
            //如果是最一个
            if(p->next == NULL){
                printf("%d\n",p->value);
            }
            else{
                printf("%d ",p->value);
            }
            p = p->next;
        }
    }
}


//创建链表
ListNode* CreateList(ListNode *head,int n){
    ListNode *newNode,*p;
    p = head;
    for(int i = 0;i < n;i++){
        newNode = (ListNode*)malloc(sizeof(ListNode));
        scanf("%d",&newNode->value);
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
    }
    return head;
}


ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1->next == NULL && pHead2->next == NULL) {
        return NULL;
    }
    else if (pHead1->next == NULL) {
        return pHead2;
    }
    else if (pHead2->next == NULL) {
        return pHead1;
    }
    else {	// 合并
        ListNode *p1, *p2, *p3, *head;
        head = (ListNode*)malloc(sizeof(ListNode));
        head->next = NULL;  // 创建一个空链表
        p1 = pHead1->next;	// 第一个节点
        p2 = pHead2->next;	// 第一个节点
        p3 = head;			// 头结点（先于第一个节点）

        while (p1 != NULL && p2 != NULL) {
            if (p1->value < p2->value) {
                p3->next = p1;
                p1 = p1->next;
            } else {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }

        // pHead1没有遍历完
        while (p1 != NULL) {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }

        // pHead2没有遍历完
        while (p2 != NULL) {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
        return head;
    }

}


int main() {
    int i,n,m;
    while(scanf("%d %d",&n,&m) != EOF){
        ListNode *head1,*head2;
        head1 = (ListNode*)malloc(sizeof(ListNode));
        head2 = (ListNode*)malloc(sizeof(ListNode));
        head1->next = NULL;
        head2->next = NULL;
        //创建链表
        if(n != 0){
            head1 = CreateList(head1,n);
        }
        if(m != 0){
            head2 = CreateList(head2,m);
        }
        //合并排序
        head1 = Merge(head1,head2);
        //打印链表
        if(head1 == NULL){
            printf("NULL\n");
        }
        else{
            OutPut(head1);
        }
    }//while
    return 0;
}
