#include <iostream>
#include <unistd.h>
#include <string>
#include <thread>

void download(std::string file) {
    for (int i = 0; i < 10; i++) {
        std::cout << "Downloading " << file
                  << " (" << i * 10 << "%)..." << std::endl;
        usleep(400000);
    }
    std::cout << "Download complete: " << file << std::endl;
}

void interact() {
    std::string name;
    std::cin >> name;
    std::cout << "Hi, " << name << std::endl;
}

void myfunc() {
    std::thread t1([&] {
        download("hello.zip"); 
    });
    // 退出函数体时，会销毁 t1 线程的句柄！
}

int main() {
    myfunc();
    interact();
    return 0;
}
