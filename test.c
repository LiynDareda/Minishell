
static char *ft_check_var(char *var, int i, t_shell *shell)
{
	char *var_name;
	int len;
	char *res;
	
	len = i;
	while (var[len] || var[len] != ' ' || var[len] != 39 || var[len] != 34)
		len++;
	var_name = malloc(sizeof(char) * len + 1 - i);
	len -= i;
	while (var[i] || var[i] != ' ' || var[i] != 39 || var[i] != 34)
	{
		var_name[i] = var[i];
		i++;
	}
	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], var_name, len) == 0)
		{
			res = var_copy(shell->env[i], var_name);
			return (res);
		} 
		i++;
	}
	return (NULL);
}