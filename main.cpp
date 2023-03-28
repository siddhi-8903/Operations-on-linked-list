#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        cout<<"Element: "<<ptr->data<<endl;
        ptr=ptr->next;
        
    }
}
struct node * insertat0(struct node *head,int data)
{
    struct node*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
};
struct node *insertatend(struct node *head,int data)
{
    struct node *p=head;
    struct node *ptr;
    ptr=(struct node *)malloc (sizeof(struct node));
    ptr->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
};
struct node *insertatindex(struct node *head,int data,int index)
{
    int i=0;
    struct node*ptr;
    struct node *p=head;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
    
}
int main()
{
    struct node *head=new(struct node);
    struct node *second=new(struct node);
    struct node *third=new(struct node);
    struct node *fourth=new(struct node);

    head->data=53;
    head->next=second;
    
    second->data=23;
    second->next=third;
    
    third->data=77;
    third->next=fourth;
    
    fourth->data=11;
    fourth->next=NULL;
    
    traversal(head);
    cout<<"Inserting at 0 index"<<endl;
    head=insertat0(head,34);
    traversal(head);
    cout<<"Inserting at end"<<endl;
    head=insertatend(head,90);
    traversal(head);
    cout<<"Inserting at index"<<endl;
    head=insertatindex(head,78,1);
    traversal(head);
}
