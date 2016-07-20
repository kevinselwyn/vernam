//tcnlhryzucrpzlxbdaxneezanegkbtasluzqe
//ijamsvilleijamsvilleijamsvilleijamsvi
//yomcantputabackdoorinmanualencryption

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static void lowercase(char **str) {
	int i = 0, l = 0;
	char c;
	char *tmp = NULL;

	tmp = *str;

	for (i = 0, l = (int)strlen(tmp); i < l; i++) {
		c = tmp[i];

		if ((int)c >= 65 && (int)c <= 90) {
			c += (char)32;
		}

		tmp[i] = c;
	}
}

static int mod(a, b) {
	int r = a % b;

    return r < 0 ? r + b : r;
}

static void usage(char *exec) {
	int length = 0;

	length = (int)strlen(exec) + 7;

	printf("Usage: %s [--help] [--table] [--row <row>] [--pad <pad>]\n", exec);
	printf("%*s [--key <key>] [--cipher <cipher>] [--text <text>]\n", length, " ");
}

int main(int argc, char *argv[]) {
	int rc = 0, pad = 1, table = 0, offset = 0;
	int i = 0, j = 0, k = 0, l = 0;
	char a, b, c;
	char *exec = NULL, *flag = NULL, *key = NULL, *row = NULL;
	char *text_a = NULL, *text_b = NULL;

	exec = argv[0];

	if (argc < 2) {
		usage(exec);

		rc = 1;
		goto cleanup;
	}

	for (i = 0, l = argc; i < l; i++) {
		flag = argv[i];

		if (strncmp("--", flag, 2) == 0) {
			if (strcmp("help", flag+2) == 0) {
				usage(exec);

				rc = 1;
				goto cleanup;
			} else if (strcmp("table", flag+2) == 0) {
				table = 1;
			} else if (strcmp("row", flag+2) == 0) {
				if (i + 1 == argc) {
					usage(exec);

					rc = 1;
					goto cleanup;
				}

				row = (char *)malloc(sizeof(char) * 27);

				strcpy(row, argv[i + 1]);
				lowercase(&row);

				i++;
			} else if (strcmp("pad", flag+2) == 0) {
				if (i + 1 == argc) {
					usage(exec);

					rc = 1;
					goto cleanup;
				}

				pad = atoi(argv[i + 1]);

				i++;
			} else if (strcmp("key", flag+2) == 0) {
				if (i + 1 == argc) {
					usage(exec);

					rc = 1;
					goto cleanup;
				}

				key = (char *)malloc(sizeof(char) * (strlen(argv[i + 1]) + 1));

				strcpy(key, argv[i + 1]);
				lowercase(&key);

				i++;
			} else if (strcmp("cipher", flag+2) == 0 || strcmp("text", flag+2) == 0) {
				if (i + 1 == argc) {
					usage(exec);

					rc = 1;
					goto cleanup;
				}

				text_a = (char *)malloc(sizeof(char) * (strlen(argv[i + 1]) + 1));
				text_b = (char *)malloc(sizeof(char) * (strlen(argv[i + 1]) + 1));

				strcpy(text_a, argv[i + 1]);
				lowercase(&text_a);

				i++;
			}
		}
	}

	if (!row || pad == 0) {
		printf("Cannot generate square without starting row and padding amount\n");

		rc = 1;
		goto cleanup;
	}

	if (table == 1) {
		offset = 0;

		for (i = 0, j = (int)strlen(row); i < j; i++) {
			if (i == 0) {
				printf(" %s\n", alpha);
			}

			for (k = 0, l = (int)strlen(row); k < l; k++) {
				if (k == 0) {
					printf("%c", alpha[i]);
				}

				printf("%c", mod((mod(((int)row[k] - 97), l) + offset), 26) + 97);
			}

			offset += pad;
			printf("\n");
		}

		rc = 0;
		goto cleanup;
	}

	if (!key) {
		printf("Cannot decode without key\n");

		rc = 1;
		goto cleanup;
	}

	if (!text_a && !text_b) {
		printf("Cannot encode or decode without text or cipher\n");

		rc = 1;
		goto cleanup;
	}

	l = (int)strlen(key);

	for (i = 0, j = (int)strlen(text_a); i < j; i++) {
		a = text_a[i];
		b = key[i % l];
		c = (char)(mod(((int)row[(int)a - 97] - 97) + mod(((int)b - 97) * pad, 26), 26) + 97);

		text_b[i] = c;
	}

	printf("%s\n", text_b);

cleanup:
	if (key) {
		free(key);
	}

	if (row) {
		free(row);
	}

	if (text_a) {
		free(text_a);
	}

	if (text_b) {
		free(text_b);
	}

	return rc;
}