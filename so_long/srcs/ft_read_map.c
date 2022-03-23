#include "../includes/so_long.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char *ft_get_file(int fd, int len, int size)
{
    char    buff[2048];
    char    *value;
    char    *tmp;

    value = malloc(sizeof(char));//null vericeğimiz için tek karakter açıyoruz.
    if(!value)
        return (0);
    len = read(fd, buff, 2048);// max byte ile mapi okuyor,
    while (len > 0)
    {
        tmp = malloc((size + len + 1 ) * sizeof(char));
        if(!tmp)
            break;
        tmp = ft_strncpy(tmp, value, len);//daha önce value tmp'ye eşitlendi ise value'yi tmp'ye kopyalıyor,
        free(value);
        ft_strncpy(tmp + size, buff, len);//tmp'nin size'ıncı indisinden sonraki kısma buff'ı yazıyor.
        value = tmp;
        size += len;
        value[size] = '0';
        len = read(fd, buff, 2048);
    }
    if(len)
        free(value);
    return (value);
}