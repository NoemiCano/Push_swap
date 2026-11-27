#include <stdio.h>

int	main(void)
{
	int	bit = 0;
	int	index = 42;

	if (!index)
	{
		printf("0\n");
		return 0;
	}

	while (index >> bit)
		bit++;
	bit--;
	while (bit >= 0)
		printf("%d", (index >> bit--) & 1);
	printf("text\n");
}
