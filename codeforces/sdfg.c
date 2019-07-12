///****** Booth's algorithm *******//
/**
Given a string. Determine the position from where
the rotation string will be the smallest.
Ex: mississippi
Output: 10 (0-indexing)
**/


int f[MAX];
int Booth(char txt[])
{
    int n = strlen(txt);
    for(int i = 0; i < MAX; i++) f[i] = -1;
    int k = 0;
    for(int j = 1; j < n; j++)
    {
        int i = f[j - k - 1];
        while(i != -1 && txt[j] != txt[k + i + 1])
        {
            if(txt[j] < txt[k + i + 1])
                k = j - i - 1;
            i = f[i];
        }
        if(i == -1 && txt[j] != txt[k + i + 1])
        {
            if(txt[j] < txt[k + i + 1])
                k = j;
            f[j - k] = -1;
        }
        else
            f[j - k] = i + 1;
    }
    return k;
}
