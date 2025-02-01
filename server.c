#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BACKLOG 10
#define PORT "3490"
#define BUFSIZE 1024

int main(void) {
  int sockfd, new_fd, bindcall, listencall, num_bytes;
  int status;
  struct sockaddr_storage their_addr;
  socklen_t addr_size;
  struct addrinfo hints, *servinfo, *p;
  int yes = 1;
  char buffer[BUFSIZE];

 
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_INET; 
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  if ((status = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    exit(1);
  }

  
  sockfd =
      socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
  if (sockfd == -1) {
    perror("socket");
    freeaddrinfo(servinfo);
    exit(1);
  }

  
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
    perror("setsockopt");
    close(sockfd);
    freeaddrinfo(servinfo);
    exit(1);
  }

  bindcall = bind(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);
  if (bindcall == -1) {
    perror("bind");
    close(sockfd);
    freeaddrinfo(servinfo);
    exit(1);
  }

  
  listencall = listen(sockfd, BACKLOG);
  if (listencall == -1) {
    perror("listen");
    close(sockfd);
    freeaddrinfo(servinfo);
    exit(1);
  }

  printf("Servidor escutando na porta %s...\n", PORT);
  while (1) {
    addr_size = sizeof(their_addr);
    new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);

    if (new_fd == -1) {
      perror("accept");
      close(sockfd);
      freeaddrinfo(servinfo);
      exit(1);
    }

    num_bytes = recv(new_fd, buffer, BUFSIZE - 1, 0);
    if (num_bytes < 0) {
      perror("recv");
      close(new_fd);
      continue;
    }
    buffer[num_bytes] = '\0';
    printf("Requisição recebida:\n%s\n", buffer);
    const char *http_response = "HTTP/1.1 200 OK\r\n"
                                "Content-Type: text/html\r\n"
                                "Content-Length: 56\r\n"
                                "\r\n"
                                "<html>"
                                "<body><h1>Server HTTP with C</h1>"
                                "</body></html>";

    if (send(new_fd, http_response, strlen(http_response), 0) == -1) {
      perror("send");
    }

    close(new_fd);
  }

  freeaddrinfo(servinfo);
  close(new_fd);
  close(sockfd);

  return 0;
}
