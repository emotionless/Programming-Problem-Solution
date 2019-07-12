#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define MAX 209
#define undef -2
#define empty -1
#define noEdge 0
#define unmatched 1
#define matched 2
#define Forward 0
#define Reverse 0

//Labels are the key to this implementation of the algorithm.
struct Label        //An even label in a vertex means there's an alternating path
{
    int even;    //of even length starting from the root node that ends on the
    int odd[2];  //vertex. To find this path, the backtrace() function is called,
};                  //constructing the path by following the content of the labels.
//Odd labels are similar, the only difference is that base nodes
//of blossoms inside other blossoms may have two. More on this later.


struct elem              //This is the element of the Queue of labels to be analyzed by
{
    int vertex,type;  //the augmentMatching() procedure. Each element contains the vertex
};                       //where the label is and its type, odd or even.


int g[MAX][MAX];         //The graph, as an adjacency matrix.

//blossom[i] contains the base node of the blossom the vertex i
int blossom[MAX];        //is in. This, together with labels eliminates the need to
//contract the graph.

//The path arrays are where the backtrace() routine will
int path[2][MAX],endPath[2];  //store the paths it finds. Only two paths need to be
//stored. endPath[p] denotes the end of path[p].

bool match[MAX];  //An array of flags. match[i] stores if vertex i is in the matching.

//label[i] contains the label assigned to vertex i. It may be undefined,
Label label[MAX]; //empty (meaning the node is a root) and a node might have even and odd
//labels at the same time, which is the case for nonbase nodes of blossoms

elem Queue[2*MAX];         //The Queue is necessary for efficiently scanning all labels.
int QueueFront,QueueBack;  //A label is enQueued when assigned and deQueued after scanned.

void initGraph(int n)
{
    for (int i=0; i<n; i++)
    {
        path[0][i] = path[1][i]= 0;
        for (int j=0; j<n; j++) g[i][j]=noEdge;
    }
}

int readGraph()
{
    int n,e,a,b, m;
    scanf("%d %d %d",&n, &m, &e);      //The graph is read and its edges are unmatched by default.
    n+=m;
    initGraph(n);               //Since C++ arrays are 0..n-1 and input 1..n , subtractions
    for (int i=0; i<e; i++)     //are made for better memory usage.
    {
        scanf("%d %d",&a,&b);
        if (a!=b)
            g[a-1][b-1]= g[b-1][a-1]=unmatched;
    }
    return n;
}

void initAlg(int n)              //Initializes all data structures for the augmentMatching()
{
    QueueFront=QueueBack=0;     //function begin. At the start, all labels are undefined,
    for (int i=0; i<n; i++)     //the Queue is empty and a node alone is its own blossom.
    {
        blossom[i]=i;
        label[i].even=label[i].odd[0]=label[i].odd[1]=undef;
    }
}

void backtrace (int vert, int pathNum, int stop, int parity, int direction)
{
    if (vert==stop) return;           //pathNum is the number of the path to store
    else if (parity==0)               //vert and parity determine the label to be read.
    {
        if (direction==Reverse)
        {
            backtrace(label[vert].even,pathNum,stop,(parity+1)%2,Reverse);
            path[pathNum][endPath[pathNum]++]=vert;
        }                             //Forward means the vertices called first enter
        else if (direction==Forward)  //the path first, Reverse is the opposite.
        {
            path[pathNum][endPath[pathNum]++]=vert;
            backtrace(label[vert].even,pathNum,stop,(parity+1)%2,Forward);
        }
    }

    else if (parity==1 && label[vert].odd[1]==undef)
    {
        if (direction==Reverse)
        {
            backtrace(label[vert].odd[0],pathNum,stop,(parity+1)%2,Reverse);
            path[pathNum][endPath[pathNum]++]=vert;
        }
        else if (direction==Forward)
        {
            path[pathNum][endPath[pathNum]++]=vert;
            backtrace(label[vert].odd[0],pathNum,stop,(parity+1)%2,Forward);
        }
    }

    else if (parity==1 && label[vert].odd[1]!=undef)
    {
        if (direction==Reverse)
        {
            backtrace(label[vert].odd[0],pathNum,empty,(parity+1)%2,Reverse);
            backtrace(label[vert].odd[1],pathNum,vert,(parity+1)%2,Forward);
            path[pathNum][endPath[pathNum]++]=vert;
        }
        else if (direction==Forward)
        {
            backtrace(label[vert].odd[1],pathNum,vert,(parity+1)%2,Reverse);
            backtrace(label[vert].odd[0],pathNum,empty,(parity+1)%2,Forward);
            path[pathNum][endPath[pathNum]++]=vert;
        }
    }
}

void enQueue (int vert, int t)
{
    elem tmp;               //EnQueues labels for scanning.
    tmp.vertex=vert;        //No label that's deQueued during the execution
    tmp.type=t;             //of augmentMatching() goes back to the Queue.
    Queue[QueueBack++]=tmp; //Thus, circular arrays are unnecessary.
}

