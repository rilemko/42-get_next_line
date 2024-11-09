<a id="readme-top" name="readme-top"></a>

<!-- ------------------------------
* TITLE, DESCRIPTION & CONTACT
------------------------------ -->
# 📃 get_next_line

<table>
    <tr>
        <th align="left" width="3333px">Score</th>
        <th align="left" width="3333px">Duration</th>
        <th align="left" width="3333px">Peer(s)</th>
    </tr>
    <tr>
        <td>✅ <b>125</b> / 100</td>
        <td>🕓 2 week(s)</td>
        <td>👷🏻 No</td>
    </tr>
</table>

<br>

This project is a function derived from the `getline` function from the **Standard Library**. It reads one or more file descriptors one line at a time and returns the **next line on each call**. As the buffer size can be specified at compile time, it is important to **keep track** of the previous call for each file descriptor, in case more than one line has been read: **static variables** are then used.

[**⛓️ FILE : SUBJECT**](en.subject.pdf)

<br>

<!-- ------------------------------
* TABLE OF CONTENTS
------------------------------ -->
## 📋 Table of contents

- [**👀 Overview**](#readme-overview)
- [**📦 Requirements**](#readme-requirements)
- [**💾 Installation**](#readme-installation)
- [**⚡️ Usage**](#readme-usage)
- [**🛠️ Makefile**](#readme-makefile)
- [**📄 License**](#readme-license)

<a id="readme-overview" name="readme-overview"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* OVERVIEW
------------------------------ -->
## 👀 Overview

### Features

- Supports reading of any valid file descriptor.
- Supports reading of multiple file descriptors.
- Supports any buffer size if specified at compile time (default is 1).
- Returns the line read, or `NULL` if there is nothing more to read or an error has occurred.

<a id="readme-requirements" name="readme-requirements"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* REQUIREMENTS
------------------------------ -->
## 📦 Requirements

```
sudo apt -y install clang-12 make
```

<a id="readme-installation" name="readme-installation"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* INSTALLATION
------------------------------ -->
## 💾 Installation

**1. Get the project**

```
git clone https://github.com/rilemko/42-get_next_line.git
```

<br>

**2. Build the project**

```
make -j$(nproc) BUFFER_SIZE=42
```

> **🔵 Info:** The `libgnl.a` archive will be created in the project root directory.

> **🟣 Tips:** The `BUFFER_SIZE` argument is optional. It is set to 1 if not specified.

<a id="readme-usage" name="readme-usage"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* USAGE
------------------------------ -->
## ⚡️ Usage

**Single file descriptor:**

```c
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>
#include "includes/get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("A.txt", O_RDONLY); // 5 lines inside, 3rd empty

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
}
```

```console
$ ./a.out
I'm the line #1 from "A.txt"
I'm the line #2 from "A.txt"

I'm the line #4 from "A.txt"
I'm the line #5 from "A.txt"
```

<br>

**Multiple file descriptors:**

```c
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>
#include "includes/get_next_line.h"

int main(void)
{
    int     fds[2];
    char    *line;

    fds[0] = open("A.txt", O_RDONLY); // 2 lines inside
    fds[1] = open("B.txt", O_RDONLY); // 4 lines inside

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            line = get_next_line(fds[j]);
            printf("%s", line);
            free(line);
        }
    }

    close(fds[0]);
    close(fds[1]);
}
```

```console
$ ./a.out
I'm the line #1 from "A.txt"
I'm the line #1 from "B.txt"
I'm the line #2 from "A.txt"
I'm the line #2 from "B.txt"
(null)
I'm the line #3 from "B.txt"
(null)
I'm the line #4 from "B.txt"
```

<a id="readme-makefile" name="readme-makefile"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* MAKEFILE
------------------------------ -->
## 🛠️ Makefile

<table>
    <tr>
        <th align="left" width="500px">Rule</th>
        <th align="left" width="9500px">Action</th>
        </tr>
    <tr><td><code>all</code></td><td>Compile.</td></tr>
    <tr><td><code>clean</code></td><td>Delete all generated object files</td></tr>
    <tr><td><code>fclean</code></td><td>Apply <code>clean</code>, <code>lclean</code> and delete the archive.</td></tr>
    <tr><td><code>lclean</code></td><td>Apply <code>fclean</code> to all used libraries.</td></tr>
    <tr><td><code>re</code></td><td>Apply <code>fclean</code> and force recompile.</td></tr>
</table>

[**⛓️ FILE : MAKEFILE**](Makefile)

<a id="readme-license" name="readme-license"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* LICENSE
------------------------------ -->
## 📄 License

This project is licensed under the terms of the **MIT** license.

[**⛓️ FILE : LICENSE**](LICENSE.md)

<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>
