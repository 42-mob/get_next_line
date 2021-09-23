
#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define OPEN_MAX 256
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef enum e_bool
{
	FALSE = 0,
	TRUE = !FALSE,
}			t_bool;

/**
 * @brief Copy the STR to a new pointer.
 *
 * @param s1 the string to be copied.
 * @return a new address with the same string of str.
 */
char	*ft_strdup(const char *s1);

/**
 * @brief Copy the from the (S + START) to (LEN).
 *
 * @param s the address of the start of the string
 * @param start start the copy from here.
 * @param len number of the bytes to be copied.
 * @return a new address to with the copy.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief 	Function returns the length of STR.
 *
 * @param s string to be counted.
 * @return length of the STR.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Allocates memory and in each memory put one 0.
 *
 * @param nbr the amount of memory to be allocated.
 * @param size the size of the memory to be allocated.
 * @return address of the space that was allocated.
 */
void	*ft_calloc(size_t nbr, size_t size);

/**
 * @brief Function copies the SRC to DEST,while dosen't reach the SIZE.
 *
 * @param dest strign to be recieve the copy.
 * @param src string to be copied.
 * @param size copy until this number.
 * @return is the len of SRC + DEST if SIZE < DEST then SRC + SIze.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief Copy the SRC to DEST, it copies only until the N byte and then
 * complete with a null byte.
 * @param	DST to be sub.
 * @param	SRC to be copied.
 * @param	N until this bit.
 * @return	the dest with the copy of src.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Copy the S1 concatenate with S2.
 *
 * @param s1 string to start the new string.
 * @param s2 string to end the new string.
 * @return new address with the s1 + s2.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Function locates the first N in the STR.
 *
 * @param s to be search
 * @param c to be find
 * @return the address of the first N.
 */
char	*ft_strchr(const char *s, int c);

#endif