void newBlossom (int a, int b)      //newBlossom() will be called after the paths are evaluated.
{
    int i,base,innerBlossom,innerBase;
    for (i=0; path[0][i]==path[1][i]; i++);   //Find the lowest common ancestor of a and b
    i--;                                      //it will be used to represent the blossom.
    base=blossom[path[0][i]];                 //Unless it's already contained in another...
    //In this case, all will be put in the older one.
    for (int j=i; j<endPath[0]; j++) blossom[path[0][j]]=base;
    for (int j=i+1; j<endPath[1]; j++) blossom[path[1][j]]=base; //Set all nodes to this
    for (int p=0; p<2; p++)                                      //new blossom.
    {
        for (int j=i+1; j<endPath[p]-1; j++)
        {
            if (label[path[p][j]].even==undef)         //Now, new labels will be applied
            {
                label[path[p][j]].even=path[p][j+1];    //to indicate the existence of even
                enQueue(path[p][j],0);                  //and odd length paths.
            }
            else if (label[path[p][j]].odd[0]==undef && label[path[p][j+1]].even==undef)
            {
                label[path[p][j]].odd[0]=path[p][j+1];
                enQueue(path[p][j],1);                 //Labels will only be put if the vertex
            }                                           //doesn't have one.

            else if (label[path[p][j]].odd[0]==undef && label[path[p][j+1]].even!=undef)
            {

                innerBlossom=blossom[path[p][j]];
                innerBase=j;
                for (; blossom[j]==innerBlossom && j<endPath[p]-1; j++);
                j--;
                label[path[p][innerBase]].odd[0]=path[p][j+1];
                label[path[p][innerBase]].odd[1]=path[p][j];
                enQueue(path[p][innerBase],1);
            }
        }
    }
    if (g[a][b]==unmatched)            //All nodes have received labels, except
    {
        if (label[a].odd[0]==undef)     //the ones that called the function in
        {
            label[a].odd[0]=b;           //the first place. It's possible to
            enQueue(a,1);                //find out how to label them by
        }                               //analyzing if they're in the matching.
        if (label[b].odd[0]==undef)
        {
            label[b].odd[0]=a;
            enQueue(b,1);
        }
    }
    else if (g[a][b]==matched)
    {
        if (label[a].even==undef)
        {
            label[a].even=b;
            enQueue(a,0);
        }
        if (label[b].even==undef)
        {
            label[b].even=a;
            enQueue(b,0);
        }
    }
}

void augmentPath ()            //An augmenting path has been found in the matching
{
    int a,b;                  //and is contained in the path arrays.
    for (int p=0; p<2; p++)
    {
        for (int i=0; i<endPath[p]-1; i++)
        {
            a=path[p][i];             //Because of labeling, this path is already
            b=path[p][i+1];           //lifted and can be augmented by simple
            if (g[a][b]==unmatched)   //changing of the matching status.
                g[a][b]=g[b][a]=matched;
            else if (g[a][b]==matched)
                g[a][b]=g[b][a]=unmatched;
        }
    }
    a=path[0][endPath[0]-1];
    b=path[1][endPath[1]-1];
    if (g[a][b]==unmatched) g[a][b]=g[b][a]=matched;
    else if (g[a][b]==matched) g[a][b]=g[b][a]=unmatched;
    //After this, a and b are included in the matching.
    match[path[0][0]]=match[path[1][0]]=true;
}

bool augmentMatching (int n)   //The main analyzing function, with the
{
    int node,nodeLabel;       //goal of finding augmenting paths or
    initAlg(n);               //concluding that the matching is maximum.
    for (int i=0; i<n; i++) if (!match[i])
        {
            label[i].even=empty;
            enQueue(i,0);          //Initialize the Queue with the exposed vertices,
        }                          //making them the roots in the forest.

    while (QueueFront<QueueBack)
    {
        node=Queue[QueueFront].vertex;
        nodeLabel=Queue[QueueFront].type;
        if (nodeLabel==0)
        {
            for (int i=0; i<n; i++) if (g[node][i]==unmatched)
                {
                    if (blossom[node]==blossom[i]);
                    //Do nothing. Edges inside the same blossom have no meaning.
                    else if (label[i].even!=undef)
                    {

                        endPath[0]=endPath[1]=0;
                        backtrace(node,0,empty,0,Reverse);
                        backtrace(i,1,empty,0,Reverse);
                        //Call the backtracing function to find out.
                        if (path[0][0]==path[1][0]) newBlossom(node,i);
                        /*
                          If the same root node is reached, a blossom was found.
                          Start the labelling procedure to create pseudo-contraction.
                        */
                        else
                        {
                            augmentPath();
                            return true;

                        }
                    }
                    else if (label[i].even==undef && label[i].odd[0]==undef)
                    {

                        label[i].odd[0]=node;
                        enQueue(i,1);
                    }
                }
        }
        else if (nodeLabel==1)  //Similar to above.
        {
            for (int i=0; i<n; i++) if (g[node][i]==matched)
                {
                    if (blossom[node]==blossom[i]);
                    else if (label[i].odd[0]!=undef)
                    {
                        endPath[0]=endPath[1]=0;
                        backtrace(node,0,empty,1,Reverse);
                        backtrace(i,1,empty,1,Reverse);
                        if (path[0][0]==path[1][0]) newBlossom(node,i);
                        else
                        {
                            augmentPath();
                            return true;
                        }
                    }
                    else if (label[i].even==undef && label[i].odd[0]==undef)
                    {
                        label[i].even=node;
                        enQueue(i,0);
                    }
                }
        }
        /*
          The scanning of this label is complete, deQueue it and
          keep going to the next one.
        */
        QueueFront++;
    }

    return false;
}

void findMaximumMatching (int n)
{

    for (int i=0; i<n; i++) match[i]=false;

    while (augmentMatching(n));
}

int main()
{
    int n;
    int t, cases = 1;
    scanf("%d", &t);
    while(t--)
    {
        n=readGraph();
        int cnt = 0;
        findMaximumMatching(n);
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                if (g[i][j]==matched)
                {
                    cnt++;
                }
            }
        }
        printf("Case %d: %d\n", cases++, cnt);
    }
    return 0;
}
/*


10
3 3 4
1 3
4 6
1 2
4 5

3 3 1
1 2

3 3 4
1 3
2 5
3 4
4 6

3 4 5
1 3
2 5
3 4
4 6
7 7

3 3 0




*/
