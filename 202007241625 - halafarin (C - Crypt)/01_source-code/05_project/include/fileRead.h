#define TEST 0

void FileRead(char *fileName){
	FILE* filePointer;
	int bufferLength = 8192;
	char buffer[bufferLength];

	filePointer = fopen(fileName, "r");

	while(fgets(buffer, bufferLength, filePointer)) {
		int *array = (int*)malloc(sizeof(int)*512);
		
		char delimiter[2] = " ";
		char *token;
		token = strtok(buffer,delimiter);

		int i = 0;
		while(token != NULL){
			array[i++] = atoi(token);
			token = strtok(NULL,delimiter);
		}

		int maxEbob = 0;
		struct Node* start = NULL;
		

	    int j;
	    if(TEST){
		    printf("Line : ");
	 		for(j=0; j<i; j++){
	 			printf("%d ",array[j] );
	 		}
	 		printf("\n");
 		}

	    for(j=0; j<i; j++){

	    	if(j==0){
	    		insertEnd(&start, array[0]); 
				continue;
	    	}
	    	if(maxEbob < Ebob(start->data,array[j])){
	    		if(TEST)
	    			printf("-> %d\n",array[j] );
	    		maxEbob = Ebob(start->data,array[j]);
	    		int mod;
	    		if(array[j] > start->data)
	    			mod = array[j] % start->data;
	    		else
	    			mod = start->data % array[j];
	    		if(TEST)
	    			printf("%d %d , ebob = %d ,mod = %d\n",start->data,array[j],Ebob(start->data,array[j]),mod );
	    	
	    		if(mod == 0){
	    			insertAfter(&start,array[j],start->data);
	    			continue;
	    		}
	    		else{
	    			int i=0;
	    			struct Node *temp = start;
	    			while(i++<mod)
	    				temp = temp->prev;
	    			if(temp == start){
	    				insertBegin(&start,array[j]);
	    				continue;
	    			}
	    		}
	    	}
	    	else{
	    		if(TEST)
	    			printf("<- %d\n",array[j] );
	    		struct Node *temp = start;
	    		while(Ebob(temp->data,array[j]) < maxEbob && temp->next != start){
	    			if(TEST)
	    				printf(" %d - %d \n",temp->data,array[j] );
	    			temp = temp->next;
	    		}
	    		int mod;
	    		if(array[j] > temp->data)
	    			mod = array[j] % temp->data;
	    		else
	    			mod = temp->data % array[j];
	    		if(TEST){
	    			printf(" %d %d , ebob = %d ,mod = %d\n",temp->data,array[j],Ebob(temp->data,array[j]),mod );
	    			printf("%d\n",temp->prev->data );
	    		}
	    		int i=0,flag=0;
	    		while(i++<mod){
	    			if(temp == start){
	    				flag =1;
	    				insertBegin(&start,array[j]);
	    				break;
	    			}
	    			temp = temp->prev;
	    		}
	    		if(flag==0)
	    			insertAfter(&temp,array[j],temp->data);
	    	}
	    if(TEST)
	     display(start); 
	    }
	    if(TEST){
		   printf("END");
		   display(start); 
		}
	    ListPrint(start);
	    free(start);
	}

	fclose(filePointer);
} 
