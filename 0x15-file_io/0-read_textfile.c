#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read from the file.
 *
 * Return: The number of letters it could read and print. If the file cannot be
 * opened or read, or if write fails or does not write the expected amount of
 * bytes, return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t num_read, num_written;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters + 1));
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	num_read = read(fd, buf, letters);
	if (num_read == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	buf[num_read] = '\0';

	num_written = write(STDOUT_FILENO, buf, num_read);
	if (num_written == -1 || (size_t)num_written != num_read)
	{
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);

	return (num_written);
}
