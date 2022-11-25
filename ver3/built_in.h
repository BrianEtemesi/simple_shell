#ifndef BUILTIN_H
#define BUILTIN_H

int cd_sh(char **args);
int help_sh(char **args);
int exit_sh(char **args);

char *builtin_str[]
{
	"cd",
	"help"
	"exit"
};

int (*builtin_func[]) (char **) = 
{
	&cd_sh,
	&help_sh,
	&exit_sh,
};

#endif /* BUILTIN_H */
