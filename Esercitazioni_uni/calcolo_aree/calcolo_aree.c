#include <stdio.h>
#include <math.h>

int main()
{
    float D, area_quad, area_cerchio, area_trian_equi;

    printf("Inserisci il numero reale di base: ");
    scanf("%f", &D);

    area_quad = pow(D, 2);
    area_cerchio = pow(D / 2.0, 2) * M_PI;
    area_trian_equi = D * (sqrt(pow(D, 2) - pow(D / 2.0, 2))) / 2;

    printf("L'area del quadrato di lato %f e' %f \n", D, area_quad);
    printf("L'area del cerchio di diametro %f e' %f \n", D, area_cerchio);
    printf("L'area del triangolo equilatero di lato %f e' %f \n", D, area_trian_equi);

    return 0;
}