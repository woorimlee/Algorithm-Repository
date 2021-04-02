#include <stdio.h>
#include <sys/stat.h>

int main() {
	int ret = 0;
	struct stat buf;
	ret = stat("link.txt", &buf);
	if (ret < 0) {
		printf("ERROR\n");
		return 0;
	}
	
	printf("deviceID[%ld], inode_num[%ld], hardlink_cnt[%ld], filesize[%ld], blocksize[%ld], block_cnt[%ld]\n", buf.st_dev, buf.st_ino, buf.st_nlink, buf.st_size, buf.st_blksize, buf.st_blocks);
	return 0;
}