/*************************************************************************
	> File Name: insert.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月27日 星期三 15时11分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
        int data;
        struct Node *next;

}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            return head;    
        }
            head = node;
            return head;   
    }
    if (index == 0) {
        node->next = head;
        head = node;
        return head;    
    }
        Node *current_node = head;
        int count = 0;
    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;    
    }
    if (count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;    
    } 
    else if(count < index - 1){
        return current_node->next;    
    }
        return head;
}

void output(LinkedList head) {
    if (head == NULL) {
        return;   
    }
        Node *current_node = head;
    while (current_node != NULL) {
            printf("%d", current_node->data);
            current_node = current_node->next;
        if (current_node) {
            printf(" ");    
        }    
    }
        printf("\n");

}

void clear(LinkedList head) {
        Node *current_node = head;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);    
    }

}

int main() {
        LinkedList linkedlist = NULL;
        int n, num, loc;
        Node *p, ret;
        scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &loc, &num);
        p = (Node *)malloc(sizeof(Node));
        p->data = num;
        p->next = NULL;
        if ((ret.next = insert(linkedlist, p, loc)) != NULL) {
            linkedlist = ret.next;
            printf("success\n");    
        } else {
            printf("failed\n");
            continue;    
        }
            
    }
        output(linkedlist);
        free(linkedlist);
        return 0;
}
