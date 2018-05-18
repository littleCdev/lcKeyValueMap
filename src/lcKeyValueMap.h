#ifndef _lcKeyValueMap
#define _lcKeyValueMap

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	char *key;
	char *value;
} kvStringString;

typedef struct {
	int		length;
	kvStringString **kv;
} kvMapStringString;



void kvDump(kvMapStringString *kv);
kvMapStringString kvInitStringString();
void kvDeinitStringString(kvMapStringString *kvMap);
char *kvGetStringString(kvMapStringString *kvMap,char *key);
int kvUnsetStringString(kvMapStringString *kvMap,char *key);
int kvSetStringString(kvMapStringString *kvMap,char *key, char *value);


#endif
