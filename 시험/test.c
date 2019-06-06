#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void main(void)
{
	int fd;
	int i;
	char  buf[16];
	int rd;

	errno_t errno = _sopen_s(&fd, "./kw.gif", O_RDONLY, _SH_DENYNO, 0);

	if (fd == -1) {
		perror("open");
		exit(0);
	}

	while (0 < (rd = _read(fd, buf, 16))) {
		for (i = 0; i < 16; i++) {
				printf("%x", buf[i]);
				//두 번마다 띄어쓰기 하나 (하렴 하고 말람 말고)

			}
		//줄바꿈
		//if buf[i]가 아스키코드로 문자 표현 가능한거면 (33~ 127인가)
		//	printf("%c", buf[i]);
			else {
				printf(".");
			}
		}
	}
}