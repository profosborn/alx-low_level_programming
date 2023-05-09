#include "main.h"

/**
 * create_file - Creates a file with the specified name and writes the given
 *               text content to it.
 * @filename: The name of the file to be created.
 * @text_content: The text content to write to the created file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, ret, len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		len = 0;
		while (text_content[len] != '\0')
			len++;

		ret = write(fd, text_content, len);
		if (ret != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
