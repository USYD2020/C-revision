#include <stdio.h>
#include <stdlib.h>

struct node;

struct node{
    int data;
    struct node *next;
};

//create_node
struct node *create_node(int value);

//add_front
struct node *add_front(struct node *head, int value);

//add_end
//if head==NULL, then return a node with node.val==val, node.next==NULL;
struct node *add_end(struct node *head, int value);

// 在node.val==target的节点后面, 插入一个node, 并且`node.val=val`, 
// 如果`node.val==target`这个节点不存在, 那么 do nothing
void insert_after(struct node *head, int target, int value);

// 在node.val==target的节点前面, 插入一个node, 并且`node.val=val`, 
//  如果`node.val==target`这个节点不存在, 那么 do nothing
struct node *insert_before(struct node *head, int target, int value);

// 删除第一个具有 `val==target` 的节点.
struct node *delete_node(struct node* head,int target);

// 删除全部具有所有 val==target` 的节点
struct node *delete_nodes(struct node* head, int target);

//翻转链表
struct node *reverse_linkedlist(struct node* head);

void print_linkedlist(struct node *head);




