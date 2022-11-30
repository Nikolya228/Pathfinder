#include "../inc/libmx.h"

void mx_pop_back(t_list **list) {
	if (*list == NULL || list == NULL) {
        return;
    }
    t_list *temp = *list;
    while(temp->next != NULL){
    	temp = temp->next;
    }
    free(temp);
}

