#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

#define ADDRPORT 9000
#define MAXCONN 10

int main() {
  
  char server_message[256] = "Hello, world!";

  int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);  
  
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(ADDRPORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
  
  listen(server_socket, MAXCONN);

  int client_socket;
  client_socket = accept(server_socket, NULL, NULL);

  send(client_socket, server_message, sizeof(server_message), 0);

  close(server_socket);

  return 0;
}
