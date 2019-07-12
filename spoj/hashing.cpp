#define prime 15485863  /// must be greater than the number ///
using namespace std;

int tabl[16000010];
int flag[16000010];

void insert(int a)
{
     int key=(a%prime+prime)%prime;
     while(flag[key]>0&&tabl[key]!=a) key=(key+1)%prime;    /// while don't find the number ///
     tabl[key]=a;
     flag[key]++;
}

int find(int a)
{
     int key=(a%prime+prime)%prime;
     while(flag[key]>0&&tabl[key]!=a) key=(key+1)%prime;
     return flag[key];
}
