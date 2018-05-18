# Small Key-Value map for C
lcKeyValueMap is a small libary that can store variable amounts of strings by name (call it associative array, dictionary key value map)
### Requierements
* nothing but gcc

### Useage 
include the header 
```c
#include "src/lcKeyValueMap.h"
```

create a new key value map
```c
kvMapStringString kv = kvInitStringString();
```

add stuff to it!
```c
kvSetStringString(&kv,"test","123345");
// add a second value
kvSetStringString(&kv,"test1","test2");

// overwrite values
kvSetStringString(&kv,"test","replaced test");
```

or remove stuff
```c
kvUnsetStringString(&kv,"test1");
```

and get the values back
```c
char *s = kvGetStringString(&kv,"test");
printf("key: test: %s\n",s);
// non existing values will return NULL
s = kvGetStringString(&kv,"test123"); // NULL
printf("key: test123: %s\n",s);
```

but don't forget to deinit after you're done
```c
kvDeinitStringString(&kv);
```
