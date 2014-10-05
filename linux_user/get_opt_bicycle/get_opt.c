#include "get_opt.h"

#include <string.h>

char *optarg = 0;
int optind = 1, opterr = -1, optopt = 0;

int getopt(int argc, char * const argv[], const char *optstring) {

	int i = 0;
	char *optstrpos;

	if(argv[optind] == NULL)
		return -1;

	if(optstring[0] == ':') {
		opterr = 0;
	}else {
		opterr = -1;
	}

	for(; optind < argc; ++optind) {
		if(argv[optind][0] == '-') {
			if(argv[optind][1] == '-')
				return -1;
			if((optstrpos = strchr(optstring,  argv[optind][1])) != NULL) {
				if(optstrpos[1] == ':') {
					if(argv[optind][2] == NULL) {
						if(argv[optind + 1] == NULL || argv[optind + 1][0] == '-') {
							if(opterr) {
								fprintf(stderr, "Option <-%c> requires an argument.\n", argv[optind][1]);
							}
							return ':';
						} 
						optarg = argv[optind + 1];
					}else {
						optarg = &argv[optind][2];
					}
				}
				return argv[optind][1];
			}else {
				optopt = argv[optind][1];
				if(opterr) {
					fprintf(stderr, "Unknown option <-%c>", argv[optind][1]);
				}
				return '?';
			}
		}
	}
	return -1;
}
