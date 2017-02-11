#include <sys/types.h>

#include <stdlib.h>
#include <unistd.h>

void	 hd(const u_char *, int);

int
main(int argc, char *argv[])
{
	ssize_t	 siz;
	char	 buf[512];

	while ((siz = read(STDIN_FILENO, buf, sizeof(buf))) > 0)
		hd(buf, siz);

	exit(EXIT_SUCCESS);
}
