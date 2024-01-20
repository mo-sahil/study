#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p1 = getpid();
    printf("p1 (pid: %d)\n", p1);

    pid_t p2 = fork();
    if (p2 == 0) {
        printf("p2 (pid: %d, parent: %d)\n", getpid(), getppid());

        pid_t p3 = fork();
        if (p3 == 0) {
            printf("p3 (pid: %d, parent: %d)\n", getpid(), getppid());

            pid_t p4 = fork();
            if (p4 == 0) {
                printf("p4 (pid: %d, parent: %d)\n", getpid(), getppid());
                sleep(2);
                printf("p4 is now an orphan (parent: %d)\n", getppid());
            }
            exit(0);
        }
        wait(NULL);
        exit(0);
    }
    pid_t p5 = fork();
    if (p5 == 0) {
        printf("p5 (pid: %d, parent: %d)\n", getpid(), getppid());

        pid_t p6 = fork();
        if (p6 == 0) {
            printf("p6 (pid: %d, parent: %d)\n", getpid(), getppid());

            pid_t p7 = fork();
            if (p7 == 0) {
                printf("p7 (pid: %d, parent: %d)\n", getpid(), getppid());
                printf("p7 is now a zombie\n");
                exit(0);
            }
            exit(0);
        }
        wait(NULL);
        exit(0);
    }

    wait(NULL);
    return 0;
}

