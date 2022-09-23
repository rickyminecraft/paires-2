#include "Paire.h"
#include <Windows.h>

int main()
{
	Paire Jeux;
	if (Jeux.Main_loop())
	{
		return EXIT_SUCCESS;
	}

	return EXIT_FAILURE;
}
