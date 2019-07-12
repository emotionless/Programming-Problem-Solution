/// **** GAUSS ********


void gauss()
{
    int i, j, k;
    for(i = 1; i < n; i++)
    {
        int ind = i;
        for(j = i + 1; j < n; j++)
            if(fabs(cof[j][i]) > fabs(cof[ind][i])) ind = j;

        if(fabs(cof[ind][i]) < eps) continue;

        if(ind != i)
            for(j = 1; j <= n; j++)
                swap(cof[ind][j], cof[i][j]);

        for(j = i + 1; j < n; j++)
        {
            double c = cof[j][i]/cof[i][i];
            for(k = 1; k <= n; k++)
            {
                cof[j][k] = cof[j][k] - c*cof[i][k];
            }
        }
    }
    x[n - 1] = cof[n - 1][n]/cof[n - 1][n - 1];

    for(i = n - 2; i > 0; i--)
    {
        double sum = 0.0;
        for(j = i + 1; j < n; j++)
            sum += cof[i][j] * x[j];
        x[i] = (cof[i][n] - sum)/cof[i][i];
//        cout<<i<<" "<<x[i]<<endl;
    }
}
