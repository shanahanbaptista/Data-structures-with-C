#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queuelist
{
	int queuelength;
	List * data;
	void (*enqueue)(struct Queuelist *, Data);
	Data (*dequeue)(struct Queuelist *);
	Data (*peek)(struct Queuelist *);
	void (*clear)(struct Queuelist *);
	void (*delete)(struct Queuelist * q);
}Queuelist;


void enqueueList(struct Queuelist *, Data);
Data dequeueList(struct Queuelist *);
Data peekQueueList(struct Queuelist *);
void clearQueueList(struct Queuelist *);
void deleteQueueList(struct Queuelist *);

#endif