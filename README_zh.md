开源代码清单



#### 1.处理独立 asio 和 Simple-Web-Server 编译的情况

在获取 Simple-Web-Server 源代码后需要修改其文件 asio_compatibility.hpp 中的代码

```cpp
#ifndef SIMPLE_WEB_ASIO_COMPATIBILITY_HPP
#define SIMPLE_WEB_ASIO_COMPATIBILITY_HPP

#include <memory>

#ifdef USE_STANDALONE_ASIO
#include <asio.hpp>
// ......
```

修改为

```cpp
#ifndef SIMPLE_WEB_ASIO_COMPATIBILITY_HPP
#define SIMPLE_WEB_ASIO_COMPATIBILITY_HPP

#include <memory>
#define USE_STANDALONE_ASIO 1 // line 5 , add
#ifdef USE_STANDALONE_ASIO
#include <asio.hpp>
// ......
```

目的是使用独立的asio库而不是boost



#### 2.处理修改 Simple-Web-Server 编译文件后的提交问题

直接在拉取代码后，修改源码之前删除 Simple-Web-Server 目录下的 .git 目录



