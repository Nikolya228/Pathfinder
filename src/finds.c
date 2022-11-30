#include "../inc/header.h"

char *find_isl(char *file){
    char *arr = NULL;
    char *text = mx_file_to_str(file);
    int line = mx_count_substr(text, "\n");
    int count_line = 1;
    int str = 0;

    
    while (*text != '\n') text++;

    while (line != count_line){
        text++;
        count_line++;

        char **islands = mx_strsplit(text, '-');
        
        while (*text != '-') text++; text++;
        //printf("%s\n", islands[0]);

        if (mx_count_substr(arr, islands[0]) <= 0){
            arr = mx_strjoin(arr, mx_itoa(str));
            arr = mx_strjoin(arr, ",");
            arr = mx_strjoin(arr, islands[0]);
            str++;
        }
        islands = mx_strsplit(text, ',');
        //printf("%s\n", islands[0]);

        while (*text != '\n') text++;

        if (mx_count_substr(arr, islands[0]) <= 0){
            arr = mx_strjoin(arr, mx_itoa(str));
            arr = mx_strjoin(arr, ",");
            arr = mx_strjoin(arr, islands[0]);
            str++;
        }
    }
    return arr = mx_strjoin(arr, "\n");
}
int **build_graph(char *file, char *arr_isl){
    char *temp = arr_isl;
    int max;
    while (*arr_isl != '\0'){
        if (mx_atoi(*mx_strsplit(arr_isl, ',')) > 0){
            max = mx_atoi(*mx_strsplit(arr_isl, ','));
        }
        arr_isl++;
    }
    max++;
    
    int **graph = (int **)malloc((max + 1) * sizeof(int*));
    for (int i = 0; i < max; i++) graph[i] = (int *)malloc(max * sizeof(int));
    graph[max] = NULL;
    
    char *text = mx_file_to_str(file);
    int line = mx_count_substr(text, "\n");
    int count_line = 1;

    while (*text != '\n') text++;
    while (line != count_line){
        text++;
        count_line++;
        char **island1 = mx_strsplit(text, '-');

        while (*text != '-') text++; text++;

        char **island2 = mx_strsplit(text, ',');

        while (*text != ',') text++; text++;
        
        char **num = mx_strsplit(text, '\n');
        
        while (*text != '\n') text++;
        
        graph[mx_atoi(mx_strsplit(&temp[mx_get_substr_index(temp, island1[0]) - 2], ',')[0])][mx_atoi(mx_strsplit(&temp[mx_get_substr_index(temp, island2[0]) - 2], ',')[0])] = (int)mx_atoi(num[0]);
        graph[mx_atoi(mx_strsplit(&temp[mx_get_substr_index(temp, island2[0]) - 2], ',')[0])][mx_atoi(mx_strsplit(&temp[mx_get_substr_index(temp, island1[0]) - 2], ',')[0])] = (int)mx_atoi(num[0]);
    }
    return graph;
}
