#include "main.h"

/**
 * create_file - Creates a file and writes the specified content into it.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string containing the content to write.
 *
 * Return: If the function succeeds, it returns 1. Otherwise, it returns -1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	/* Check if the filename is NULL */
	if (filename == NULL)
		return (-1);

	/* Calculate the length of the text content */
	if (text_content != NULL)
	{
		for (len = 0; text_content[len]; len++)
			;
	}

	/* Create the file with read and write permissions */
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* Write the text content to the file */
	w = write(fd, text_content, len);
	if (w == -1)
	{
		close(fd);
		return (-1);
	}

	/* Close the file and return 1 to indicate success */
	close(fd);
	return (1);
}
