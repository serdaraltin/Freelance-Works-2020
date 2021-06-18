void fileIn(char namefile[20]){
	FILE* fpoin;
	int buflengt = 8000;
	char buf[buflengt];

	fpoin = fopen(namefile, "r");

	while(fgets(buf, buflengt, fpoin)) {
		int *arr = (int*)malloc(sizeof(int)*512);
		
		char spchar[2] = " ";
		char *tkn;
		tkn = strtok(buf,spchar);

		int i = 0;
		while(tkn != NULL){
			arr[i++] = atoi(tkn);
			tkn = strtok(NULL,spchar);
		}

		int mxc = 0;
		struct nod* first = NULL;
		
	    int j;

	    for(j=0; j<i; j++){

	    	if(j==0){
	    		end(&first, arr[0]); 
				continue;
	    	}

	    	if(mxc < Ebob(first->num,arr[j])){

	    		mxc = Ebob(first->num,arr[j]);

	    		int md;
	    		if(arr[j] > first->num)
	    			md = arr[j] % first->num;
	    		else
	    			md = first->num % arr[j];
	    		
	    		if(md == 0){
	    			aft(&first,arr[j],first->num);
	    			continue;
	    		}
	    		else{
	    			int i=0;
	    			struct nod *temp = first;
	    			while(i++<md)
	    				temp = temp->right;
	    			if(temp == first){
	    				beg(&first,arr[j]);
	    				continue;
	    			}
	    		}
	    	}
	    	else{
	    		
	    		struct nod *temp = first;
	    		while(Ebob(temp->num,arr[j]) < mxc && temp->left != first){
	    			temp = temp->left;
	    		}
	    		int md;
	    		if(arr[j] > temp->num)
	    			md = arr[j] % temp->num;
	    		else
	    			md = temp->num % arr[j];
	    		
	    		int i=0,flag=0;
	    		while(i++<md){
	    			if(temp == first){
	    				flag =1;
	    				beg(&first,arr[j]);
	    				break;
	    			}
	    			temp = temp->right;
	    		}
	    		if(flag==0)
	    			aft(&temp,arr[j],temp->num);
	    	}
	    }
	    printDLs(first);
	}
	fclose(fpoin);
} 

