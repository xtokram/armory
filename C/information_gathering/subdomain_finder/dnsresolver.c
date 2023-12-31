#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdbool.h>

void printBanner(void);

int main(int argc, char *argv[])
{
    char * target;
    target = argv[1];
    struct hostent *host;

    char *subdomain;
    char content[50];
    FILE *wordlist;
    wordlist = fopen(argv[2], "r");

    if(argc < 3){
        printf(" [+] T0kr4m's SUBDOMAIN Fuzzer [+] \n"
               " Usage: ./dnsresolver dns.com wordlist \n"
               " Exiting... \n");
        return 0;
    }

    printBanner();

    if (target == NULL){
        printf("Targer is invalid! \n");
        return 0;
    }

    while(fscanf(wordlist, "%s", &content) != EOF){
        subdomain = (char * ) strcat(content, target);
        host=gethostbyname(subdomain);

        if(host == NULL)
            continue;

        printf("[+] SubDomain found: %s and has IP: %s \n", subdomain, inet_ntoa(*((struct in_addr *)host->h_addr)));

    }


    return 0;
}


void printBanner(void){
printf(""
"@@@@@@@@@@@@@@@@@%####################################***+************###@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@*+%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%-@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@=************************+*************************+#@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@@@@@@@@@@@@@@#%@@%%#@@@@@@@@@@@@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@@@@@@@@@@@@#%%%%#%%@#@@@@@@@@@@@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@@@@@@@@@@@@#%#@%#%%#*@@@@@@@@@@@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@@@@@@@@@@@@*+#**+##*+@@@@@@@@@@@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@@@@@@@@@@@##+=**%*=***%@@@@@@@@@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@@@@@@@#*%%*@#++**++*+@@%%#@@@@@@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@@@@@%#@@*##@+**+##%%*@%%@@#@@@@@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@@@@#%@@%*%%*##%#*#%@##+*@@@#@@@@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@@%#*#%%@@%*%%%@#%##+@%%%%*#%#@@@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@%#%@@@@@@#@@%*%%#@@+*%@@@@%##%@@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@*@@@@@%#*@%%%%#@##@*@#%@@@@@@#@@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@*@%%%%@*#%%%#*%*%%@#@@@#%@@@@@#@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@@@@@@@@##%%@%#@@@@@%%@@@@*%%%%%@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@:@@@@@@@@@@@@@@@@#@@@@@%@@@@@@%@@@@%@@@@@@@@@@@@@@@#*@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+#@=**************************************************+#@+%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@+*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@*+##**#**##***#***#**##***#***#***#***#***#***#***#***#**##=#@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@*+%%*@***##**##***#***#***#***#**+#**+#**+#**+#**+#**=##*=%%*@#+#@@@@@@@@@@@@\n"
"@@@@@@@@@@@#+#@@@@@@@@@@@@@@@@@@@@@%******************#@@@@@@@@@@@@@@@@@@@@@@#+#@@@@@@@@@@\n"
"@@@@@@@@@#+#@@@@@@@@@@@@@@@@@@@@@@=+%%%%%%%%%%%%%%%%%#+-%@@@@@@@@@@@@@@@@@@@@@@#+#@@@@@@@@\n"
"@@@@@@@%-=***********************+======================+************************--%@@@@@@\n"
"@@@@@@@#+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+**********+*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#+@@@@@@\n"
"@@@@@@@@+*************************************************************************+%@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"\n \n \t \t \t \t [+] T0kr4m's DNS RESOLVER [+] \n \n "
);


}
