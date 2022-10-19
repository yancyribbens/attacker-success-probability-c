#include <math.h>

double AttackerSuccessProbability(double q, int z)
{
    double p = 1.0 - q;
    double lambda = z * (q / p);
    double sum = 1.0;
    int i, k;
    for (k = 0; k <= z; k++)
    {
        double poisson = exp(-lambda);
        for (i = 1; i <= k; i++)
            poisson *= lambda / i;
        sum -= poisson * (1 - pow(q / p, z - k));
    }
    return sum;
}

main ()
{
    int z;

    printf("q=0.1\n");
    for (z = 0; z <= 10; z++) {  
        double sum = AttackerSuccessProbability(0.1, z);
        char aa[50];
        sprintf(aa, "%0.7f", sum);
        printf("%s\n", aa);
    }

    printf("\n");
    printf("q=0.3\n");
    for (z = 0; z <= 50; z = z+5) {  
        double sum = AttackerSuccessProbability(0.3, z);
        char aa[50];
        sprintf(aa, "%0.7f", sum);
        printf("%s\n", aa);
    }


    printf("\n");
    printf("P < 0.001\n");
    int z_arr[8] = {5, 8, 11, 15, 24, 41, 89, 340};
    double q_arr[8] = {0.10, 0.15, 0.20, 0.25, 0.30, 0.35, 0.40, 0.45};

    for (z = 0; z <= 7; z++) {  
        double sum = AttackerSuccessProbability(q_arr[z], z_arr[z]);
        char aa[50];
        sprintf(aa, "%0.7f", sum);
        printf("%s\n", aa);
    }
}
