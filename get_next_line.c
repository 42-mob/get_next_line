//#include "get_next_line.h"
//#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

// buffer_size < \n || EOF !!!
// buffer = char lidos até BUFFER_SIZE ou até EOF
// Verificar se dentro do buffer tem \n
//		não = usa auxiliar
//			1. line zerada -> (setada no "")
//			2. guardar o que tem dentro de buffer dentro da line
// Verificar se dentro de buffer tem \n ou EOF
//		não = line com conteudo
//			1. line(atual) copia pra a auxiliar(temp) o conteudo
//			2. line(atual) = line auxiliar(temp) concatena com o que acabou de ler
//			3. libera o auxiliar(temp)
//		sim = guarda o que tem até \n dentro da line junto o que já tinha

// line = retornar
// auxiliar = se necessário pra fazer a concatenação 
//			-> segura o valor anterior da line + novo valor
char	*get_next_line(int fd)
{
	char	*buff;
	char	*backup;
	char	*copy;
	int		count_buff;
	int		count_backup;

	count_buff = 0;
	count_backup = 0;
	buff = malloc(BUFFER_SIZE * sizeof(char));
	printf("buff antes do read: %s\n", buff);
	printf("ponteiro buff antes do read: %p\n", buff);
	backup = malloc(BUFFER_SIZE * sizeof(char));
	read (fd, buff, BUFFER_SIZE);
	printf("buff depois do read: %s\n", buff);
	printf("ponteiro buff antes do read: %p\n", buff);
	while (buff[count_buff] != '\n')
		count_buff++;
	copy = ft_substr(buff, 0, count_buff + 1);
	count_buff++;
	while (count_buff < BUFFER_SIZE)
	{
		backup[count_backup] = buff[count_buff];
		count_buff++;
		count_backup++;
	}
	return (copy);
}

int main(void)
{
	char	*str;
	int		fd;

	fd = open("41_with_nl", O_RDONLY);
	str = get_next_line(fd);
	//printf("string str: %s", str);
	/* str = get_next_line(fd);
	str = get_next_line(fd);
	str = get_next_line(fd); */
	/* while(1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			printf("str vazia\n");
			break ;
		}
		printf("> %s\n", str);
		free(str);
	} */
	return (0);
}
