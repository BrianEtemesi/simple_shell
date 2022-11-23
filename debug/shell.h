#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFSIZE 1024

void proc_exec(char *cmd, char *argv[]);
void print_shell(char *buffer, size_t size);

#endif /* SHELL_H */
