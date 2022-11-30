#pragma once

#include "libmx.h"

int main(int argc, char **argv);
bool error(char *file);
void skip(int fp, int n);
bool error_line(char *text);
bool error_dubl_island(char *text);
bool error_num_islands(char *text);
bool error_max_l(char *text);
char *find_isl(char *file);
int **build_graph(char *file, char *arr_isl);
int *min_path(int **graph, int begin, int to, char *arr);
int **search_path(int **graph, int *d, int begin, int to);
void print_path(int **graph, int *d, int **ver, int begin, char *islands);
void print_islands(char *islands, int i);
void print_dist(int **graph, int *d, int *ver, int to);
int **unite(int **v, int **ver, int l);
int **split(int **ver, int **v, int l);
