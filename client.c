#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h> 

int main(int agrc, char *argv[]) {

    int socket_desc;
    struct sockaddr_in server;

    /* AF_INET - IPV4 ; SOCK_STREAM - TECP ; O - IP */
    socket_desc = socket(AF_INET, SOCK_STREAM, 0); 

    if(socket_desc == -1){
        printf("Não foi possível criar o socket.\n");
        return 1;
    }
    
    server.sin_addr.s_addr = inet_addr("172.217.28.132"); /* Converter IP para long */
    server.sin_family = AF_INET; /* IPV4 */ 
    server.sin_port = htons(80); /* Define a porta */

    /* CONECTA-SE AO SERVIDOR */
    if(connect(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0){
        printf("Erro ao fazer conexão.");
        return 1;
    }

        printf("Você está conectado.\n");
    
    return 0;
}