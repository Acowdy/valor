#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static void print_usage(FILE *out);
static void print_options();
int main(int argc, char **argv);

const struct option long_options[] = {
	{"help", no_argument, 0, 'h'},
	{"out", required_argument, 0, 'o'},
	{0, 0, 0, 0},
};

const char *option_argnames[] = {
	0,
	"FILE",
};

const char *option_descriptions[] = {
	"Display this message",
	"Specify the output file",
};

static void
print_usage(FILE *out)
{
	fprintf(out, "Usage: valorc [OPTIONS] [INPUT]\n");
}

static void
print_options()
{
	int i;
	printf("Options:\n");
	for (i = 0; long_options[i].name != 0; ++i) {
		printf("\t");
		if (long_options[i].val != 0) {
			printf("-%c, ", long_options[i].val);
		}
		printf("--%s", long_options[i].name);
		if (option_argnames[i] != 0) {
			printf(" %s", option_argnames[i]);
		}
		printf("\n\t\t%s\n", option_descriptions[i]);
	}
}

int
main(int argc, char **argv)
{
	int c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "ho:", long_options, &opt_index)) != -1) {
		switch (c) {
		case 'h':
			print_usage(stdout);
			printf("\n");
			print_options();
			exit(EXIT_SUCCESS);
		case 'o':
			printf("option -o = value `%s'\n", optarg);
			break;
		/* case 0: break; // handle long-only arguments */
		default:
			print_usage(stderr);
			exit(EXIT_FAILURE);
		}
	}
	argc -= optind;
	argv += optind;
	return EXIT_SUCCESS;
}


