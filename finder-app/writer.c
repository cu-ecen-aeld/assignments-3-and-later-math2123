#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<syslog.h>

char logfile[]="log";

int main(int argc, char** argv){
    openlog(logfile, LOG_CONS, LOG_USER);

    if(argc < 3){
        if(argc == 1){
            printf("missing writefile and writestr\n");
        }
        if(argc == 2){
            printf("missing writestr\n");
        }
        syslog(LOG_DEBUG, "missing");
        exit(1);
    }

    int fd;
    fd = creat(argv[1], 0644);
    if(fd == -1){
        //perror("fd error");
        syslog(LOG_DEBUG, "fd error");
        exit(1);
    }
    ssize_t nr;
    char* str;
    str = strcat(argv[2], "\n");
    nr = write(fd, str, strlen(str));
    if(nr == -1){
        //perror("nr error");
        syslog(LOG_DEBUG, "nr error");
        exit(1);
    }

    //char str2[strlen(str)];
    //sprintf(str2, "Writing %s to %s", str, argv[1]);
    //syslog(LOG_DEBUG, "%s", str2);
    syslog(LOG_DEBUG, "Writing %s to %s", str, argv[1]);
    closelog();
    return 0;
}
