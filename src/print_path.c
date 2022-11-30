#include "../inc/header.h"

void print_path(int **graph, int *d, int **ver, int begin, char *islands){
    for (int i = 0; ver[i] != NULL; i++){
        // printf("\n");
        // for (int h = 0; ver[h] != NULL; h++){
        // for (int j = 0; j < mx_length(graph); j++){
        //     printf("%i ", ver[h][j]);
        // }
        // printf("\n");}
        mx_printstr("========================================\n");
        mx_printstr("Path: ");
        print_islands(islands, begin);
        mx_printstr(" -> ");
        print_islands(islands, ver[i][0]);
        mx_printchar('\n');
        mx_printstr("Route: ");
        for (int j = mx_length(graph) - 1; j >= 0 ; j--){
            if (ver[i][j] != -1 && ver[i][j] != ver[i][0]){
                print_islands(islands, ver[i][j]);
                mx_printstr(" -> ");
            }
            else if(ver[i][j] != -1) print_islands(islands, ver[i][j]);
        }
        mx_printchar('\n');
        mx_printstr("Distance: ");
        print_dist(graph, d, ver[i], ver[i][0]);
        mx_printchar('\n');
        mx_printstr("========================================\n");
    }

}

void print_islands(char *islands, int i){
    while(mx_atoi(mx_strsplit(islands, ',')[0]) != i) islands++;
    islands += 2;

    while(mx_atoi(mx_strsplit(islands, ',')[0]) != i + 1 && *islands != '\n'){
        mx_printchar(*islands);
        islands++;
    }
}

void print_dist(int **graph, int *d, int *ver, int to){
    bool b = true;
    for (int i = mx_length(graph) - 1; i >= 0; i--){
        if (ver[i] != -1 && ver[i - 1] != to && b){
            mx_printint(graph[ver[i]][ver[i - 1]]);
            mx_printstr(" + ");
            mx_printint(graph[ver[i - 1]][ver[i - 2]]);
            b = false;
        }
        else if (ver[i] != -1 && ver[i - 1] == to && b){
            mx_printint(d[to]);
            break;
        }
        else if (ver[i] != -1 && ver[i - 1] == to && !b){
            mx_printstr(" = ");
            mx_printint(d[to]);
            break;
        }
        else if (ver[i] != -1 && ver[i - 1] != to && !b){
            mx_printstr(" + ");
            mx_printint(graph[ver[i - 1]][ver[i - 2]]);
        }
    }
}
