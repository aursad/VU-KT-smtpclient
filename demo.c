#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "smtp.h"

int main(int argc,char *argv[]){
	char *smtp_host = NULL;
	char  smtp_port[32] = {'\0'};
	int   socket = -1;
	int   step;
    char smtpHost[50], user[50], pass[50], sendto[50], sub[120], body[160];

	char *username = "aurimas.smtp@inbox.lt";//Your account
	char *password = "aurimas1";//Your password
	char *address  = "kaimisx@gmail.com";//Target e-mail address
	char *subject  = "SMTP Client Demo";
	char *content  = "This is content messaage.\n Now test Lithuanian keybord - ąčęėįšųū!";

    print_help();
    do
    {
        printf("-- Selection: ");
        scanf("%d", &step);
        switch(step){
            case 1:
                printf("SMTP server address: ");
                scanf("%s", &smtpHost);
                if(smtpHost) { smtp_host = smtpHost; } else { printf("Empty server address!\n"); }
                printf("----\n");
                break;
            case 2:
                printf("SMTP server port: ");
                scanf("%d", &smtp_port);
                if(!smtp_port) { printf("Empty port. Default port 25!\n"); }
                printf("----\n");
                break;
            case 3:
                printf("Username: ");
                scanf("%s", &user);
                if(user) { username = user; } else { printf("Please insert username!\n"); }
                printf("----\n");
                break;
            case 4:
                printf("Password: ");
                scanf("%s", &pass);
                if(pass) { password = pass; } else { printf("Please insert password!\n"); }
                printf("----\n");
                break;
            case 5:
                printf("Send to: ");
                scanf("%s", &sendto);
                if(sendto) { address = sendto; } else { printf("Please insert email!\n"); }
                printf("----\n");
                break;
            case 6:
                printf("Subject: ");
                scanf("%s", &sub);
                if(sub) { subject = sub; } else { printf("Please insert subject!\n"); }
                printf("----\n");
                break;
            case 7:
                printf("Content: ");
                scanf("%s", &body);
                if(body) { content = body; } else { printf("Please insert content!\n"); }
                printf("----\n");
                break;
            case 8:
                connect2server(&socket,smtp_host,smtp_port);//Connect to the SMTP server
                hello(socket,"Aurimas-HP-Ubuntu");//Say hello
                authenticate(socket,username,password);//Check your authentication
                send_email(socket,username,address,subject,content);//Send an e-mail.
                printf("----\n");
                break;
            case 9:
                return 1;
                break;
            default :
                printf("Please make selection!\n");
        }
	}while(step != 9);
	return 0;
}
