# Arthur Carrell Utils

General purpose C header files will go here, these are able to be copy pasted into any project, and will not have any conflicts.

An implementation will need to be defined in order to use the functions/structs provided in these util files.

All header definitions go along the lines of `AC_(NAME)_H` and to define the implementations, it is `#define AC_(NAME)_IMPL`

My naming convention is `snake_case`, so expect functions to be using that. Macros use `SCREAMING_SNAKE_CASE`

## ac_log.h
Does not require an implementation definition.

Simple logger that can take unlimited args and works the same as printf, but also displays information such as the level of logging, the file and the line.

```c
#include "ac_log.h"

int main(int argc, char** argv) {
    LOG_INFO("Hello, World!");
    LOG_WARN("Something aint right");
    LOG_ERR("Something is very wrong!");
    return 0;
}
```
```
(src/main.c:5)[INFO]: Hello, World!
(src/main.c:6)[WARN]: Something aint right
(src/main.c:7)[ERROR]: Something is very wrong!
```