if(mx == -1)
        printf("Forget about apartments. Live in the dormitory.");
    else if(q == -1 && p >= 0)
        printf("You should rent the apartment #%d alone.",p+1);
    else if(p >= 0 & q >= 0)
        printf("You should rent the apartment #%d with the friend #%d.",p+1,q+1);
    else
        printf("Forget about apartments. Live in the dormitory.");


    return 0;
}
