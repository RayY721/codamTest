/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:46:43 by kuyu              #+#    #+#             */
/*   Updated: 2025/05/05 14:49:46 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <string.h>
#include <strings.h>

// cc libftmain.c libft.a -o test


// main for isalpha, isdigit, isalnum, isascii, isprint
/* int	main(void)
{
	// isalpha
	char c1 = 'a';
	char c2 = '-';

	if ((ft_isalpha(c1) && isalpha(c1)) == (ft_isalpha(c1) || isalpha(c1)))
		printf("The ft_isalpha function is correct\n");
	else
		printf("The ft_isalpha function is incorrect\n");
	if ((ft_isalpha(c2) && isalpha(c2)) == (ft_isalpha(c2) || isalpha(c2)))
		printf("The ft_isalpha function is correct\n");
	else
		printf("The ft_isalpha function is incorrect\n");

	// isdigit()
	c1 = '4';
	c2 = 'a';

	if ((ft_isdigit(c1) && isdigit(c1)) == (ft_isdigit(c1) || isdigit(c1)))
		printf("The ft_isdigit function is correct\n");
	else
		printf("The ft_isdigit function is incorrect\n");
	if ((ft_isdigit(c2) && isdigit(c2)) == (ft_isdigit(c2) || isdigit(c2)))
		printf("The ft_isdigit function is correct\n");
	else
		printf("The ft_isdigit function is incorrect\n");

	c1 = '4';
	c2 = 'a';
	char c3 = '-';

	if ((ft_isalnum(c1) && isalnum(c1)) == (ft_isalnum(c1) || isalnum(c1)))
		printf("The ft_isalnum function is correct\n");
	else
		printf("The ft_isalnum function is incorrect\n");
	if ((ft_isalnum(c2) && isalnum(c2)) == (ft_isalnum(c2) || isalnum(c2)))
		printf("The ft_isalnum function is correct\n");
	else
		printf("The ft_isalnum function is incorrect\n");
	if ((ft_isalnum(c3) && isalnum(c3)) == (ft_isalnum(c3) || isalnum(c3)))
		printf("The ft_isalnum function is correct\n");
	else
		printf("The ft_isalnum function is incorrect\n");

	c3 = '\xAA';
	if ((ft_isascii(c3) && isascii(c3)) == (ft_isascii(c3) || isascii(c3)))
		printf("The ft_isascii function is correct\n");
	else
		printf("The ft_isascii function is incorrect\n");
	
	c3 = 5;
	if ((ft_isprint(c3) && isprint(c3)) == (ft_isprint(c3) || isprint(c3)))
		printf("The ft_isprint function is correct\n");
	else
		printf("The ft_isprint function is incorrect\n");
	
	char *str = "This is a string.";
	
	printf("The result of ft_strlen is %zu.\n", ft_strlen(str));
	printf("The result of strlen is %zu.\n", strlen(str));
	if (ft_strlen(str) == strlen(str))
		printf("ft_strlen is correct\n");
	else
		printf("ft_strlen is incorrect\n");
	return (0);
} */

void print_result(const char *func, int passed) {
    printf("%s: [%s]\n", func, passed ? "OK" : "FAIL");
}

void test_memset() {
    char s1[10] = "abcdefghi";
    char s2[10] = "abcdefghi";
    ft_memset(s1 + 2, 'X', 4);
    memset(s2 + 2, 'X', 4);
    print_result("ft_memset", memcmp(s1, s2, 10) == 0);
}

void test_bzero() {
    char s1[10] = "abcdefghi";
    char s2[10] = "abcdefghi";
    ft_bzero(s1 + 2, 4);
    bzero(s2 + 2, 4);
    print_result("ft_bzero", memcmp(s1, s2, 10) == 0);
}

void test_memcpy() {
    char src[] = "12345";
    char d1[10] = "abcdefghi";
    char d2[10] = "abcdefghi";
    ft_memcpy(d1, src, 5);
    memcpy(d2, src, 5);
    print_result("ft_memcpy", memcmp(d1, d2, 10) == 0);
}

void test_memmove() {
    char d1[10] = "123456789";
    char d2[10] = "123456789";
    ft_memmove(d1 + 2, d1, 5);
    memmove(d2 + 2, d2, 5);
    print_result("ft_memmove", memcmp(d1, d2, 10) == 0);
}

