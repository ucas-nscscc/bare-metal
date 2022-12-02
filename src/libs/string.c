#include <types.h>

size_t strlen(const char *s) {
	// assert(s != NULL);
	size_t len = 0;
	while (*s++) {
		len++;
	}
	return len;
}

char *strcpy(char *dst, const char *src) {
	// assert(dst != NULL || src != NULL);
	int i;
	for (i = 0; src[i] != '\0'; i++) {
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
	// assert(dst != NULL || src != NULL);
	int i;
	for (i = 0; i < n && src[i] != '\0'; i++) {
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return dst;
}

char *strcat(char *dst, const char *src) {
	// assert(dst != NULL || src != NULL);
	char *temp = dst;
	while (*temp != '\0') {
		temp++;
	}
	while ((*temp++ = *src++) != '\0') {
		;
	}
	return dst;
}

int strcmp(const char *s1, const char *s2) {
	// assert(s1 != NULL || s2 != NULL);
	while (*s1 == *s2 && *s1 != '\0') {
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
	// assert(s1 != NULL || s2 != NULL);
	while (*s1 == *s2 && *s1 != '\0' && --n) {
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

void *memset(void *s, int c, size_t n) {
	// assert(s != NULL);
	char *mem = s;
	for (int i = 0; i < n; i++)
	{
		mem[i] = c;
	}
	return s;
}

void *memmove(void *dst, const void *src, size_t n) {
	// assert(dst != NULL && src != NULL);
	char* tmp_dest = (char*)dst;
	const char* tmp_src = (const char*)src;

	if (tmp_src < tmp_dest){
		while (n--) {
			*tmp_dest++ = *tmp_src++;
		}    
	} else if (tmp_src > tmp_dest) {
		tmp_src += n - 1;
		tmp_dest += n - 1;
		while (n--) {
			*tmp_dest-- = *tmp_src;
		}
	}
	return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
	// assert(in != NULL && out != NULL);
	char* tmp_out = (char*)out;
	const char* tmp_in = (const char*)in;
	while (n--) {
		*tmp_out++ = *tmp_in++;
	}
	return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
	// assert(s1 != NULL || s2 != NULL);
	while (*(char*)s1 == *(char*)s2 && --n) {
		s1 = (char*)s1 + 1;
		s2 = (char*)s2 + 1;
	}
	return *(char*)s1 - *(char*)s2;
}
