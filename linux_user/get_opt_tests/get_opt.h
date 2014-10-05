#ifndef GET_OPT_H
#define GET_OPT_H

int getopt(int argc, char * const argv[], const char *optstring);

extern char *optarg;
extern int optind, opterr, optopt;

#endif //GET_OPT_H
