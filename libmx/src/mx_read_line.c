#include "../inc/libmx.h"

int mx_read_line(char** lineptr, size_t buf_size, char delim, const int fd){
    if(!fd) {
        close(fd);
        return -2;
    }
    int bytes = 0;

    char* buff = mx_strnew(buf_size);
    char* result = NULL;
    char* temp = mx_strnew(buf_size);
    bool bflag = false;
    while(read(fd, buff, buf_size) > 0) {
        if (bflag) {
            break;
        }
        size_t i = 0;
        while (i < buf_size) {
            if(buff[i] == delim){
                bflag = true;
                break;
            }
            i++;
            bytes++;
        }
        result = mx_strnew(bytes);
        result = mx_strcat(temp, mx_strndup(buff, i));
        temp = mx_strdup(result);

    }
    if (bytes == 0) {
        close(fd);
        mx_strdel(&result);
        mx_strdel(&temp);
        mx_strdel(&buff);
        return -1;
    }
    
   *lineptr = result;
    mx_strdel(&temp);
    mx_strdel(&buff);
    return bytes;
}
