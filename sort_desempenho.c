#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void bubble_sort(int a[], int n);
void insertion_sort(int a[], int n);
void selection_sort(int a[], int n);
void preenche_lista(int a[], int n);
void print_lista(int a[], int n);

int main(void) {
    int *lista, Tam_lista;
    char tipo_ordenacao;
    struct timeval start, end;

    printf("Tipo de ordenação desejado (B-bubble, I-insertion ou S-selection): ");
    scanf(" %c", &tipo_ordenacao);

    printf("Tamanho da lista: ");
    scanf("%d", &Tam_lista);

    lista = (int*)malloc(Tam_lista * sizeof(int));
    if (lista == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    preenche_lista(lista, Tam_lista);

    gettimeofday(&start, NULL);

    if (tipo_ordenacao == 'B') {
        bubble_sort(lista, Tam_lista);
    } 
    else if (tipo_ordenacao == 'I') {
        insertion_sort(lista, Tam_lista);
    } 
    else if (tipo_ordenacao == 'S') {
        selection_sort(lista, Tam_lista);
    } 
    else {
        printf("Tipo de ordenação inválido.\n");
        free(lista);
        return 1;
    }

    gettimeofday(&end, NULL);
    
    print_lista(lista, Tam_lista);

    long seconds = end.tv_sec - start.tv_sec;
    long micros = end.tv_usec - start.tv_usec;
    printf("\nO tempo de execução foi de %ld segundos e %ld microsegundos.\n", seconds, micros);

    free(lista);
    return 0;
}

void bubble_sort(int a[], int n) {
    int i, j, tmp;
    for (i = 0; i < n - 1; i++) {  
        for (j = 0; j < n - i - 1; j++) { 
            if (a[j] > a[j + 1]) {  
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void insertion_sort(int a[], int n) {
    int i, j, tmp;
    for (i = 1; i < n; i++) {
        j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            tmp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = tmp;
            j--;
        }
    }
}

void selection_sort(int a[], int n) { 
    int i, j, min, aux;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (i != min) {
            aux = a[i];
            a[i] = a[min];
            a[min] = aux;
        }
    }
}

void print_lista(int a[], int n) {
    for (int i = 0; i < n; i++) { 
        printf("\nv[%d]: %d", i + 1, a[i]);
    }
    printf("\n");
}

void preenche_lista(int a[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000 + 1;
    }
}
