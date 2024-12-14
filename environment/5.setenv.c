#include "environ.h"

size_t **double_count(char **strings)
{
    size_t words, i, **array, letters;

    words = letters = 0;
    /* counting words in array */
    for (i = 0; strings[i]; i++)
        words++;

    /* storing word count in array */
    array = malloc(sizeof(size_t *) * 2);
    if (!array)
        return (NULL);

    array[0] = malloc(sizeof(size_t));
    if (!array[0])
        return (NULL);
    array[0] = &words;

    /* counting the number of letters in each word */
    array[1] = malloc(sizeof(size_t) * words);
    if (!array[1])
        return (NULL);

    for (i = 0; i < words; i++)
    {
        letters = strlen(strings[i]);
        array[1][i] = letters;
    }

    return (array);
}

/**
 * _setenv - changes or adds an environment variable
 *           (without using setenv).
 * @name: variable name to the environment.
 * @value: variable value to name.
 * @overwrite: zero or not zero.
 *
 * Return: zero on success, or -1 on error.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
extern char **environ;
    char **temp_env, *variable, *n, *v, *new_path;
    size_t i, j, l1, l2, words, **count;

    l1 = strlen(name);
    l2 = strlen(value);
    v = strdup(value);
    n = strdup(name);
    variable = _getenv(name);

    /** checking for errors */
    if (!name || !l1 || strchr(name, '='))
    {
        perror("Error:");
        return (-1);
    }

    /** creating new string */
    new_path = malloc(sizeof(char) * (l1 + l2 + 2));
    if (!new_path)
    {
      perror("Error:");
        return (-1);
    }

    for (i = 0; i < l1; i++)
    {
        new_path[i] = n[i];
    }
    new_path[i++] = '=';
    for (j = 0; j < l2; j++)
    {
        new_path[i++] = v[j];
    }
    new_path[i] = 0;

    /** copying strings to a new space */
    count = double_count(environ);
    words = **count;
    temp_env = malloc(sizeof(char *) * (words + 1));
    if (!temp_env)
    {
        perror("Error:");
        return (-1);
    }

    for (i = 0; i < words; i++)
    {
        temp_env[i] = environ[i];
    }

    /** if variable doesn't exist */
    if (!variable)
    {
        temp_env[words] = new_path;
        printf("temp_env[%ld]: %s\n", i, temp_env[i]);
        environ = temp_env;
        variable = new_path;
        printf("_getenv(%s): %s\n", name, _getenv(name));
        return (0);
    }

    /** if variable does exist */
    else
    {
      /** if overwrite is nonzero, change value */
        if (overwrite)
        {
            variable = new_path;
            return (0);
        }
        else
            return (0);
    }

    return (-1);
}
