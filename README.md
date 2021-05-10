# fileLock
Multiprocess and thread safe File lock class.

## Compability
`fileLock` is compatible with all OS what contains `#include <sys/file.h>` and `#include <unistd.h>`

## Usage

```
std::string    filename = "file.txt";
std::string    mode = "a";
annm::fileLock file = annm::fileLock(filename, mode);

file.lock();
fprintf(file.pointer(), "Hello file!");
file.unlock();
```

## License

You can find it in LICENSE file.