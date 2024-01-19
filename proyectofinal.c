#include <stdio.h>

void mayorYMenor(float nums[], float mayor_y_menor[2]) {
    mayor_y_menor[0] = nums[0];
    mayor_y_menor[1] = nums[0];

    for (int i = 0; i < 4; i++) {
        if (nums[i] < mayor_y_menor[0])
            mayor_y_menor[0] = nums[i];

        if (nums[i] > mayor_y_menor[1])
            mayor_y_menor[1] = nums[i];
    }
}

float promedioSinExtremos(float nums[]) {
    float mayor_y_menor[2];
    mayorYMenor(nums, mayor_y_menor);

    float sum = 0.0;
    for (int i = 0; i < 5; i++) {
        sum += nums[i];
    }

    return (sum - mayor_y_menor[0] - mayor_y_menor[1]) / 3;
}

int main() {
    float numeros[5];
    float mejorCotizacion = 0.0; 
    int mejorCotizacionIndex = -1; 

    printf("Ingrese 5 valores mayores a $20,000:\n");

    for (int i = 0; i < 5; i++) {
        do {
            printf("Valor #%d: ", i + 1);
            scanf("%f", &numeros[i]);

            if (numeros[i] <= 20000) {
                printf("El valor debe ser mayor a $20,000. Intente de nuevo.\n");
            }

            
            if (numeros[i] > mejorCotizacion) {
                mejorCotizacion = numeros[i];
                mejorCotizacionIndex = i;
            }
        } while (numeros[i] <= 20000);
    }

    float extremos[2];
    mayorYMenor(numeros, extremos);

    printf("Cotizaciones eliminadas:\n");
    for (int i = 0; i < 2; i++) {
        printf("%.2f\n", extremos[i]);
    }

    printf("Promedio: %.2f\n", promedioSinExtremos(numeros));

    
    if (mejorCotizacionIndex != -1) {
        printf("La mejor cotizacion es el valor #%d: %.2f\n", mejorCotizacionIndex + 1, mejorCotizacion);
    }

    return 0;
}
