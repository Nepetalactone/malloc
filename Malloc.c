#include <stdio.h>
#include <inttypes.h>

#define MAX_MEMORY_SIZE 10000
#define MAX_HEADER_SIZE 1000

typedef struct {
	uint32_t crc;
	uint32_t len;
	uint16_t flag;
} header;

static header * curMemoryPos;
static char memory[MAX_MEMORY_SIZE];
static header memoryHeader[MAX_HEADER_SIZE];
static uint32_t vIndex = -1;


static void * mem_alloc (int size) {
	header tmp;

	if ((MAX_MEMORY_SIZE - curMemoryPos) < size) {
		/* return null */
	}

	while (vIndex <= MAX_HEADER_SIZE) {

		tmp = memoryHeader[vIndex];

		if (tmp.flag == 0) {
			break;
		}
		vIndex++;
	}

	tmp.len = size;
	tmp.flag = 1;

	memoryHeader[vIndex] = (header) tmp;

	curMemoryPos = curMemoryPos + sizeof(tmp) + size;

}


int main() {
	mem_alloc(1024);
	return 0;
}


void mem_free(void* delBlock) {

}