void test_toupper() {
    int pass = 1;
    for (int i = -128; i <= 127; i++) {
        if (ft_toupper(i) != toupper(i)) {
            pass = 0;
            break;
        }
    }
    print_result("ft_toupper", pass);
}

void test_tolower() {
    int pass = 1;
    for (int i = -128; i <= 127; i++) {
        if (ft_tolower(i) != tolower(i)) {
            pass = 0;
            break;
        }
    }
    print_result("ft_tolower", pass);
}

void test_strchr() {
    char *s = "abcdef";
    print_result("ft_strchr", ft_strchr(s, 'd') == strchr(s, 'd'));
}

void test_strrchr() {
    char *s = "abcabc";
    print_result("ft_strrchr", ft_strrchr(s, 'a') == strrchr(s, 'a'));
}

void test_strncmp() {
    print_result("ft_strncmp", ft_strncmp("abc", "abd", 3) == strncmp("abc", "abd", 3));
}

void test_memchr() {
    char *s = "hello world";
    print_result("ft_memchr", ft_memchr(s, 'w', 11) == memchr(s, 'w', 11));
}

void test_memcmp() {
    print_result("ft_memcmp", ft_memcmp("abc", "abd", 3) == memcmp("abc", "abd", 3));
}

void test_atoi() {
    print_result("ft_atoi", ft_atoi("  -123abc") == atoi("  -123abc"));
}

void test_calloc() {
    void *a = ft_calloc(4, sizeof(int));
    void *b = calloc(4, sizeof(int));
    int res = memcmp(a, b, 4 * sizeof(int)) == 0;
    free(a); free(b);
    print_result("ft_calloc", res);
}

void test_strdup() {
    char *s = "42";
    char *a = ft_strdup(s);
    char *b = strdup(s);
    int res = strcmp(a, b) == 0;
    free(a); free(b);
    print_result("ft_strdup", res);
}

void test_substr() {
    char *s = ft_substr("HelloWorld", 5, 5);
    print_result("ft_substr", strcmp(s, "World") == 0);
    free(s);
}

void test_strjoin() {
    char *s = ft_strjoin("Hello", "42");
    print_result("ft_strjoin", strcmp(s, "Hello42") == 0);
    free(s);
}

void test_strtrim() {
    char *s = ft_strtrim("$$Hello$$", "$");
    print_result("ft_strtrim", strcmp(s, "Hello") == 0);
    free(s);
}

void test_split() {
    char **arr = ft_split("a,b,c", ',');
    int ok = strcmp(arr[0], "a") == 0 && strcmp(arr[1], "b") == 0 && strcmp(arr[2], "c") == 0 && arr[3] == NULL;
    print_result("ft_split", ok);
    for (int i = 0; arr[i]; i++) free(arr[i]);
    free(arr);
}

void test_itoa() {
    char *s = ft_itoa(-1234);
    print_result("ft_itoa", strcmp(s, "-1234") == 0);
    free(s);
}

