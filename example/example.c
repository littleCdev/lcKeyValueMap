#include <stdlib.h>
#include <stdio.h>

#include "../src/lcKeyValueMap.h"

int main(int argc, char *argv[]) {
	
int i = 0;
	
	// create a new KeyValueMap
	kvMapStringString kv = kvInitStringString();
	
	// add values
	i = kvSetStringString(&kv,"test","123345");
	if(i == 1) printf("added new value\n");else if(i == 2)printf("replaced value\n");
	i = kvSetStringString(&kv,"test1","1");	
	if(i == 1) printf("added new value\n");else if(i == 2)printf("replaced value\n");
	i = kvSetStringString(&kv,"test2","12");
	if(i == 1) printf("added new value\n");else if(i == 2)printf("replaced value\n");
	// or overwrite them
	i = kvSetStringString(&kv,"test1","123");
	if(i == 1) printf("added new value\n");else if(i == 2)printf("replaced value\n");
	
	
	// get a value
	char *s = kvGetStringString(&kv,"test");
	printf("key: test: %s\n",s);
	// non existing values will return NULL
	s = kvGetStringString(&kv,"test123");
	printf("key: test123: %s\n",s);

	// dump all keys/values
	kvDump(&kv);

	// unset a value
	printf("removing \"test\"\n");
	kvUnsetStringString(&kv,"test");
	kvDump(&kv);	
	s = kvGetStringString(&kv,"test");
	printf("key: test: %s\n",s);
		
	s = kvGetStringString(&kv,"test123");
	printf("key: test123: %s\n",s);
	

	// deinit
	kvDeinitStringString(&kv);
	
	return 0;
}
