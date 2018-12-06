#ifndef STACK_H
#define STACK_H

/*typedef struct Data{
	double value;
}Data;

typedef struct Node{
	Data data;
	struct Node * next, * prev;
}Node;

typedef struct List{
	Node * head, * tail;
	void (*insert)(struct List *, int index, Data d);
	Data *(*read)(struct List *, int index);
	void (*remove)(struct List *, int index);
	void (*delete)(struct List *);
}List;*/

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