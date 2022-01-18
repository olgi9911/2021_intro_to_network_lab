#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 80

int main(int argc, char const *argv[]) {
    int sock = 0, valread = 0;
    struct sockaddr_in serv_addr;
    char requestLine[50] = "GET ";
    char *CRTN = " \r\n";
    char host[80] = "";
    char buffer[10005] = "";
    char *start_pos[80];  // pointer to hyperlinks strings
    //create TCP socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    printf("Enter the hostname: ");
    scanf("%s", host);
    char *url = strstr(host, "/");  // extract path
    if (url != NULL) {
        strcat(requestLine, url);   // add /... to GET message
        strcat(requestLine, CRTN);  // add "\r\n"
    }
    serv_addr.sin_family = AF_INET;  // IPv4
    serv_addr.sin_port = htons(PORT);
    // convert url to ip address, remove "/..." path in url
    struct hostent *h = gethostbyname(strtok(host, "/"));
    // save ip address to sockaddr
    memcpy(&serv_addr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
    // establish connection
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    // send GET /... message
    send(sock, requestLine, strlen(requestLine), 0);
    char in[1024] = "";
    valread = recv(sock, in, 1024, 0);  // receive first segment
    strncat(buffer, in, 1024);          // copy receved segment to buffer
    // keep receiving until recv returns 0
    while (valread > 0) {
        char in[1024] = "";
        valread = recv(sock, in, 1024, 0);
        strncat(buffer, in, 1024);
    }
    //printf("%s\n", buffer);
    start_pos[0] = strstr(buffer, "a href=\"");  // move string position to first "a href="
    // point to location of each hyperlink
    int i = 0;
    while (start_pos[i] != NULL) {
        start_pos[i + 1] = strstr(start_pos[i] + 1, "a href=\"");
        i++;
    }
    // remove quotation mark before and after url
    int j = 0;
    for (; j < i; j++) {
        char *str2 = strtok(start_pos[j], "\"");
        str2 = strtok(NULL, "\"");
        printf("%s\n", str2);
    }
    // print number of hyperlinks
    printf("%d\n", j);
    return 0;
}