#include <stdlib.h>

typedef int32_t ring_size_t;

struct ring {  
    uint8_t *data;
    ring_size_t size;
    uint32_t begin;
    uint32_t end;
};

#define RING_SIZE(RING)  ((RING)->size - 1)
#define RING_DATA(RING)  (RING)->data
#define RING_EMPTY(RING) ((RING)->begin == (RING)->end)

static void ring_init(struct ring *ring, uint8_t *buf, ring_size_t size){
	ring->data = buf;
	ring->size = size;
	ring->begin = 0;
	ring->end = 0;
}

static int32_t ring_write_ch(struct ring *ring, uint8_t ch){
	if (((ring->end + 1) % ring->size) != ring->begin) {
		ring->data[ring->end++] = ch;
		ring->end %= ring->size;
		return (uint32_t)ch;
	}
	return -1;
}

static int32_t ring_write(struct ring *ring, uint8_t *data, ring_size_t size) {
	int32_t i;

	for (i = 0; i < size; i++) {
		if (ring_write_ch(ring, data[i]) < 0)
			return -i;
	}
	return i;
}
static int32_t ring_read_ch(struct ring *ring, uint8_t *ch) {
	int32_t ret = -1;

	if (ring->begin != ring->end) {
		ret = ring->data[ring->begin++];
		ring->begin %= ring->size;
		if (ch)
			*ch = ret;
	}
	return ret;
}

static int32_t ring_read(struct ring *ring, uint8_t *data, ring_size_t size)
{
	int32_t i;
	for (i = 0; i < size; i++) {
		if (ring_read_ch(ring, data + i) < 0)
			return i;
	}
	return -i;
}