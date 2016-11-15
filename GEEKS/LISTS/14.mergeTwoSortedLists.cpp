#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define size 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;
class List 
{       struct Node
        {       int data;
                Node *next;
        }*root;
        void delAll(Node *root)
        {       if(root==NULL)return;
                delAll(root->next);
                free(root);
                cout<<'*';
        }
        Node *getNode(int data)
        {       Node *t=(Node *)malloc(sizeof(Node));
                t->next=NULL;
                t->data=data;
                return t;
        }
        Node *insertAtBack(Node *t,int data)
        {       if(t == NULL)return getNode(data);
                t->next=insertAtBack(t->next,data);
                return t;
        }
        Node *insertAtFront(Node *t,int data)
        {       Node *s=getNode(data);
                s->next=t;
                return s;       
        }
        Node *delFromBack(Node *t)
        {       if(t->next==NULL){free(t);return NULL;}
                t->next=delFromBack(t->next);
                return t;
        }
        Node *delFromFront(Node *t)
        {       Node *s=t->next;
                free(t);
                return s;
        }
        void disp(Node *t)
        {       if(t==NULL)return;
                cout<<t->data<<' ';
                disp(t->next);
        }
        
        Node *MergeList(Node *A,Node *B)
        {       if(A==NULL)return B;
                if(B==NULL)return A;
                if(A->data < B->data)
                {       
                        A->next=MergeList(A->next,B);
                        return A;
                }
                else
                {       B->next=MergeList(A,B->next);
                        return B;
                }
        }
       public:
        List(){root=NULL;}
        ~List(){delAll(root);}
        void push_back(int key)
        {       root=insertAtBack(root,key);}
        void push_front(int key)
        {       root=insertAtFront(root,key);}
        void pop_back()
        {       if(root!=NULL)
                root=delFromBack(root);
        }
        void pop_front()
        {       if(root!=NULL)
                root=delFromFront(root);
        }
        void display(){disp(root);cout<<'\n';}
        void MergeList(List *L)
        {       L->MergeList(root);
                L->display();
        }
        void MergeList(Node *rt)
        {        root=MergeList(root,rt);        
        }
};


int main(int argc, char *argv[])
{       int A[]={1,2,3,7,12};
        int B[]={4,5,6,8,9,11,13};
        int n=sizeof(A)/sizeof(A[0]);
        List L,M;
        while(n--)L.push_front(A[n]);
        n=sizeof(B)/sizeof(B[0]);
        while(n--)M.push_front(B[n]);
        L.display();
        M.display();
        L.MergeList(&M);
        L.display();
        M.display();
        
        
        return 0;
}
