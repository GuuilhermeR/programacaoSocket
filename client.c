#include<stdio.h>
#include<string.h> /* strlen */
#include<sys/socket.h>
#include<arpa/inet.h>  /* inet_addr */
#include<unistd.h> /* close */

int main(int agrc, char *argv[]) {

    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[2000];


    /* AF_INET - IPV4 ; SOCK_STREAM - TECP ; O - IP */
    socket_desc = socket(AF_INET, SOCK_STREAM, 0); 

    if(socket_desc == -1){
        printf("Não foi possível criar o socket.\n");
        return 1;
    }
    
    
    server.sin_addr.s_addr = inet_addr("172.217.28.132"); /* CONVERTER IP PARA LONG */
    server.sin_family = AF_INET; /* IPV4 */ 
    server.sin_port = htons(80); /* DEFINE A PORTA */

    /* CONECTA-SE AO SERVIDOR */
    if(connect(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0){
        printf("Erro ao fazer conexão.\n");
        return 1;
    }

        printf("Você está conectado.\n");


    /* ENVIA DADOS */
    message = "GET / HTTP/1.1\r\n\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0 ){
        printf("Erro ao enviar os dados.\n");
        return 1;
    }


    printf("Dados enviados.\n");

    /* RECEBER DADOS */
    if (recv(socket_desc, server_reply, 2000, 0) < 0){
        printf("Erro ao receber os dados.\n");
        return 1;
    }

    printf("Respostas recebida\n");
    printf("%s\n", server_reply);

    /* ENCERRA CONEXÃO */
    close(socket_desc);


    return 0;
}