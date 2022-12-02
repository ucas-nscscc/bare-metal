#ifndef _MM_H
#define _MM_H

#define PAGE_SIZE	(0x1 << 12)

struct page_desc {
	struct page_desc *next;
};

void mm_init();
void *alloc_page();
void free_page(void *ptr);

#endif
