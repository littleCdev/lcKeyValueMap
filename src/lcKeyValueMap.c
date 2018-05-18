#include "lcKeyValueMap.h"

void kvDump(kvMapStringString *kv){
	int i=0;
	printf("---dump----\n");
	for(i=0;i<kv->length;i++){
		printf("%i: %s\t\t%s\n",i,kv->kv[i]->key,kv->kv[i]->value);
	}
	printf("---/dump---\n");
}

kvMapStringString kvInitStringString(){
	kvMapStringString kv = {
		.length = 0,
		.kv = NULL
	};
	return kv;
}

void kvDeinitStringString(kvMapStringString *kvMap){
	int i = 0;
	
	if(kvMap->kv == NULL)
		return;
		
	for(i=0; i<kvMap->length;i++){
		free(kvMap->kv[i]->key);
		free(kvMap->kv[i]->value);
		free(kvMap->kv[i]);
	}
	
	free(kvMap->kv);
	kvMap->length = 0;
	kvMap->kv = NULL;
	
	return;
}

char *kvGetStringString(kvMapStringString *kvMap,char *key){
	if(kvMap->length == 0)
		return NULL;
		
	int i = 0;
	
	for(i=0; i<kvMap->length;i++){
		if(strcmp(key,kvMap->kv[i]->key) == 0)
			return kvMap->kv[i]->value;
	}
	
	return NULL;	
}

int kvUnsetStringString(kvMapStringString *kvMap,char *key){
	if(kvMap->length == 0)
		return 0;
		
	int i = 0;
	int iPos = -1;
	
	for(i=0; i<kvMap->length;i++){
		if(strcmp(key,kvMap->kv[i]->key) == 0){
			iPos = i;
			break;
		}
	}
	
	if(iPos == -1)
		return 0;
	
	// free position of the actual key
	free(kvMap->kv[iPos]->key);
	free(kvMap->kv[iPos]->value);
	
	if(iPos+1 == kvMap->length){
		free(kvMap->kv[iPos]);
		return 1;
	}
	
	// copy last postion to current and delete last
	int iLastPos = kvMap->length-1;
	
	kvMap->kv[iPos]->key = kvMap->kv[iLastPos]->key;
	kvMap->kv[iPos]->value = kvMap->kv[iLastPos]->value;
	
	free(kvMap->kv[iLastPos]);
	
	kvMap->length--;
	
	kvMap->kv = realloc(kvMap->kv,(kvMap->length+1)*sizeof(kvStringString *));
	
	return 1;	
}


/**
	@return 1 	new values added
	@return	2 	value overwritten
**/
int kvSetStringString(kvMapStringString *kvMap,char *key, char *value){
	int i = 0;
	int iPos = -1;
	
	for(i=0;i<kvMap->length;i++){
		if(strcmp(key,kvMap->kv[i]->key) == 0){
			iPos = i;
			break;
		}		
	}
	
	if(kvMap->length == 0)
		kvMap->kv = malloc(sizeof(kvStringString *));
	
	if(iPos != -1){
		free(kvMap->kv[iPos]->value);
		kvMap->kv[iPos]->value = malloc(strlen(value)+1);
		memset(kvMap->kv[iPos]->value,'\0',strlen(value)+1);
		strcpy(kvMap->kv[iPos]->value,value);
		
		return 2;
	}else{
		
		kvMap->kv = realloc(kvMap->kv,(kvMap->length+1)*sizeof(kvStringString *));
		kvMap->length++;
		
		kvMap->kv[kvMap->length-1]	= malloc(sizeof(kvStringString));
		
		kvMap->kv[kvMap->length-1]->key = malloc(strlen(key)+1);
		kvMap->kv[kvMap->length-1]->value = malloc(strlen(value)+1);
		
		strcpy(kvMap->kv[kvMap->length-1]->key,key);
		strcpy(kvMap->kv[kvMap->length-1]->value,value);
		
		return 1;		
	}	
}

