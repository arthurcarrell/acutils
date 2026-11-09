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

## ac_num.h
Does not require an implementation definition.

Simply just renames number types:<br>
`int32_t` -> `i32`<br>
`uint16_t` -> `u16`<br>
`float` -> `f32`<br>
`double` -> `f64`<br>
 etc...

## ac_vec2.h
Adds Vector2's to C. This **does require an implementation definition.**

Gives maths functions to do stuff like add, divide, scale, compare etc...
This does use the *math.h* library.

At the top of your main.c file / whatever file is called first, put this:
```c
#define AC_VEC2_IMPL
#include "ac_vec2.h"
```
This needs to be **before** any file that uses ac_vec2.h (this includes C files)

```c
#define AC_VEC2_IMPL
#include "ac_vec2.h"

int main(int argc, char** argv) {
    Vec2f vector = VEC2F(2.0f, 5.0f);
    vector = Vec2f_sca(vector, 10);
    printf("Vec2f: x: %f y: %f\n", vector.x, vector.y);

    Vec2 intvec = VEC2(10, 5);
    intvec = Vec2_sca(Vec2_add(intvec, VEC2(10, 5)), 10);
    printf("Vec2: x: %i y: %i\n", intvec.x, intvec.y);
    return 0;
}
```
```
Vec2f: x: 20.000000 y: 50.000000
Vec2: x: 200 y: 100
```