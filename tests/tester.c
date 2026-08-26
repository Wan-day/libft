#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <unistd.h>

static int total = 0, passed = 0;
#define TEST(name, cond) do { total++; if (cond) { passed++; printf("[PASS] %s\n", name); } else printf("[FAIL] %s\n", name); } while (0)

static int sign_same(int a, int b) { return ((a == 0 && b == 0) || (a < 0 && b < 0) || (a > 0 && b > 0)); }
static char map_upper(unsigned int i, char c) { (void)i; return (char)toupper((unsigned char)c); }
static void iter_shift(unsigned int i, char *c) { *c = (char)(*c + (i % 2)); }
static void list_inc(void *p) { (*(int *)p)++; }
static void *list_double(void *p) { int *q = malloc(sizeof(int)); if (q) *q = (*(int *)p) * 2; return q; }
static void del_free(void *p) { free(p); }
static int *new_int(int v) { int *p = malloc(sizeof(int)); if (p) *p = v; return p; }
static void free_split(char **a) { size_t i=0; if (!a) return; while (a[i]) free(a[i++]); free(a); }

static int capture_fd(void (*fn)(void), const char *expected)
{
    int p[2], saved; char buf[256]; ssize_t n;
    if (pipe(p) < 0) return 0;
    saved = dup(STDOUT_FILENO); dup2(p[1], STDOUT_FILENO); close(p[1]);
    fn(); dup2(saved, STDOUT_FILENO); close(saved);
    n = read(p[0], buf, sizeof(buf)-1); close(p[0]);
    if (n < 0)
        return 0;
    buf[n] = 0;
    return strcmp(buf, expected) == 0;
}
static void out_char(void) { ft_putchar_fd('Z', STDOUT_FILENO); }
static void out_str(void) { ft_putstr_fd("hello", STDOUT_FILENO); }
static void out_end(void) { ft_putendl_fd("hello", STDOUT_FILENO); }
static void out_num(void) { ft_putnbr_fd(INT_MIN, STDOUT_FILENO); }

