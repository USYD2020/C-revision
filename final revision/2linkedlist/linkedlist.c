#include "linkedlist.h"

//create_node
struct node *create_node(int value)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

//add_front, return newnode
struct node *add_front(struct node *head, int value)
{
    struct node *newnode = create_node(value);
    newnode->next = head;
    return newnode;
}

//add_end, return head
struct node *add_end(struct node *head, int value)
{
    struct node *newnode = create_node(value);
    //if head==NULL
    if(head == NULL)
        return newnode;
    
    else{
        struct node *cur = head;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newnode;
    }
    return head;
}

// 在node.val==target的节点后面, 插入一个node, 并且`node.val=val`, 
// 如果`node.val==target`这个节点不存在, 那么 do nothing
void insert_after(struct node *head, int target, int value)
{
    struct node *cur = head;
    while(cur != NULL && cur->data != target)
    {
        cur = cur->next;
    }
    //如果没有找到
    if(cur == NULL){
        // do nothing
    }else{
        //如果找到了就创建一个新node
        struct node *newnode = create_node(value);
        newnode->next = cur->next;
        cur->next = newnode;
    }
}

// 在node.val==target的节点前面, 插入一个node, 并且`node.val=val`, 
//  如果`node.val==target`这个节点不存在, 那么 do nothing
struct node *insert_before(struct node *head, int target, int value)
{
    //NULL
    if(head == NULL)
        return NULL;
    //如果head的value和target相等
    else if(head->data == target){
        //return 重复add_front
        return add_front(head,value);
    }else{
        struct node *cur = head;
        //一直循环找到等于target的值；找cur的下一个
        while(cur != NULL && cur->next != NULL && cur->next->data != target)
        {
            cur = cur->next;
        }
        //找到了cur下一个node；插入前面
        if(cur != NULL && cur->next != NULL && cur->next->data == target)
        {
            struct node *newnode = create_node(value);
            newnode->next = cur->next;
            cur->next = newnode;
        }
        return head;
    }
}

// 删除第一个具有 `val==target` 的节点.delete only one node
struct node *delete_node(struct node* head, int target)
{
    //第一个值head == target
    if(head->data == target){
        //创建新node加入head后面
        struct node *newnode = head->next;
        free(head);
        return newnode;
    }
    else{
        struct node *cur = head;
        while(cur != NULL && cur->next != NULL && cur->next->data != target){
            cur = cur->next;
        }
        if(cur != NULL && cur->next != NULL && cur->next->data == target)
        {
            struct node *temp = cur->next;
            cur->next = temp->next;
            free(temp);
        }
        return head;
    }
}

// 删除全部具有所有 val==target` 的节点 delete all node->value == target
struct node *delete_nodes(struct node* head, int target);

//翻转链表
struct node *reverse_linkedlist(struct node* head);

//free
void free_linkedlist(struct node *head)
{
    if(head != NULL){
        struct node *cur = head;
        while(cur != NULL)
        {
            struct node *temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
}

// print all nodes
void print_linkedlist(struct node *head)
{
    struct node *cur = head; 
    printf("output: ");
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main(int argc, char **argv){

    //head
    struct node *head = create_node(-1);
    int count = 5;
    for(int i = 0; i < count; i++)
    {
        head = add_end(head,i);
    }
    //add_front
    head = add_front(head, 666);
    printf("测试1: add_front\n");
    printf("hhhope: 666 -1 0 1 2 3 4\n");
    print_linkedlist(head);
    //add_end
    head = add_end(head,10);
    printf("测试2: add_end\n");
    printf("hhhope: 666 -1 0 1 2 3 4 10\n");
    print_linkedlist(head);
    //insert_after
    head = insert_before(head,10,5);
    printf("测试3: insert_before\n");
    printf("hhhope: 666 -1 0 1 2 3 4 5 10\n");
    print_linkedlist(head);
    //insert_after
    insert_after(head,10,12);
    printf("测试4: insert_after\n");
    printf("hhhope: 666 -1 0 1 2 3 4 5 10 12\n");
    print_linkedlist(head);
    //delete_node
    head = delete_node(head,10);
    printf("测试5: delete_node\n");
    printf("hhhope: 666 -1 0 1 2 3 4 5 12\n");
    print_linkedlist(head);
    //delete_node
    head = delete_node(head,666);
    printf("测试6: delete_node\n");
    printf("hhhope: -1 0 1 2 3 4 5 12\n");
    print_linkedlist(head);
    //free_linkedlist
    free_linkedlist(head);
    printf("测试7: free_linkedlist\n");
    printf("hhhope:\n");
    // print_linkedlist(head);
    return 0;
}
