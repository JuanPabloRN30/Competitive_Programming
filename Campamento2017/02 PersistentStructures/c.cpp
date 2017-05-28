#include <bits/stdc++.h>

using namespace std;

#define INF 1e8

int tam;

struct Node
{
    Node *left , *right;
    int value;

    Node()
    {
        left = right = NULL;
    }

    Node(Node* &other)
    {
        this->left = other->left;
        this->right = other->right;
    }

};

struct stp
{
    Node *root;

    stp()
    {
        root = NULL;
    }

    stp(Node *other)
    {
        this->root = other;
    }

    Node *build(vector < int > &arr , int low = 0 , int high = tam - 1)
    {
        Node *n = new Node;
        if(low == high)
        {
            n->value = arr[low];
            return n;
        }
        int mid = (low + high) >> 1;
        n->left = build(arr , low , mid);
        n->right = build(arr , 1 + mid , high);
        n->value = max(n->left->value , n->right->value);
        return n;
    }

    stp(vector < int > &arr)
    {
        this->root = build(arr);
    }

    int query(Node *voy , int &qlow , int &qhigh , int low = 0 , int high = tam - 1)
    {
        if(qhigh < low || qlow > high)
            return -INF;
        if(low >= qlow && high <= qhigh)
            return voy->value;
        int mid = (low + high) >> 1;
        return max(query(voy->left , qlow , qhigh , low , mid) , query(voy->right , qlow , qhigh , 1 + mid , high));
    }

    int query(int i , int j)
    {
        return query(this->root , i , j);
    }

    bool in(int &pos , int low , int high)
    {
        return pos >= low && pos <= high;
    }

    Node* update(Node *voy , int &pos , int &val , int low = 0 , int high = tam - 1)
    {
        int mid = (low + high) >> 1;
        Node *n = new Node(voy);
        if(low == high)
        {
            n->value = val;
            return n;
        }
        if(in(pos , low , mid))
            n->left = update(voy->left , pos , val , low , mid);
        else
            n->right = update(voy->right , pos , val , 1 + mid , high);
        n->value = max(n->left->value , n->right->value);
        return n;
    }
    Node* update(int &pos , int &val)
    {
        return update(this->root , pos , val);
    }

};

#define MAX 100010

int main()
{
    int n,q,a,b,c,actual = 0;
    char op[100];
    scanf("%d" , &n);
    vector < int > arr(n);
    stp sts[MAX];
    tam = n;
    for(int i = 0 ; i < n ; ++i)
        scanf("%d" , &arr[i]);
    sts[0] = stp(arr);
    scanf("%d" , &q);
    while(q--)
    {
        scanf("%s" , op);
        if(op[0] == 'c')
        {
            scanf("%d %d %d" , &a , &b , &c);
            sts[++actual] = stp(sts[a - 1].update(--b , c));
        }
        else
        {
            scanf("%d %d" , &a , &b);
            --b;
            printf("%d\n" , sts[a - 1].query(b , b));
        }
    }
    return 0;
}
