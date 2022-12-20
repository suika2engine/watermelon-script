#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wms.h"

#define MAX_SCRIPT_SIZE		(4 * 1024 * 1024)

char script[MAX_SCRIPT_SIZE];

static bool WMSAPI hello(struct wms_runtime *rt, struct wms_value *arg);

int main(int argc, char **argv)
{
	struct wms_runtime *rt;
	FILE *fp;
	size_t len;

	/* Check the command line arguments. */
	if (argc != 2) {
		fprintf(stderr, "Usage: wms <script-file>\n");
		return 1;
	}

	/* Open the script file. */
	fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		fprintf(stderr, "Could not open script file %s\n", argv[1]);
		return 1;
	}

	/* Read the script file. */
	len = fread(script, 1, sizeof(script) - 1, fp);
	if (len == 0 && ferror(fp) != 0) {
		fprintf(stderr, "Could not read the script file.\n");
		return 1;
	}
	script[len] = '\0';

	/* Parse. */
	rt = wms_make_runtime(script);
	if (rt == NULL) {
		fprintf(stderr, "Syntax error at line %d column %d.\n",
			wms_get_parse_error_line(),
			wms_get_parse_error_column());
		return 1;
	}

	/* Register foreign function. */
	if (!wms_register_ffi_func(rt, "hello", hello)) {
		fprintf(stderr, "%s.\n", wms_get_runtime_error_message(rt));
		return 1;
	}

	/* Execute. */
	if (!wms_run(rt)) {
		fprintf(stderr, "%s at line %d.\n",
			wms_get_runtime_error_message(rt),
			wms_get_runtime_error_line(rt));
		return 1;
	}

	/* Free. */
	wms_free_runtime(rt);

	return 0;
}

/* Foreign function example. */
static bool WMSAPI hello(struct wms_runtime *rt, struct wms_value *arg)
{
	assert(rt != NULL);

	printf("Bonjour!\n");

	wms_set_ffi_arg_value(rt, arg, "hello", "bonjour");

	return true;
}
