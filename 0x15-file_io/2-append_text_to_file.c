#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function succeeds, it returns 1. Otherwise, it returns -1.
 *
 * Description: This function opens a file specified by `filename` and appends
 * the contents of `text_content` to the end of the file. If the file does not
 * exist, or if the user lacks write permissions, the function returns -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result, len = 0;

	/* Check if the filename is NULL */
	if (filename == NULL)
		return (-1);

	/* Calculate the length of the text content */
	if (text_content != NULL)
	{
		for (len = 0; text_content[len]; len++)
			;
	}

	/* Open the file in write mode and set the file pointer to the end */
	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);

	/* Write the text content to the end of the file */
	write_result = write(file_descriptor, text_content, len);
	if (write_result == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	/* Close the file and return 1 to indicate success */
	close(file_descriptor);
	return (1);
}
