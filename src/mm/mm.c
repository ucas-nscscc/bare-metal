#include <asm/mysoc.h>
#include <mm.h>

static ulong pmem_base;
static ulong pmem_size;

static struct page_desc *free_pages = NULL;

void mm_init()
{
	struct page_desc *pdesc = NULL;
	void *next_page = NULL;
	arch_mm_init(&pmem_base, &pmem_size);
	pdesc = (struct page_desc *)pmem_base;
	free_pages = pdesc;
	while (1) {
		next_page = (void *)((ulong)pdesc + PAGE_SIZE);
		if ((ulong)next_page >= (pmem_base + pmem_size)) {
			pdesc->next = NULL;
			break;
		}
		pdesc->next = (struct page_desc *)next_page;
		pdesc = (struct page_desc *)next_page;
	}
}

void *alloc_page()
{
	if (free_pages == NULL)
		return NULL;
	void *ret = (void *)free_pages;
	free_pages = free_pages->next;
	return ret;
}

void free_page(void *ptr)
{
	struct page_desc *pdesc = (struct page_desc *)ptr;
	pdesc->next = free_pages;
	free_pages = pdesc;
}
