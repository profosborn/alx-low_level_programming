#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file to append to.
 * @text_content: The NULL-terminated string to append to the file.
 *
 * Return: 1 on success, or -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_desc, num_written, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	file_desc = open(filename, O_WRONLY | O_APPEND);
	num_written = write(file_desc, text_content, len);

	if (file_desc == -1 || num_written == -1)
		return (-1);

	close(file_desc);

	return (1);
}
