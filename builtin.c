
#include "minishell.h"

void    export(char *args, char **envp)
{
    t_index id;

    id.i = 0;
    id.j = 0;
    id.k = 0;
    while (envp[id.i])
        id.i++;
    envp[id.i] = (char *)malloc(sizeof(char) * (ft_strlen(args) + 1));
    while (args[id.j])
    {
        envp[id.i][id.j] = args[id.k];
        id.j++;
        id.k++;
    }
    envp[id.i][id.j] = '\0';
    id.i++;
    envp[id.i] = NULL;
}

void    print_env(char **envp)
{
    t_index id;

    id.i = 0;
    while (envp[id.i])
    {
        printf("%s\n", envp[id.i]);
        id.i++;
    }
}


void    pwd(char **envp)
{
    int i;

    i = 0;
    while(envp[i])
    {
        if (ft_strncmp(envp[i], "PWD", 3) == 0)
            printf("%s\n", envp[i] + 4);
        i++;
    }
}