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
				//�� ������ ���� �ϳ� (�Ϸ� �ϰ� ���� ����)

			}
		//�ٹٲ�
		//if buf[i]�� �ƽ�Ű�ڵ�� ���� ǥ�� �����ѰŸ� (33~ 127�ΰ�)
		//	printf("%c", buf[i]);
			else {
				printf(".");
			}
		}
	}
}