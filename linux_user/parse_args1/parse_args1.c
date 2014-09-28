#include <stdio.h>
#include <strings.h>

int main(int argc, char *argv[]) {
	
	int i = 1, b_arg = 0, parse_opts = 1, j = 0;
	char b_arg_buf[128];
	bzero(b_arg_buf, sizeof(b_arg_buf));

	if(argc < 2) {
		puts("No args.");
		return 0;
	}

//	puts("Starting to parse arguments.");
	for(; i < argc; ++i) {
		
		if(b_arg) {
			if(argv[i][0] != '-') {
				printf("Argument of -b is %s.\n", argv[i]);
				b_arg = 0;
				continue;
			}
			puts("Missing -b argument.");
		}

		b_arg = 0;

		if(argv[i][0] == '-') {
			if(argv[i][1] == '-') {
				break;
			}
			
			j = 1;
			parse_opts = 1;

			// starting to parse.
			while(parse_opts && argv[i][j]) {

			// new options arrived
			switch(argv[i][j]) {
				case 'a':
					puts(" Option -a is founded.");
					break;
				case 'b':
					puts(" Option -b is founded.");
					if(!argv[i][j + 1]) {
						b_arg = 1;
					}else {
						printf("Argument of -b is %s.\n", &argv[i][j + 1]);
						b_arg = 0;
						parse_opts = 0;
					}
					break;
				case 'c':
					puts(" Option -c is founded.");
					break;
				default:
					parse_opts = 0;
					break;
			}
			++j;
			}
			
		}

	}

	//puts("End parse.");

	return 0;
}
