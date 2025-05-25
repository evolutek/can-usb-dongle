/*
 * queue.c
 *
 *  Created on: May 25, 2025
 *      Author: guilh
 */

#include "Utils/queue.h"

#include <string.h> //memcpy

int queue_enqueue(queue_t *q, void *elt, size_t elt_size, overflow_handler_t error_handler)
{
	if (q->size + elt_size > QUEUE_SIZE)
	    return 1;

	size_t pos = (q->head) % QUEUE_SIZE;
	size_t end_pos = (pos + elt_size) % QUEUE_SIZE;

	if (end_pos < pos)
	{
		//cut the elt in 2 if not enough space at the end of the queue
	    memcpy(q->buf + pos, elt, QUEUE_SIZE - pos);
	    memcpy(q->buf, (uint8_t*)elt + (QUEUE_SIZE - pos), end_pos);
	}
	else
	    memcpy(q->buf + pos, elt, elt_size);

	q->head = end_pos;
	q->size += elt_size;

	return 0;
}

int queue_dequeue(queue_t *q, void *output, size_t elt_size)
{
	if (q->size < elt_size)
	    return 1;

	size_t pos = q->tail % QUEUE_SIZE;
	size_t end_pos = (pos + elt_size) % QUEUE_SIZE;

	if (end_pos < pos)
	{
		//handle the case where the elt was cut in 2
	    memcpy(output, q->buf + pos, QUEUE_SIZE - pos);
	    memcpy((uint8_t*)output + (QUEUE_SIZE - pos), q->buf, end_pos);
	}
	else
	    memcpy(output, q->buf + pos, elt_size);

	q->tail = end_pos;
	q->size -= elt_size;

	return 0;
}
