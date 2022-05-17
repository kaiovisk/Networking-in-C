#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {
    
  // Apparently, I need to create a socket.
  int network_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_IP);

  struct sockaddr_in server_addr;

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(9000);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  int connection_status = connect(network_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

  if (connection_status == -1) {
    printf("There was an error with the socket \r\n");
  }

  char server_res[256];
  recv(network_socket, &server_res, sizeof(server_res), 0);
  
  printf("Sended the data: %s\n", server_res);

  close(network_socket);

  return 0;
}
