Stacklist * newStacklist(){
	Stacklist * sl = malloc(sizeof(Stacklist));
	sl->stacklength = 0;
	sl->data = newList();
	sl->push = pushStackList;
	sl->pop = popStackList;
	sl->peek = peekStackList;
	sl->clear = clearStackList;
	sl->delete = deleteStackList;

	return sl;
}

void pushStackList(Stacklist * s, Data d){
	int index = 0;
	s->data->insert(s->data, index, d);
	s->stacklength++;
}

Data popStackList(Stacklist * s){
	if(s->stacklength > 0)
	{	
		Data popped = s->data->tail->data;

		s->data->remove(s->data, s->stacklength-1);
		s->stacklength--;

		return popped;
	}
	else
	{
		return (Data){.value = -1};
	}
}

Data peekStackList(Stacklist * s){
	return s->data->tail->data;
}

void clearStackList(Stacklist * s){
	while(s->stacklength != 0){
		s->data->remove(s->data, s->stacklength-1);
		s->stacklength--;
	}
}

void deleteStackList(Stacklist * s){
	for(int i = 0; i < s->stacklength; i++){
		s->data->remove(s->data, i);
	}
	s->data->delete(s->data);
	s->data = NULL;
	free(s);
}