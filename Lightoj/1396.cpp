#include<bits/stdc++.h>

using namespace std;


int main()
{
    int i,k;
    int n;
    int t, cases = 1;
    cin>>t;
    string str;
    while(t--)
    {
        cin>>str;
        i = 0;
        while(str[0] == '0')
            str.erase(str.begin());

        string str2;
        str2 = str;


        int len = str.length();
        int lim = len - len / 2;

        while(i < lim)
            str2[len - i - 1] = str2[i++];

        i = 0;
        bool flag = false;
        while(i < len)
        {
            if(str[i] < str2[i])
            {
                flag = true;
                break;
            }
            if(str[i] > str2[i])
            {
                flag = false;
                break;
            }
            i++;
        }
        printf("Case %d: ", cases++);

        if(str2.length() == 0)
        {
            cout<<1<<endl;
            continue;
        }

        if(flag)
        {
            cout<<str2<<endl;
            continue;
        }
        //cout<<str2<<endl;
        i = lim - 1;
        while(i > -1)
        {
            if(str2[i] < '9')
            {
                str2[i]++;
                break;
            }
            else
                str2[i] = '0';
            i--;
        }
        i = 0;
        while(i < lim)
            str2[len - i - 1] = str2[i++];
        if(str2[0] == '0')
        {
            str2[len - 1] = '1';
            str2 = "1" + str2;
        }
        cout<<str2<<endl;
    }
    return 0;
}
