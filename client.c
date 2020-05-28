#include<stdio.h>
#include<sys/socket.h>

int main(int agrc, char *argv[]) {

    /* AF_INET - IPV4 ; SOCK_STREAM - TECP ; O - IP */
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0); 

    if(socket_desc == -1){
        printf("Não foi possível criar o socket\n");
        return 1;
    }
    
    
    return 0;
}