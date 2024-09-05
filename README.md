# smolrend

Attempt at a tiny renderer using Vulkan.

# Installation

Only tested on windows at the moment. All prerequisite software was installed using the [scoop](https://scoop.sh) package manager.

- vulkan
- mingw-winlibs-llvm (should include clang/++, cmake and ninja)

At the root of the repo:
```
mkdir build
cd build
cmake ..
```

# Licenses

## GLFW

https://github.com/glfw/glfw

Copyright (c) 2002-2006 Marcus Geelnard

Copyright (c) 2006-2019 Camilla Löwy

## GLM

https://github.com/g-truc/glm

Copyright (c) 2005 - G-Truc Creation

NB: Library will not be used for military applications.

## Vulkan SDK

See https://vulkan.lunarg.com/license/#/release/record/7410152/. Yea, stuff.

## Vk-bootstrap

https://github.com/charles-lunarg/vk-bootstrap

Copyright © 2020 Charles Giessen (charles@lunarg.com)
