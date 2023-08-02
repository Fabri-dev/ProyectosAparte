#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    char abecedario[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char letra,letra_random;
    int i, num_random, intentos, cont;

    cont = 1;
    num_random = rand()%25 ; // Numero random que la saque de google
    letra_random = abecedario[num_random]; // Aca convierto el numero random a letra, se pone en cualquier posicion del array abecedario

    printf("Juego adivinar letra, ingrese cuantos intentos quiere tener: ");
    scanf("%i", &intentos);


    while (cont < intentos) {
        printf("Adivine la letra: \n(Por favor ingrese una letra en minuscula):");
        fflush(stdin);
        scanf("%c", &letra);


        if (letra == letra_random){

            system("cls");
            printf("Felicidades acertaste la letra! \n");
            printf("Usted adivino la letra con: %i intentos",cont);
            break;
        } else if (letra > letra_random){

            printf("Letra mayor a random, ingrese una menor \n");
        } else if (letra < letra_random){

            printf("Letra menor a random, ingrese una mayor \n");
        }

        cont += 1 ; // Esto es igual a contador = contador + 1

    }




    return 0;
}




