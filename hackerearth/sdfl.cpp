#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
// IO
#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 500009



using namespace std;
///******* Template ********///


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}

///***** Template ends here *****///
///********************* Code starts here ****************************


ll  _mergeSort(ll arr[], ll temp[], ll left, ll right);
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right);


ll mergeSort(ll arr[], ll array_size)
{
    ll *temp = (ll *)malloc(sizeof(ll)*array_size);
    return _mergeSort(arr, temp, 0ll, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
ll _mergeSort(ll arr[], ll temp[], ll left, ll right)
{
    ll mid, inv_count = 0;
    if (right > left)
    {
        /* Divide the array llo two parts and call _mergeSortAndCountInv()
           for each of the parts */
        mid = (right + left)/2;

        /* Inversion count will be sum of inversions in left-part, right-part
          and number of inversions in merging */
        inv_count  = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right)
{
    ll i, j, k;
    ll inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid;  /* i is index for right subarray*/
    k = left; /* i is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            /*this is tricky -- see above explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray
     (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray
     (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i=left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

ll arr[MAX];
ll tmp[MAX];

int main()
{
    ll i, j;
    ll t,n,q, a, b, m;
    scanf("%lld", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        tmp[i] = arr[i];
    }
    ll cnt = 0;

    ll get = mergeSort(arr, n);
    if(get == 0)
    {
        cout<<"Cool Array"<<endl;
        return 0;
    }

    cnt = get;
    ll res = cnt, k;
    a = 0, b = 0;
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            for(k = 0; k < n; k++)
                arr[k] = tmp[k];
            swap(arr[i], arr[j]);
            ll koto = mergeSort(arr, n);
            if(koto < res)
            {
                res = koto;
                a = i;
                b = j;
            }
            swap(arr[i], arr[j]);
        }
    }
    if(a == 0 && b == 0)
        printf("Cool Array\n");
    else
        printf("%lld %lld\n", a + 1, b + 1);


    return 0;
}

/*

1 2
3 5
2 4
8 9
6 1

5
1 4 3 2 1

9
1 3 2 2 5 4 3 2 1


*/
