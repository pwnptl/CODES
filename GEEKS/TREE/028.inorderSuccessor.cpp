#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

class Tree
{
        struct Node
        {       int data;
                Node *left,*right;
                Node *next;
        }*root;
        int size;
        
        Node *getNode(int data)
        {       Node *t=(Node *)malloc(sizeof(Node));
                t->left=t->right=t->next=NULL;
                t->data=data;
                return t;
        }
        void delAll(Node *t)
        {       if(t==NULL)return;
                delAll(t->left);
                delAll(t->right);
                free(t);
                t=NULL;
        }
        void preorder(Node *t)
        {       if(t==NULL)return;
                cout<<t->data<<' ';
                preorder(t->left);
                preorder(t->right);
        }
        void inorder(Node *t)
        {       if(t==NULL)return;
                inorder(t->left);
                cout<<t->data<<' ';
                inorder(t->right);
        }
        void postorder(Node *t)
        {       if(t==NULL)return;
                postorder(t->left);
                postorder(t->right);
                cout<<t->data<<' ';
        }
        Node *insert(Node *t,int data)
        {       if(t==NULL){++size;return getNode(data);}
                if(data < t->data) t->left = insert(t->left,data);
                else t->right = insert(t->right,data);
                return t;
        }
        Node *insert2(Node *t,int data,int s)
        {       if(t==NULL)
                {       ++size;
                        return getNode(data);
                }
                int l=1;
                while(l<=s)l=l<<1;
                l/=2;
                if(s<l*3/2)
                        t->left =insert2(t->left ,data,s-l/2);
                else    t->right=insert2(t->right,data,s-l);
                        
               return t;
        }
        
        Node *rem2(Node *rt,Node *root)
        {       if(rt->right!=NULL)
                                rt->right=rem2(rt->right,root);
                else
                {       root->data=rt->data;
                        Node *t=rt->left;
                        free(rt);
                        return t;
                }
                return rt;
        }
        Node *rem(Node *root,int key)
        {       if(root==NULL)return NULL;
                if(root->data==key)
                {       if(root->left==NULL)
                        {       Node *t=root->right;
                                free(root);
                                return t;
                        }
                        else
                                root->left=rem2(root->left,root);
                }
                else if(key < root->data)root->left=rem(root->left,key);
                else root->right=rem(root->right,key);
                return root;
        }
        int search(Node *root,int key)
        {       if(root==NULL)return 0;
                if     (key < root->data)return search(root->left,key);
                else if(key > root->data)return search(root->right,key);
                else return 1;
        }
        
        void inOrderSuccessor(Node *t)
        {
                static Node *next=NULL;
                if(t)
                {       inOrderSuccessor(t->right);
                        t->next = next;
                        next = t;
                        inOrderSuccessor(t->left);
                }
        }
        void disp(Node *t)
        {       if(t==NULL)return;
                cout<<t->data<<' ';
                disp(t->next);
        }
        
       public:
        Tree (){root=NULL;size=0;}
        ~Tree(){ delAll(root);}
        void preorder(){preorder(root);cout<<endl;}
        void inorder(){inorder(root);cout<<endl;}
        void postorder(){postorder(root);cout<<endl;}
        void insert (int data){root=insert (root,data       );}
        void insert2(int data){root=insert2(root,data,size+1);}
        void remove(int key){root=rem(root,key);}
        int  find(int key){ return search(root,key);}       

        void inOrderSuccessor()
        {inOrderSuccessor(root);}
        void disp(){Node *t=root;while(t->left)t=t->left;disp(t);}
};


int main(int argc, char *argv[])
{
        int A[]={1,2,3,4,5,6,7,9,0};
        int n  =sizeof(A)/sizeof(A[0]);
        Tree T;
        while(n--)
                T.insert2(A[n]);
        
        T.inorder();
        T.inOrderSuccessor();
        T.disp();        
                
        return 0;
}
