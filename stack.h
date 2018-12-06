#ifndef STACK_H
#define STACK_H

typedef struct Stacklist
{
	int stacklength;
	List * data;
	void (*push)(struct Stacklist *, Data);
	Data (*pop)(struct Stacklist *);
	Data (*peek)(struct Stacklist *);
	void (*clear)(struct Stacklist *);
	void (*delete)(struct Stacklist *);
}Stacklist;

void pushStackList(struct Stacklist *, Data);
Data popStackList(struct Stacklist *);
Data peekStackList(struct Stacklist *);
void clearStackList(struct Stacklist *);
void deleteStackList(struct Stacklist *);

#endif