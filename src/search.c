#include "../inc/header.h"

int *min_path(int **graph, int begin, int to, char *arr){
    if (arr || to){}
    int *d = (int *)malloc(mx_length(graph) * sizeof(int)); //минимальное растояние
    int v[mx_length(graph)]; //посещеные вершины
    int temp, minindex = 0, min = 0;
    

    for (int i = 0; i < mx_length(graph); i++){
        d[i] = 100000;
        v[i] = 1;
    }
    d[begin] = 0;
    
    while (minindex < 100000) {
        minindex = 100000, min = 100000;
        
        for (int i = 0; i < mx_length(graph); i++){
            if ((v[i] == 1) && (d[i] < min)){
                min = d[i];
                minindex = i;
            }
        }
        if (minindex != 100000){
            for(int i = 0; i < mx_length(graph); i++){
                if (graph[minindex][i] > 0){
                    temp = min + graph[minindex][i];
                    if (temp < d[i]){
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }

    }
    // printf("\n%i %i \n D[]: ", begin, to);
    // for (int i = 0; i < 5; i++) printf("%i ", d[i]);
    // printf("\n");
    return d;
}
int **search_path(int **graph, int *d, int begin, int to){
    if (d || begin || to || graph){}
    bool flag = true;
    int **ver = (int **)malloc(2 * sizeof(int*));
    ver[0] = (int *)malloc(mx_length(graph) * sizeof(int));
    ver[1] = NULL;
    for (int i = 0; i < mx_length(graph); i++){ ver[0][i] = -1;}
    int end = to;
    ver[0][0] = end;
    int k = 1;
    int weight = d[end];

    while (end != begin){
        for (int i = 0; i < mx_length(graph); i++){
            if (graph[end][i] != 0){
                int temp = weight - graph[end][i];
                if (temp == d[i] && flag){
                    flag = false;
                    ver[0][k] = i;
                    k++;
                }
                else if (temp == d[i] && !flag){
                    int **v = (int **)malloc(2 * sizeof(int *));
                    v[0] = (int *)malloc(mx_length(graph) * sizeof(int));
                    v[1] = NULL;
                    for (int j = 0; j < mx_length(graph); j++){
                        if (j == k - 1){
                            v[0][j] = i;
                        }
                        else v[0][j] = ver[0][j];
                    }
                    // printf("\n");
                    // printf("\n k: %i\n", k);
                    // for (int j = 0; v[j] != NULL; j++)
                    // for (int i = 0; i < mx_length(graph); i++){
                    //     printf(" %i", v[j][i]);
                    // }
                    // printf("\n");
                    
                    v = unite(v, search_path(graph, d, begin, i), mx_length(graph));
                    // printf("\n");
                    // printf("\n k: %i\n", k);
                    // for (int j = 0; v[j] != NULL; j++)
                    // for (int i = 0; i < mx_length(graph); i++){
                    //     printf(" %i", v[j][i]);
                    // }
                    // printf("\n");
                    ver = split(ver, v, mx_length(graph));
                    // for (int j = 0; v[j] != NULL; j++){
                    //         printf("\nj: %i k: %i\n", j, k);
                    //         for (int h = 0; h < mx_length(graph); h++) printf(" ver: %i ", v[j][h]);
                    // }
                    // printf("\n");
                }
            }
            if (i == mx_length(graph) - 1){
                weight -= graph[end][ver[0][k - 1]];
                end = ver[0][k - 1];
                flag = true;
            }
        }
    }
    return ver;
}

int **unite(int **v, int **ver, int l){
    int count_1 = 0;
    while (v[count_1] != NULL) count_1++;

    int count_2 = 0;
    while (ver[count_2] != NULL) count_2++;

    int count = count_1 + count_2 + 1;

    // printf("\nv[][]: \n");
    // for (int j = 0; v[j] != NULL; j++)
    // for (int i = 0; i < l; i++){
    //     printf(" %i", v[j][i]);
    // }
    // printf("\nver[][]: \n");
    // for (int j = 0; ver[j] != NULL; j++)
    // for (int i = 0; i < l; i++){
    //     printf(" %i", ver[j][i]);
    // }
    // printf("\n");


    int **new_ver = (int **)malloc(count * sizeof(int *));
    for (int i = 0; i < count - 2; i++){
        new_ver[i] = (int *)malloc(l * sizeof(int));
        for (int j = 0; j < l; j++) new_ver[i][j] = -1;
    }
    new_ver[count - 1] = NULL;
    count_1 = 0;

    while (v[0][count_1] != -1){
        new_ver[0][count_1] = v[0][count_1];
        count_1++;
    }

    for (int i = 1; ver[0][i] != -1; i++, count_1++){
        new_ver[0][count_1] = ver[0][i];
    }
    for (int i = 1; ver[i] != NULL; i++){
        for (int j = 0; j < l; j++) new_ver[i][j] = ver[i][j];
    }

    
    return new_ver;
}
int **split(int **ver, int **v, int l){
    int count_1 = 0, count_2 = 0, count = 0;
    while (ver[count_1] != NULL) count_1++;
    while (v[count_2] != NULL) count_2++;

    int **new_ver = (int **)malloc((count_1 + count_2 + 1) * sizeof(int));
    for (int i = 0; ver[i] != NULL; i++){
        new_ver[count] = (int *)malloc(l * sizeof(int));
        for (int j = 0; j < l; j++) new_ver[count][j] = ver[i][j];
        count++;
    }
    for (int i = 0; v[i] != NULL; i++){
        new_ver[count] = (int *)malloc(l * sizeof(int));
        for (int j = 0; j < l; j++) new_ver[count][j] = v[i][j];
        count++;
    }
    new_ver[count] = NULL;
    return new_ver;
}
