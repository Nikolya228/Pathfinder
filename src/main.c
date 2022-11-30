#include "../inc/header.h"

int main(int argc, char **argv){
    if (argc < 2){
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 0;
    }
    if (!error(argv[1])){
        return 0;
    }
    char *arr_isl = find_isl(argv[1]);
    int **graph = build_graph(argv[1], arr_isl);
    // printf("%s\n", arr_isl);
    
    for (int i = 0; i < mx_length(graph); i++)
        for (int j = i + 1; j < mx_length(graph); j++){
            print_path(graph, min_path(graph, i, j, arr_isl), search_path(graph, min_path(graph, i, j, arr_isl), i, j), i, arr_isl);
        }
}
