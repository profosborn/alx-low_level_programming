#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *create_buffer(char *file);
void close_file(int file_desc);

/**
 * create_buffer - This allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: Pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @file_desc: The file descriptor to be closed.
 */
void close_file(int file_desc)
{
	int result;

	result = close(file_desc);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file_desc %d\n", file_desc);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, read_result, write_result;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	read_result = read(file_from, buffer, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || read_result == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_result = write(file_to, buffer, read_result);
		if (file_to == -1 || write_result == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_result = read(file_from, buffer, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_result > 0);

	free(buffer);
	close_file(file_from);
	close_file(to);

	return (0);
}
