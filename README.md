# ecu-logic

A platform‑agnostic way to share common logic across multiple controllers.

## Getting Started

These instructions assume you have a C/C++ compiler installed.

1. Installing [Meson](https://mesonbuild.com/Getting-meson.html) this assumes that you have [Python 3](https://www.python.org/) installed. _A sidenote: using a tool such as [pipx](https://github.com/pypa/pipx) simplifies this process a lot by just being able to run `pipx install meson` globally._
2. [Ninja](https://ninja-build.org/) – this is the build tool that is going to be used to actually compile the code. It’s a lot like [GNU Make](https://www.gnu.org/software/make/) but not quite.
3. [VSCode](https://code.visualstudio.com/) – assuming that you have no editor set up. If you have one such as [Visual Studio](https://visualstudio.microsoft.com/), you can read the Meson docs for generating the proper build scripts for those tools.
4. :tada: Now the fun part: installing extensions in [VSCode](https://code.visualstudio.com/)!
   - [Meson](https://marketplace.visualstudio.com/items?itemName=mesonbuild.mesonbuild) – this extension gives support for **syntax** highlighting and a nice place to build and test the project.
   - [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd) – this extension will allow for the **IntelliSense** that we are all used to.
     _Another sidenote: if IntelliSense isn’t working out of the box, you may need to run `ln -s builddir/compile_commands.json compile_commands.json` in the project’s root directory so that clangd can locate the generated compile‑commands file._
5. `meson setup builddir`  
   This will now find the installed compiler on your system and download the required **dependencies**.
6. Compiling the project is as simple as:

   ```bash
   cd builddir && meson compile
   ```

   which will then produce the build.

## Running Tests with Meson

:wrench: Meson makes it easy to build and run your test suite:

```bash
meson test -C builddir
```

### Writing Tests with GooglTest

To write and integrate tests using [GoogleTest](https://github.com/google/googletest) framework:

1. Create a test source file, e.g `test_easing_strategy.cpp`:

```cpp
#include <gtest/gtest.h>

// This is required when importing C source files.
extern "C" {
#include "easing_out_cubic.h"
#include "easing_out_sin.h"
#include "easing_strategy.h"
}

TEST_F(EasingStrategyTest, EasingStrategyFunctionPointer) {
  EasingStrategy sine_strategy = ease_out_sine;
  EasingStrategy cubic_strategy = ease_out_cubic;

  EXPECT_NEAR(0.0, sine_strategy(0, 100), EPSILON);
  EXPECT_NEAR(1.0, sine_strategy(100, 100), EPSILON);

  EXPECT_NEAR(0.0, cubic_strategy(0, 100), EPSILON);
  EXPECT_NEAR(1.0, cubic_strategy(100, 100), EPSILON);

  EXPECT_NE(sine_strategy(50, 100), cubic_strategy(50, 100));
}
```

2. Add the test to the `test/meson.build`:

```python
test_project_sources = [
    'test_easing_strategy.cpp', # Now just append the file to this list
]
```

3. :shipit: Running the test is now as simple as:

```bash
meson test -C builddir
```

Meson will compile your test executable and automatically run it, reporting the results in the terminal.
