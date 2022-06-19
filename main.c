#include "./inc/philosophers.h"

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (!philosopher(argv))
		{
			printf("Incorrect arguments...");
			return (EXIT_FAILURE);
		}
	}
	else if (argc < 5 || argc > 6)
	{
		printf("Choose correct amount of arguments\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}