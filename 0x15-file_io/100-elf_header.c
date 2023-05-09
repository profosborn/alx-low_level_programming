#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void check_elf(unsigned char *magic_numbers);
void print_magic(unsigned char *magic_numbers);
void print_abi(unsigned char *magic_numbers);
void print_osabi(unsigned char *magic_numbers);
void print_class(unsigned char *magic_numbers);
void print_data(unsigned char *magic_numbers);
void print_version(unsigned char *magic_numbers);
void print_entry(unsigned long int entry_point, unsigned char *magic_numbers);
void print_type(unsigned int elf_type, unsigned char *magic_numbers);
void close_elf(int elf_fd);

/**
 * check_elf - Checks if a file is an ELF file.
 * @magic_numbers: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *magic_numbers)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (magic_numbers[i] != 127 &&
            magic_numbers[i] != 'E' &&
            magic_numbers[i] != 'L' &&
            magic_numbers[i] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *magic_numbers)
{
    int i;

    printf(" Magic: ");

    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", magic_numbers[i]);

        if (i == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * print_class - Prints the class of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *magic_numbers)
{
    printf(" Class: ");

    switch (magic_numbers[EI_CLASS])
    {
        case ELFCLASSNONE:
            printf("none\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", magic_numbers[EI_CLASS]);
    }
}

/**
 * print_data - Prints the data of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *magic_numbers)
{
    printf(" Data: ");

    switch (magic_numbers[EI_DATA])
    {
        case ELFDATANONE:
            printf("none\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", magic_numbers[EI_DATA]);
    }
}

/**
 *  * print_elf_version - Prints the version of an ELF header.
 *   * @header: Pointer to an array containing the ELF header.
 *    */
void print_elf_version(unsigned char *header)
{
	 printf(" Version: %d", header[EI_VERSION]);

	switch (header[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_elf_osabi - Prints the OS/ABI of an ELF header.
 * @header: Pointer to an array containing the ELF header.
 */
void print_elf_osabi(unsigned char *header)
{
	printf(" OS/ABI: ");

	switch (header[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", header[EI_OSABI]);
	}
}

/**

close_file - Closes a file.
@fd: The file descriptor of the file.
Description: If the file cannot be closed - exit code 98.
*/
void close_file(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't close fd %d\n", fd);
exit(98);
}
}
/**

main - Displays the information contained in the

ELF header at the start of an ELF file.

@argc: The number of arguments supplied to the program.

@argv: An array of pointers to the arguments.

Return: 0 on success.

Description: If the file is not an ELF File or

the function fails - exit code 98.
*/
int main(int attribute((unused)) argc, char *argv[])
{
Elf64_Ehdr *header;
int fd, read_res;

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close_file(fd);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
read_res = read(fd, header, sizeof(Elf64_Ehdr));
if (read_res == -1)
{
free(header);
close_file(fd);
dprintf(STDERR_FILENO, "Error: %s: No such file\n", argv[1]);
exit(98);
}

check_elf(header->e_ident);
printf("ELF Header:\n");
print_magic(header->e_ident);
print_class(header->e_ident);
print_data(header->e_ident);
print_version(header->e_ident);
print_osabi(header->e_ident);
print_abi(header->e_ident);
print_type(header->e_type, header->e_ident);
print_entry(header->e_entry, header->e_ident);

free(header);
close_file(fd);
return (0);
}
