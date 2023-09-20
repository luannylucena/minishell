#include "stdio.h"
#include "unistd.h"

void printList(char **args) {
	int i = 0;
	printf("aqui\n");
	while (args[i]) {
		printf("%d %s ", i, args[i]);
		i++;
	}
	printf("\n");
}

int main(int ac, char **argv, char **envp)
{
	argv++;
	printList(argv);

	//printf("%s\n", *argv);
	// char **args1;
	
	// args1 = argv;
	// //char **args2 = &argv[4];
	// //printf("%s", *args2);

	// argv[3] = NULL;
	//print(args2);
	(void)ac;
	(void)envp;
}