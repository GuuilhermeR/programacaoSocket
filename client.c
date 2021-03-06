#include <arpa/inet.h> /* inet_addr */
#include <stdio.h>
#include <string.h> /* strlen */
#include <sys/socket.h>
#include <unistd.h> /* close */

int main(int argc, char *argv[]) {
  int socket_desc;
  struct sockaddr_in server;
  char message[2000], server_reply[2000];

  socket_desc = socket(AF_INET, SOCK_STREAM, 0);

  if (socket_desc == -1) {
    printf("Não foi possível criar o socket\n");
    return 1;
  }

  server.sin_addr.s_addr = inet_addr("127.0.0.1"); /* converte IP para long */
  server.sin_family = AF_INET;                     /* ip v4 */
  server.sin_port = htons(8888);

  if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("Erro ao conectar-se\n");
    return 1;
  }

  printf("Conectado.\n");

  do {
    printf("Digite uma mensagem: ");
    scanf("%s", message);
    fflush(stdin);


    if (send(socket_desc, message, strlen(message), 0) < 0) {
      printf("Erro ao enviar\n");
      return 1;
    }
    printf("Dados enviados.\n");

    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
      printf("Falha no recv\n");
      return 1;
    }
    printf("%s\n", server_reply);

  } while (message != "exit");

  close(socket_desc);

  return 0;
}