# _This project has been created as part of the 42 curriculum by dboldino._

## Description

This is the project that has the goal of recreating and learning some basic libc functions and extra functions provided by the 42Prague libft project. In total there are 39 functions that can be divided into several groups:

 1. Functions that are used for working with linked lists.
 2. Functions that check if the char belongs in a specific group (isdigit, isalpha, etc.)
 3. Functions that work with memory.
 4. Functions that work with strings.
 5. Functions that produce output on a specific file descriptor.

Complete list of functions and their prototypes:

### Linked list functions:
unsigned int	ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));

### Is functions: 
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);

### Memory functions:
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t n, size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

### String functions:
size_t			ft_strlcat(char *dest, const char *src, size_t dsize);
size_t			ft_strlcpy(char *dest, const char *src, size_t dsize);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *nptr);
int				ft_tolower(int c);
int				ft_toupper(int c);

### Print finctions:
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);



## Instructions

To compile and use the library you need to use the Makefile that is already present in the repo. 

 1. Clone the repo into a directory.
 2. Open the terminal inside the directory.
 3. Run ***make*** to create the libft.a file which is the library file you need to use.
 4. Copy the libft.a and libft.h files into your codebase and import the library using #include "libft.h".

## Resources

For the creating and writing of the functions I have use the man pages to see how to real functions operate and their prototypes. Additionally the AI was used as an assistant when debugging the functions when I was stuck.


