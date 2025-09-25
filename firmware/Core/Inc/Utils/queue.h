/*
 * queue.h
 *
 *  Created on: May 25, 2025
 *      Author: guilh
 */

#ifndef INC_UTILS_QUEUE_H_
#define INC_UTILS_QUEUE_H_

#define QUEUE_SIZE 512

#include <stdint.h> //uint8_t
#include <stddef.h> //size_t

typedef struct queue_s
{
	uint8_t buf[QUEUE_SIZE];	//data buffer
	size_t size; 				//size in bytes
	size_t head; 				//offset in bytes of the next elt to enqueue
	size_t tail;				//offset in bytes of the next elt to dequeue
} queue_t;

#define PQUEUE_EMPTY(q) (q->size == 0)
#define QUEUE_EMPTY(q) (q.size == 0)

typedef void (*overflow_handler_t)(queue_t *q);

/**
  * @brief init the queue
  * @param q is the queue to init
  * @retval none
  */
void queue_init(queue_t *q);
/**
  * @brief enqueue an elt of size elt_size in the queue
  * @param q is the targeted queue
  * @param elt is the element to enqueue (copied)
  * @param size is the size of the element to enqueue
  * @param error_handler is the function called on q in case of overflow (NULLable)
  * @retval 1 if error (overflow or invalid args) 0 otherwise
  */
int queue_enqueue(queue_t *q, void *elt, size_t elt_size, overflow_handler_t error_handler);

/**
  * @brief dequeue an elt of size elt_size from the queue
  * @param q is the targeted queue
  * @param elt is the element to dequeue (copied)
  * @param size is the size of the element to dequeue
  * @retval 1 if error (empty queue or invalid args) 0 otherwise
  */
int queue_dequeue(queue_t *q, void *output, size_t elt_size);

void queue_default_overflow_handler(queue_t* q);

#endif /* INC_UTILS_QUEUE_H_ */
