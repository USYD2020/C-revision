#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


// --------type/function header-----------------

struct node;

struct node {
    int val;
    struct node* next;
};
typedef struct node node_t;

void print_linkedlist(struct node *head);

struct node *create_node(int val);

struct node *add_to_front(struct node *head, int val);

// add a node to the end of the linkedlist. 
//  if head==NULL, then return a node with node.val==val, node.next==NULL;
struct node *add_to_end(struct node *head, int val);

// 在node.val==target的节点后面, 插入一个node, 并且`node.val=val`, 
//  如果`node.val==target`这个节点不存在, 那么 do nothing
void insert_after(struct node *head, int target, int val);

// 在node.val==target的节点前面, 插入一个node, 并且`node.val=val`, 
//  如果`node.val==target`这个节点不存在, 那么 do nothing
struct node* insert_before(struct node *head, int target, int val);

// 删除第一个具有 `val==target` 的节点.
struct node* delete_node(struct node* head, int target);

// 删除全部具有所有 val==target` 的节点
struct node* delete_nodes(struct node* head, int target);

//翻转链表
struct node* reverse_linkedlist(struct node* head);


void print_linkedlist(struct node *head)
{
    struct node *cur = head;

    printf("output: ");
    while (cur != NULL)
    {
        printf("[%d]->", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}

// -------------我们的代码写在这里-----------------------





// def __init__(self);
// class Node {
//     Node() {

//     }
// }
struct node *create_node(int val) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}


struct node *add_to_end(struct node *head, int val) {
    node_t* new_node = create_node(val);
    if (head == NULL) {
        return new_node;
    } else {
        node_t* cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
        return head;
    }
}


struct node *add_to_front(struct node *head, int val) {
    node_t* new_head = create_node(val);
    new_head->next = head;
    return new_head;
}

// 等价形式 (需要理解, 但是不推荐这么写)
void add_to_front2(struct node **head, int val) {
    node_t* new_head = create_node(val);
    new_head->next = *head;
    *head = new_head;
}


// 在node.val==target的节点后面, 插入一个node, 并且`node.val=val`, 
//  如果`node.val==target`这个节点不存在, 那么 do nothing
void insert_after(struct node *head, int target, int val) {
    node_t* cur = head;
    while (cur != NULL && cur->val != target) {
        cur = cur->next;
    }
    if (cur == NULL) {
        // do nothing
    } else {
        node_t* new_node = create_node(val);

        // sol-1:
        // node_t* temp_next = cur->next;
        // cur->next = new_node;
        // new_node->next = temp_next;

        // sol-2
        new_node->next = cur->next;
        cur->next = new_node;
    }

}



// 删除第一个具有 `val==target` 的节点.
struct node* delete_node(struct node* head, int target) {
    if (head->val == target) {
        node_t* new_head = head->next;
        free(head);
        return new_head;
    } else {
        node_t* cur = head;
        while (cur != NULL && \
            cur->next != NULL && \
            cur->next->val != target) {
            cur = cur->next;
        }
        if (cur!=NULL && \
           cur->next != NULL && \
           cur->next->val == target) {
            node_t* node_to_delete = cur->next;
            cur->next = node_to_delete->next;
            free(node_to_delete);
        }
        return head;
    }
}



// 在node.val==target的节点前面, 插入一个node, 并且`node.val=val`, 
//  如果`node.val==target`这个节点不存在, 那么 do nothing
struct node* insert_before(struct node *head, int target, int val) {
    if (head == NULL) {
        return NULL;
    } else if (head->val == target) {
        return add_to_front(head, val);
    } else {
        node_t* cur = head;
        while (cur != NULL && \
            cur->next != NULL && \
            cur->next->val != target) {
            cur = cur->next;
        }
        if (cur!=NULL && \
           cur->next != NULL && \
           cur->next->val == target) {
               node_t* new_node = create_node(val);

               new_node->next = cur->next;
               cur->next = new_node;
        }
        return head;
    }
}

void free_linkedlist(node_t* head) {
    if (head != NULL) {
        node_t* cur = head;
        while(cur!=NULL) {
            node_t* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
}

// -------------下面是test函数区----------------------

int main(int argc, char *argv[])
{
    printf("\n# ⚔️  LinkedList Dojo 🤺 \n");

    struct node *head = create_node(-1);

    printf("\n## 0. test add_to_end\n");
    printf("test add_to_end\n");
    int count = 5;
    for (size_t i = 0; i < count; i++)
    {
        head = add_to_end(head, i);
    }
    print_linkedlist(head);
    printf("expect: [-1]->[0]->[1]->[2]->[3]->[4]->NULL\n");

    printf("\n## 1. test add_to_front: 前面插入666\n");
    printf("input:  [-1]->[0]->[1]->[2]->[3]->[4]->NULL\n");
    head = add_to_front(head, 666);
    printf("expect: [666]->[-1]->[0]->[1]->[2]->[3]->[4]->NULL\n");
    print_linkedlist(head);

    printf("\n## 2. test insert_after\n");

    printf("2.1 test 在中间插入: 3后面插入555\n");
    printf("input:  [666]->[-1]->[0]->[1]->[2]->[3]->[4]->NULL\n");
    insert_after(head, 3, 555);
    print_linkedlist(head);
    printf("expect: [666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->NULL\n");

    printf("2.2 test 在队尾插入: 4后面插入999\n");
    printf("input:  [666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->NULL\n");
    insert_after(head, 4, 999);
    print_linkedlist(head);
    printf("expect: [666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->[999]->NULL\n");

    printf("2.3 test 如果target不存在: target=888(不存在)后面插入777\n");
    printf("input:  [666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->[999]->NULL\n");
    insert_after(head, 888, 777);
    print_linkedlist(head);
    printf("expect: [666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->[999]->NULL\n");

    printf("\n## 3. test insert_before\n");

    printf("3.1 test insert_before, test 在第一个前面插入: 666前面插入123\n");
    printf("input:  [666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->[999]->NULL\n");
    head = insert_before(head, 666, 123);
    print_linkedlist(head);
    printf("expect: [123]->[666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->[999]->NULL\n");

    printf("3.2 test insert_before, test 在第中间插入: 2前面插入234\n");
    printf("input:  [123]->[666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->[999]->NULL\n");
    head = insert_before(head, 2, 234);
    print_linkedlist(head);
    printf("expect: [123]->[666]->[-1]->[0]->[1]->[234]->[2]->[3]->[555]->[4]->[999]->NULL\n");

    printf("3.3 test insert_before, test 如果target不存在: 222前面插入678\n");
    printf("input:  [123]->[666]->[-1]->[0]->[1]->[234]->[2]->[3]->[555]->[4]->[999]->NULL\n");
    head = insert_before(head, 222, 678);
    print_linkedlist(head);
    printf("expect: [123]->[666]->[-1]->[0]->[1]->[234]->[2]->[3]->[555]->[4]->[999]->NULL\n");


    // printf("3.4 test insert_before, test 在队尾插入: 999前面插入567\n");
    // printf("input:  [123]->[666]->[-1]->[0]->[1]->[234]->[2]->[3]->[555]->[4]->[999]->NULL\n");
    // head = insert_before(head, 999, 567);
    // print_linkedlist(head);
    // printf("expect: [123]->[666]->[-1]->[0]->[1]->[234]->[2]->[3]->[555]->[4]->[567]->[999]->NULL\n");

    printf("\n## 4. test delete_node\n");

    printf("4.1 test 删除第一个节点, aka 123\n");
    printf("input:  [123]->[666]->[-1]->[0]->[1]->[234]->[2]->[3]->[555]->[4]->[999]->NULL\n");
    head = delete_node(head, 123);
    print_linkedlist(head);
    printf("expect: [666]->[-1]->[0]->[1]->[234]->[2]->[3]->[555]->[4]->[999]->NULL\n");

    printf("4.2 test 删除中间一个节点, i.e. 234\n");
    printf("input:  [666]->[-1]->[0]->[1]->[234]->[2]->[3]->[555]->[4]->[999]->NULL\n");
    head = delete_node(head, 234);
    print_linkedlist(head);
    printf("expect: [666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->[999]->NULL\n");

    printf("4.3 test 删除最后一个节点, aka 999\n");
    printf("input:  [666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->[999]->NULL\n");
    head = delete_node(head, 999);
    print_linkedlist(head);
    printf("expect: [666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->NULL\n");

    printf("4.4 test 删除一个不存在的节点, e.g. 876\n");
    printf("input:  [666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->NULL\n");
    head = delete_node(head, 876);
    print_linkedlist(head);
    printf("expect: [666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->NULL\n");

    // printf("\n## 5. test 翻转链表\n");
    // printf("input:  [666]->[-1]->[0]->[1]->[2]->[3]->[555]->[4]->NULL\n");
    // head = reverse_linkedlist(head);
    // printf("expect: [4]->[555]->[3]->[2]->[1]->[0]->[-1]->[666]->NULL\n");
    // print_linkedlist(head);


    // printf("\n## 6. test free linkedlist\n");
    printf("\n## 6. test free_linkedlist\n");
    free_linkedlist(head);
    printf("DONE!\n");

    return 0;
}