void print_list(t_list *lst) {
    while (lst) {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

void iter_fn(void *p) {
	 ((char *)p)[0] += 1; 
}

void test_lst_functions() {
    t_list *a = ft_lstnew(strdup("1"));
    ft_lstadd_front(&a, ft_lstnew(strdup("0")));
    ft_lstadd_back(&a, ft_lstnew(strdup("2")));
    print_result("ft_lstsize", ft_lstsize(a) == 3);
    print_result("ft_lstlast", strcmp(ft_lstlast(a)->content, "2") == 0);

    // test iter/map
    
    ft_lstiter(a, iter_fn);
    print_result("ft_lstiter", ((char *)a->content)[0] == '1');

    t_list *mapped = ft_lstmap(a, (void *(*)(void *))strdup, free);
    print_result("ft_lstmap", mapped && strcmp(mapped->content, "1") == 0);

    // clear
    ft_lstclear(&a, free);
    ft_lstclear(&mapped, free);
    print_result("ft_lstclear", a == NULL && mapped == NULL);
}


int main() {

	test_memset(); test_bzero(); test_memcpy(); test_memmove();
    test_toupper(); test_tolower();
    test_strchr(); test_strrchr(); test_strncmp(); test_memchr();
    test_memcmp(); test_atoi(); test_calloc(); test_strdup();

    // Part 2
    test_substr(); test_strjoin(); test_strtrim(); test_split();
    test_itoa();

    // Bonus
    test_lst_functions();
    return 0;
}
/* 	
int	main(void)
{
	char	str[] = "   -1234ab567";
	// "   ---+--+1234ab567";
	printf("The atoi result is %d.\n", atoi(str));
	printf("The ft_atoi result is %d.\n", ft_atoi(str));
	return (0);
}
} */


// int	main(void)
// {
// 	char c = 'c';
// 	printf("The char is %c.\n", c);
// 	printf("The result is %c.\n", ft_toupper(c));
// 	return (0);
// }

// int	main(void)
// {
// 	char c = '+';
// 	printf("The char is %c.\n", c);
// 	printf("The result is %c.\n", ft_tolower(c));
// 	return (0);
// }

// atoi()
/* int	main(void)
{
	char	str[] = "   -1234ab567";
	// "   ---+--+1234ab567";
	printf("The atoi result is %d.\n", atoi(str));
	printf("The ft_atoi result is %d.\n", ft_atoi(str));
	return (0);
} */

// memset()
/* int	main(void)
{
	char	str[] = "   -1234ab567";
	char	str2[] = "   -1234ab567";
	
	memset(str, 289, 6);
	printf("The memset result is %s.\n", str);
	ft_memset(str2, 289, 6);
	printf("The ft_memset result is %s.\n", str2);
	return (0);
} */

// bzero()
/* int	main(void)
{
	char	str[] = "561-1234ab567";
	char	str2[] = "561-1234ab567";
	
	printf("The original string is %s.\n", str);
	bzero(str + 3, 6);
	printf("The bzero result is %s.\n", str);
	ft_bzero(str2 + 3, 6);
	printf("The ft_bzero result is %s.\n", str2);
	return (0);
} */

// memcpy()
/* int	main(void)
{
	char	dest[] = "123456789";
	char	dest2[] = "123456789";
	char	src[] = "abcdefghij";
	
	printf("The original string is %s.\n", dest);
	memcpy(dest, src, 5);
	printf("The memcpy result is %s.\n", dest);
	ft_memcpy(dest2, src, 5);
	printf("The ft_bzero result is %s.\n", dest2);
	return (0);
} */

// memmove()
/* int	main(void)
{
	char	dest[] = "123456789";
	int		n = 10;

	write(1, "The dest memory originally has:", 31);
	write(1, dest, n);
	write(1, "\n", 1);
	write(1, "The src memory has:", 19);
	write(1, dest + 5, n);
	write(1, "\n", 1);
	ft_memmove(dest, dest + 5, n);
	write(1, "The dest memory after ft_memmove has:", 37);
	write(1, dest, n);
	write(1, "\n", 1);
	
	// memmove(dest, dest + 5, n);
	// write(1, "The dest memory after memmove has:", 34);
	// write(1, dest, n);
	// write(1, "\n", 1);

	return (0);
} */

// strlcpy()
/* int	main(void)
{
	char		dst[] = "123456789";
	char		src[] = "abcdefghijk";
	size_t		n = 10;

	printf("The original dst string is: %s\n", dst);
	printf("The src string is: %s\n", src);
	ft_strlcpy(dst, src, n);
	printf("The dst string after ft_strlcpy is: %s\n", dst);
	return (0);
} */

// strchr()
/* int	main(void)
{
	const char	s[] = "1234596789";
	char		*ptr;
	char		*ptr2;

	ptr = ft_strchr(s, '9');
	ptr2 = strchr(s, '9');
	if (ptr == ptr2)
		printf("The ft_strchr is correct\n");
	else
		printf("The ft_strchr is incorrect\n");
	return (0);
} */

// strrchr()
/* int	main(void)
{
	const char	s[] = "1234596789";
	char		*ptr;
	char		*ptr2;

	ptr = ft_strrchr(s, '9');
	ptr2 = strrchr(s, '9');
	if (ptr == ptr2)
		printf("The ft_strrchr is correct\n");
	else
		printf("The ft_strrchr is incorrect\n");

	return (0);
} */

// memchr()
// int	main(void)
// {
// 	const char	s[] = "1234596789";
// 	char		*ptr;
// 	char		*ptr2;
// 	int			n = 5;
// 	int			c = 130;

// 	ptr = ft_memchr(s, c, n);
// 	ptr2 = memchr(s, c, n);
// 	if (ptr == ptr2)
// 		printf("The ft_memchr is correct\n");
// 	else
// 		printf("The ft_memchr is incorrect\n");

// 	return (0);
// }
