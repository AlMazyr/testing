#include <stdio.h>
//#include <unistd.h>
#include "get_opt.h"

int main(int argc, char* argv[]) {

	char *bargument;
	char oc;

	while((oc = getopt(argc, argv, ":acb:")) != -1) {
		switch(oc) {
			case 'a':
				puts("Option a is founded.");
				break;
			case 'b':
				puts("Option b is founded.");
				printf("Argument is %s\n", optarg);
				bargument = optarg;
				break;

			case 'c':
				puts("Option c is founded.");
				break;
			case ':':
				printf("Option <-%c> requires an argument.\n", optopt);	
				break;
			case '?':
			default:
				printf("Unknown option is <%c>.\n", optopt);
				break;
		}

	}

	return 0;
}
