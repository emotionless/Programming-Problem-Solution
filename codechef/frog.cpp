#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

vector< pair< string, int > > V;

class Node
{
public:
    Node *left, *right;
    int weight, ch;
    Node() {}
    Node(int _w, int _c) : weight(_w), ch(_c)
    {
        left = right = NULL;
    }
    ~Node() {}
};

class comp
{
public:
    bool operator() (const Node &a, const Node &b)
    {
        return a.weight > b.weight;
    }
};

void generate(const Node *a, char *code, int depth)
{
    if(a->left == NULL && a->right == NULL)
    {
        code[depth] = 0;
        V.push_back(pair< string, int > (code, a->ch));
        return;
    }
    if(a->left != NULL)
    {
        code[depth] = '0';
        generate(a->left, code, depth + 1);
    }
    if(a->right != NULL)
    {
        code[depth] = '1';
        generate(a->right, code, depth + 1);
    }
}

int main()
{
    priority_queue< Node, vector< Node >, comp > Q;
    int ch, weight;
    char code[100];

    // read ascii and frequency
    while(cin >> ch >> weight)
    {
        Q.push(Node(weight, ch));
    }

    // build 2-tree
    while(Q.size() > 1)
    {
        Node *a = new Node;
        *a = Q.top();
        Q.pop();
        Node *b = new Node;
        *b = Q.top();
        Q.pop();
        Node c(a->weight + b->weight, 0);
        c.left = a, c.right = b;
        Q.push(c);
    }

    // traverse tree to generate code
    generate(&Q.top(), code, 0);

    // display character and code
    for(int i = 0; i < (int)V.size(); i++)
    {
        cout << V[i].first << " --> " << V[i].second << endl;
    }
    return 0;
}
