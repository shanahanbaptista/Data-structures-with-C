Queuelist * newQueuelist(){
	Queuelist * ql = malloc(sizeof(Queuelist));
	ql->queuelength = 0;
	ql->data = newList();
	ql->enqueue = enqueueList;
	ql->dequeue = dequeueList;
	ql->peek = peekQueueList;
	ql->clear = clearQueueList;
	ql->delete = deleteQueueList;

	return ql;
}

void enqueueList(Queuelist * q, Data d){
	int index = 0;
	q->data->insert(q->data, index, d);
	q->queuelength++;
}

Data dequeueList(Queuelist * q){
	if(q->queuelength > 0)
	{	
		Data dequeued = q->data->head->data;

		q->data->remove(q->data, 0);
		q->queuelength--;

		return dequeued;
	}
	else
	{
		return (Data){.value = -1};
	}
}

Data peekQueueList(Queuelist * q){
	return q->data->head->data;
}

void clearQueueList(Queuelist * q){
	while(q->queuelength != 0){
		q->data->remove(q->data, 0);
		q->queuelength--;
	}
}

void deleteQueueList(Queuelist * q){
	for(int i = 0; i < q->queuelength; i++){
		q->data->remove(q->data, i);
	}
	q->data->delete(q->data);
	q->data = NULL;
	free(q);
}