# VecGui
Vector based header only GUI library. Targets either pure sdl `sdl_vgui_context.h` or nanovg `nanovg_vgui_context.h`. Supports reflection with [sttr](https://github.com/SnapperTT/sttr).

See `src/example.lzz` for how to implement. Depends on [sdl-stb-font](https://github.com/SnapperTT/sdl-stb-font) for font rendering

```sh
git clone https://github.com/SnapperTT/vecgui
cd vecgui
git clone https://github.com/SnapperTT/sdl-stb-font
# To build example:
./build.sh
```

*Please note that this is here for a personal project this may be one day usuable but no guarantees.*


## Editing
Requires [lzz2](https://github.com/mjspncr/lzz3) ([binary mirror](https://github.com/SnapperTT/lzz-bin))


## Usage
In headers:

```C++
// Include the header
#include "vgui.h"
#include "sdl_vgui_context.h" // or nanovg
```

and in ONE implementation (.cpp) file:
```C++
#define VECGUI_IMPL 1
#include "vgui.h"
#include "sdl_vgui_context.h" // or nanovg
```


## Settings
Redefine the following macros to change:

* `VGUI_DO_DELTA_DRAWING`: Only draw 
* `VGUI_USE_INT`: Use int as coordinates
* `VGUI_USE_DOUBLE`: Use double as coordinates 
* `VGUI_STRING`: Defaults to std::string
* `VGUI_VECTOR`: Defaults to std::vector
* `VGUI_NEW(X)`: Defaults to `new (X)`, replace to use your custom allocator
* `VGUI_DEL(X)`: Defaults to `delete (X)`, replace to use your custom allocator
