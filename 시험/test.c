void main(void)
{
	int fd;
	int i, count;
	char  buf[16];
	ssize_t rd;
	int count = 0;
	fd = open("./kw.gif", O_RDONLY);
	if (fd == -1) {
		perror("open");
		exit(0);
	}

	while (0 < (rd = read(fd, buf, 16))) {
		count = 0;
		for (i = 0; i < 16; i++) {
			printf("%x", buf[i]);
			count++;
			if (count == 2) {
				printf(" ");
				count = 0;
			}
		}
		printf("   ");
		for (i = 0; i < 16; i++) {
			if (buf[i] > 32 && buf[i] < 127) {
				printf("%c", buf[i]);
			}
			else {
				printf(".");
			}
		}
		printf("\n");
	}
}