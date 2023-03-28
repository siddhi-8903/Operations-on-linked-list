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
struct node *deleteat0(struct node *head)
{
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct node *deleteatend(struct node* head)
{
    struct node *ptr=head;
    struct node *q=head->next;
    while(q->next!=NULL)
    {
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=NULL;
    free(q);
    return head;
}
struct node *deleteatindex(struct node *head,int index)
{
    struct node *p=head;
    struct node *q=head->next;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}
int main()
{
    struct node *head = new (struct node);
    struct node *second = new (struct node);
    struct node *third = new (struct node);
    struct node *fourth = new (struct node);
  
    head->data=53;
    head->next=second;
    
    second->data=23;
    second->next=third;
    
    third->data=77;
    third->next=fourth;
    
    fourth->data=11;
    fourth->next=NULL;
    
    traversal(head);
    cout<<"Deleting index node"<<endl;
    head=deleteat0(head);
    traversal(head);cout<<endl;
    head=deleteatend(head);
    traversal(head);cout<<endl;
    head=deleteatindex(head,1);
    traversal(head);
    
}