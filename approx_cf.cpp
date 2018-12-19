#include "approx_cf.h"

/* MAIN */
int main(int argc, char *argv[]) {
	if ( argc < 4 ) return EXIT_FAILURE;
	t_timemes t_run = {0};
	t_init(t_run);

	const char *patterns_filename = argv[1], *patt_size_pch = argv[2], *filename = argv[3];
	unsigned int patt_size = atoi(patt_size_pch), text_size = 0;
	uchar *text = NULL, *pattern = NULL;
	FILE * file = NULL;

	text_size = read_file_content<uchar>(&text, filename);
	if (text == NULL) return EXIT_FAILURE;

	pattern = (uchar*)calloc (patt_size+1, CH_SIZE);
	if (pattern == NULL) { free(text); report_critical_error("Error: Can't allocate memory for pattern."); }

	file = fopen (patterns_filename, "rb");
	if (!file) { free(text); free(pattern); report_critical_error("Error: Can't open patterns file."); }

	while (fread (pattern, CH_SIZE, patt_size, file)==patt_size) {
		t_start(t_run);
		cf::cf1<cf::cf1_verif_lev>(pattern, patt_size, text, text_size, K_DIFF, NULL);
		t_stop(t_run);
	}
	approx_cf::print_result(t_get_seconds(t_run), 0, indexes.size(), text_size, patt_size, K_DIFF);
	indexes.clear();
	free(text);
	free(pattern);
	fclose(file);

	return EXIT_SUCCESS;
}
