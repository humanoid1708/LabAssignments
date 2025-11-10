#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pipefDescrip[2];

    if(pipe(pipefDescrip) == -1) {
        perror("pipe");
    }

    pid_t pid = fork();

    if(pid < 0) {
        perror("fork");
    }
    else if(pid > 0) {
        close(pipefDescrip[0]);
        char writeMsg[50];
        printf("Enter the message to be sent: ");
        fgets(writeMsg, 50, stdin);
        write(pipefDescrip[1], writeMsg, sizeof(writeMsg));
        close(pipefDescrip[1]);
        printf("Message sent to the child\n");
    }
    else {
        close(pipefDescrip[1]);
        char readMsg[100];
        read(pipefDescrip[0], readMsg, 100);
        printf("Message received by child process is: %s\n", readMsg);
    }
    return 0;
}