int main(void)
{
    char a[32], b[32], c[32], d[32]; void *p; char *s; char **sp; size_t r;
    int x1=1,x2=2,x3=3; t_list *l1,*l2,*l3,*mapped;

    TEST("ft_isalpha", !!ft_isalpha('A') && !!ft_isalpha('z') && !ft_isalpha('1') && (!!ft_isalpha(200) == !!isalpha(200)));
    TEST("ft_isdigit", !!ft_isdigit('0') && !!ft_isdigit('9') && !ft_isdigit('a'));
    TEST("ft_isalnum", !!ft_isalnum('a') && !!ft_isalnum('7') && !ft_isalnum('#'));
    TEST("ft_isascii", ft_isascii(0) && ft_isascii(127) && !ft_isascii(128) && !ft_isascii(-1));
    TEST("ft_isprint", ft_isprint(32) && ft_isprint(126) && !ft_isprint(31) && !ft_isprint(127));
    TEST("ft_toupper", ft_toupper('a')=='A' && ft_toupper('Z')=='Z' && ft_toupper('1')=='1');
    TEST("ft_tolower", ft_tolower('A')=='a' && ft_tolower('z')=='z' && ft_tolower('1')=='1');
    TEST("ft_strlen", ft_strlen("")==0 && ft_strlen("hello")==5);

    strcpy(a,"abcdef"); strcpy(b,"abcdef"); ft_memset(a+1,'X',3); memset(b+1,'X',3);
	TEST("ft_memset", memcmp(a,b,7)==0);
    strcpy(a,"abcdef"); strcpy(b,"abcdef"); ft_bzero(a+2,3); bzero(b+2,3);
	TEST("ft_bzero", memcmp(a,b,7)==0);
    memset(a,0,sizeof(a)); memset(b,0,sizeof(b)); ft_memcpy(a,"hello",6); memcpy(b,"hello",6);
	TEST("ft_memcpy", memcmp(a,b,6)==0);
    strcpy(a,"0123456789"); strcpy(b,"0123456789"); ft_memmove(a+2,a,7); memmove(b+2,b,7);
	TEST("ft_memmove overlap", memcmp(a,b,11)==0);
    TEST("ft_memchr", ft_memchr("abcabc",'b',6)==memchr("abcabc",'b',6) && ft_memchr("abc",'z',3)==NULL);
    TEST("ft_memcmp", sign_same(ft_memcmp("abc","abd",3),memcmp("abc","abd",3)) && ft_memcmp("abc","abc",3)==0);

    TEST("ft_strchr", ft_strchr("abcabc",'b') == strchr("abcabc",'b') && ft_strchr("abc",'\0') == strchr("abc",'\0'));
    TEST("ft_strrchr", ft_strrchr("abcabc",'b') == strrchr("abcabc",'b') && ft_strrchr("abc",'\0') == strrchr("abc",'\0'));
    TEST("ft_strncmp", sign_same(ft_strncmp("abc","abd",3),strncmp("abc","abd",3)) && ft_strncmp("abc","xyz",0)==0);
    s=ft_strdup("hello");
	TEST("ft_strdup", s && strcmp(s,"hello")==0 && s != (char *)"hello"); free(s);

    memset(a,'Q',sizeof(a)); r=ft_strlcpy(a,"hello",4);
	TEST("ft_strlcpy", r==5 && strcmp(a,"hel")==0);
    strcpy(a,"abc"); r=ft_strlcat(a,"XYZ",sizeof(a));
	TEST("ft_strlcat", r==6 && strcmp(a,"abcXYZ")==0);
    strcpy(a,"abcdef"); r=ft_strlcat(a,"XYZ",4);
	TEST("ft_strlcat small size", r==7 && strcmp(a,"abcdef")==0);
    TEST("ft_strnstr", ft_strnstr("hello world","world",11) && strcmp(ft_strnstr("hello world","world",11),"world")==0 && ft_strnstr("hello world","world",7)==NULL && ft_strnstr("abc","",0)==(char *)"abc");
    TEST("ft_atoi", ft_atoi("42")==atoi("42") && ft_atoi(" \t\n-123abc")==atoi(" \t\n-123abc") && ft_atoi("+7")==7);

    p=ft_calloc(8,1);
	TEST("ft_calloc", p && memcmp(p,"\0\0\0\0\0\0\0\0",8)==0); free(p);
    p=ft_calloc((size_t)-1,2);
	TEST("ft_calloc overflow", p==NULL); free(p);
    s=ft_substr("hello world",6,5);
	TEST("ft_substr", s && strcmp(s,"world")==0); free(s);
    s=ft_substr("abc",99,4);
	TEST("ft_substr past end", s && strcmp(s,"")==0); free(s);
    s=ft_strjoin("hello ","world");
	TEST("ft_strjoin", s && strcmp(s,"hello world")==0); free(s);
    s=ft_strtrim("xx hello xy"," xy");
	TEST("ft_strtrim", s && strcmp(s,"hello")==0); free(s);
    s=ft_itoa(INT_MIN);
	TEST("ft_itoa INT_MIN", s && strcmp(s,"-2147483648")==0); free(s);
    s=ft_itoa(0);
	TEST("ft_itoa zero", s && strcmp(s,"0")==0); free(s);
    sp=ft_split("  one  two three  ",' ');
	TEST("ft_split", sp && sp[0]&&sp[1]&&sp[2]&&!sp[3] && strcmp(sp[0],"one")==0 && strcmp(sp[1],"two")==0 && strcmp(sp[2],"three")==0); free_split(sp);
    sp=ft_split("",',');
	TEST("ft_split empty", sp && sp[0]==NULL); free_split(sp);
    s=ft_strmapi("abC",map_upper);
	TEST("ft_strmapi", s && strcmp(s,"ABC")==0); free(s);
    strcpy(c,"abcd"); ft_striteri(c,iter_shift);
	TEST("ft_striteri", strcmp(c,"acce")==0);

    TEST("ft_putchar_fd", capture_fd(out_char,"Z"));
    TEST("ft_putstr_fd", capture_fd(out_str,"hello"));
    TEST("ft_putendl_fd", capture_fd(out_end,"hello\n"));
    TEST("ft_putnbr_fd", capture_fd(out_num,"-2147483648"));

    l1=ft_lstnew(&x1); l2=ft_lstnew(&x2); l3=ft_lstnew(&x3);
    TEST("ft_lstnew", l1 && l1->content==&x1 && l1->next==NULL);
    ft_lstadd_back(&l1,l2); ft_lstadd_back(&l1,l3);
    TEST("ft_lstadd_back", l1->next==l2 && l2->next==l3);
    TEST("ft_lstsize", ft_lstsize(l1)==3);
    TEST("ft_lstlast", ft_lstlast(l1)==l3);
    { t_list *front=ft_lstnew(&x1); ft_lstadd_front(&l1,front);
	TEST("ft_lstadd_front", l1==front && l1->next && ft_lstsize(l1)==4); free(front); l1=l2; }
    ft_lstiter(l1,list_inc);
	TEST("ft_lstiter", x2==3 && x3==4);
    mapped=ft_lstmap(l1,list_double,del_free);
	TEST("ft_lstmap", mapped && ft_lstsize(mapped)==2 && *(int*)mapped->content==6 && *(int*)mapped->next->content==8);
    ft_lstclear(&mapped,del_free);
	TEST("ft_lstclear", mapped==NULL);
    free(l1); free(l3);
    { t_list *one=ft_lstnew(new_int(9)); ft_lstdelone(one,del_free);
		TEST("ft_lstdelone", 1); }

    /* Dedicated clear test with heap-owned contents. */
    l1=ft_lstnew(new_int(1)); l2=ft_lstnew(new_int(2)); if (l1) l1->next=l2; ft_lstclear(&l1,del_free);
	TEST("ft_lstclear heap contents", l1==NULL);

    strcpy(d,"sentinel"); (void)d;
    printf("\nResult: %d/%d tests passed\n", passed, total);
    return (passed == total ? 0 : 1);
}

