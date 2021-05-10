# fileLock
Multiprocess and thread safe file lock class.

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

## Tests
It's possible to create simple test.

```
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <unistd.h>
#include <fileLock/fileLock.hpp>

void testThread() {

    std::string    filename = "test.txt";
    std::string    mode     = "a";
    annm::fileLock file     = annm::fileLock(filename, mode);
    
    if(file.lock()) {
        for(int i = 0; i < 10; i++) {
            fprintf(file.pointer(), "Hello file!\n");
        }
        // sleep(1); /* It's possible to slow down this critical section. */
        file.unlock();
    }

}


int main(void) {

    int n = 10;
    std::vector<std::thread> threads(n);

    for(int i = 0; i < n; i++) {
        threads[i] = std::thread(testThread);
    }

    for(int i = 0; i < n; i++) {
        threads[i].join();
    }

    return 0;

}
```

## License

You can find it in LICENSE file.