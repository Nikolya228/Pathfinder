#include "../inc/header.h"

bool error(char *file){
    int fp = open(file, O_RDONLY);
    if (fp == -1){
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" does not exist\n");
        close(fp);
        return 0;
    }
    if (mx_file_to_str(file) == NULL){
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" is empty\n");
        close(fp);
        return 0;
    }
    char *text;
    mx_read_line(&text, 100, '\n', fp);
    for (int i = 0; i < mx_strlen(text); i++){
        if (!mx_isdigit(text[i])){
            mx_printerr("error: line 1 is not valid\n");
            free(text);
            close(fp);
            return 0;
        }   
    }
    text = mx_file_to_str(file);
    if (error_line(text)){
        free(text);
        close(fp);
        return 0;
    }
    if (error_dubl_island(text)){
        free(text);
        close(fp);
        return 0;
    } 
    if (error_num_islands(text)){
        free(text);
        close(fp);
        return 0;
    }
    if (error_max_l(text)){
        free(text);
        close(fp);
        return 0; 
    } 
    close(fp);
    free(text);
    return true;
}

bool error_line(char *text){
    int line = mx_count_substr(text, "\n");
    char *temp  = text;
    while (*temp != '\n') temp++;

    int count_line = 1;
    while (count_line != line){
        count_line++;
        temp++;
        if (*temp == '-'){
            mx_printerr("error: line ");
            mx_printerr(mx_int_to_char(count_line));
            mx_printerr(" is not valid\n");
            return 1;
        }

        char **island1 = mx_strsplit(temp, '-');

        while (*temp != '-'){
            if (!mx_ischar(*temp)){
                mx_printerr("error: line ");
                mx_printerr(mx_int_to_char(count_line));
                mx_printerr(" is not valid\n");
                mx_del_strarr(&island1);
                return 1;
            }
            temp++;
        }
        temp++;
        char **island2 = mx_strsplit(temp, ',');

        while (*temp != ','){
            if(!mx_ischar(*temp)){
                mx_printerr("error: line ");
                mx_printerr(mx_int_to_char(count_line));
                mx_printerr(" is not valid\n");
                mx_del_strarr(&island1);
                mx_del_strarr(&island2);
                return 1;
            }
            temp++;
        }
        temp++;
        if (mx_strcmp(island1[0], island2[0]) == 0){
            mx_printerr("error: line ");
            mx_printerr(mx_int_to_char(count_line));
            mx_printerr(" is not valid\n");
            mx_del_strarr(&island1);
            mx_del_strarr(&island2);
            return 1;
        }
        temp++;

        while (*temp != '\n'){
            if (!mx_isdigit(*temp)){
            mx_printerr("error: line ");
            mx_printerr(mx_int_to_char(count_line));
            mx_printerr(" is not valid\n");
            mx_del_strarr(&island1);
            mx_del_strarr(&island2);
            return 1;
            }
            temp++;
        }
        mx_del_strarr(&island1);
        mx_del_strarr(&island2);
    }
    return 0;
}

bool error_dubl_island(char *text){
    int line = mx_count_substr(text, "\n");
    char *temp  = text;
    while (*temp != '\n') temp++;
    char *islands = NULL;

    int count_line = 1;

    while (count_line != line){
        count_line++;
        temp++;
        
        char *island = *mx_strsplit(temp, ',');
        
        while (*temp != '\n') temp++;
        
        if (mx_count_substr(islands, island) > 0){
            mx_printerr("error: duplicate bridges\n");
            return true;
        }
        islands = mx_strjoin(islands, island);
        char *island_temp = *mx_strsplit(island, '-');

        while (*island != '-') island++;
        island++;
        
        char *island_rev = island;
        island_rev = mx_strjoin(island_rev, "-");
        island_rev = mx_strjoin(island_rev, island_temp);
        if (mx_count_substr(islands, island_rev) > 0){
            mx_printerr("error: duplicate bridges\n");
            return true;
        }
    }
    return false;
}

bool error_num_islands(char *text){
    int line = mx_count_substr(text, "\n");
    char *temp = text;
    char *num_c = *mx_strsplit(temp, '\n');
    int num = mx_atoi(num_c);
    int num_islands = 0;
    while (*temp != '\n') temp++;
    char *islands = NULL;

    int count_line = 1;

    while (count_line != line){
        count_line++;
        temp++;
        
        char **island = mx_strsplit(temp, '-');
        
        if (mx_count_substr(islands, island[0]) <= 0){
            num_islands++;
            islands = mx_strjoin(islands, island[0]);
        }

        while (*temp != '-') temp++; temp++;

        island = mx_strsplit(temp, ',');      
        if (mx_count_substr(islands, island[0]) <= 0 ){
            num_islands++;
            islands = mx_strjoin(islands, island[0]);
        } 

        while (*temp != '\n') temp++;
    }
    
    if (num != num_islands){
        mx_printerr("error: invalid number of island\n");
        return true;
    }
    return false;
}
bool error_max_l(char *text){
    int line = mx_count_substr(text, "\n");

    while (*text != '\n') text++;

    long long int num = 0;
    int count_line = 0;

    while (count_line != line){
        count_line++;
        text++;

        while (*text != ',') text++; text++;

        char **num_c = mx_strsplit(text, '\n');
        num += mx_atoi(num_c[0]);

        if (num >= INT_MAX){
            mx_printerr("error: sum of bridges length is too big\n");
            mx_del_strarr(&num_c);
            return true;
        }

        while (*text != '\n') text++;
        mx_del_strarr(&num_c);
    }

    return false;
}
