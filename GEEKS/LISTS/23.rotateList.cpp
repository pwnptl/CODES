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
                cout<<'.';
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
        Node *splitInHalf(Node *root)
        {       if(root==NULL||root->next==NULL)return NULL;
                Node *t=root,*s=root;
                if(root->next->next==NULL)
                {       t=root->next;
                        root->next=NULL;
                        return t;       
                }
                while(t!=NULL)
                {       t=t->next;
                        if(t==NULL)break;
                        t=t->next;
                        s=s->next;
                }
                t=s->next;
                s->next=NULL;
                return t;
        }
        Node *Merge(Node *A,Node *B)
        {       if(A==NULL)return B;
                if(B==NULL)return A;
                Node *t;
                if(A->data<B->data)
                {       t=A;
                        t->next=Merge(A->next,B);
                }
                else
                {       t=B;
                        t->next=Merge(A,B->next);
                }
                return t;
        }
        Node *MergeSort(Node *rt)
        {       if(rt==NULL||rt->next==NULL)return rt;
                Node *t=splitInHalf(rt);
                t=MergeSort(t);
                rt=MergeSort(rt);
                rt=Merge(rt,t);
                return rt;
        }
        Node * reverse(Node *root)
        {       Node *x=root,*y,*z;
                if(x==NULL)return NULL;
                y=x->next;
                x->next=NULL;
                if(y==NULL)return x;
                while(y!=NULL)
                {       z=y->next;
                        y->next=x;
                        x=y;
                        y=z;
                }
                root=x;
                return root;
        }       
        Node *rotate(Node *root,int k)
        {       if(root==NULL)return NULL;
                Node *t1,*t2,*t3;
                t1=t2=root;
                while(--k&&t2!=NULL)
                       t2=t2->next;
                if(t2==NULL)return root;
                
                t3=t2->next;
                if(t3==NULL)return root;
                while(t3->next!=NULL)
                       t3=t3->next;
                cout<<t2->data<<' '<<t3->data<<endl;
                t3->next=t1;
                root=t2->next;
                t2->next=NULL;
                return root;
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
 /**/       void MergeSort()
        {       root=MergeSort(root);   }        
 /**/
        void rotate(int k)
        {       root=rotate(root,k);    }

};

int main(int argc, char *argv[])
{       int A[]={1,2,3,4,5,6,7,8,99,3};
        int n=sizeof(A)/sizeof(A[0]);
        List L;
        while(n--)L.push_front(A[n]);
        L.display();
        L.rotate(4);
        L.display();
        
        

        return 0;
}
