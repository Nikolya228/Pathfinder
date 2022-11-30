#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size){
    void *newptr;
 
    if (ptr == NULL)
        newptr = malloc(size);
    else {
        //if (malloc_size(ptr) < size) { //for macos
        if (malloc_usable_size(ptr) < size) { //for linux
            newptr = malloc(size);
   
            //mx_memcpy(newptr, ptr, malloc_size(ptr)); //for macos
            mx_memcpy(newptr, ptr, malloc_usable_size(ptr));  //for linux
   
            free(ptr);
        }
        else
            newptr = ptr;
    }
 
    return newptr;
}

