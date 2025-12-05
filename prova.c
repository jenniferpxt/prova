#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    char *categoria;
} Produto;

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    Produto *p = malloc(n * sizeof(Produto));
    char buffer[200];

    for (int i = 0; i < n; i++) {
        fgets(buffer, 200, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        p[i].nome = malloc(strlen(buffer) + 1);
        strcpy(p[i].nome, buffer);

        fgets(buffer, 200, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        p[i].categoria = malloc(strlen(buffer) + 1);
        strcpy(p[i].categoria, buffer);
    }

    int menor = 0;
    for (int i = 1; i < n; i++)
        if (strlen(p[i].nome) < strlen(p[menor].nome))
            menor = i;

    int max = 0;
    char *cat = NULL;
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < n; j++)
            if (!strcmp(p[i].categoria, p[j].categoria))
                c++;
        if (c > max) {
            max = c;
            cat = p[i].categoria;
        }
    }

    int tam = 1;
    for (int i = 0; i < n; i++)
        tam += strlen(p[i].nome) + 1;

    char *concat = malloc(tam);
    concat[0] = 0;

    for (int i = 0; i < n; i++) {
        strcat(concat, p[i].nome);
        if (i < n - 1) strcat(concat, ";");
    }

    printf("%s\n", p[menor].nome);
    printf("%s\n", cat);
    printf("%s\n", concat);

    for (int i = 0; i < n; i++) {
        free(p[i].nome);
        free(p[i].categoria);
    }
    free(p);
    free(concat);
}
