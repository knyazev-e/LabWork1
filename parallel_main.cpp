/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork 1 */

#include "Image.h"
#include <iostream>
#include <thread>

int main() {
    auto job1 = [](){
        Image pic;
        if (!pic.readFile("input.bmp")) {
            std::cerr << "Could not read input.bmp in job1\n";
            return;
        }
        pic.rotateClockwise();
        if (!pic.writeFile("clockwise.bmp")) {
            std::cerr << "Could not save clockwise.bmp\n";
        }
    };

    auto job2 = [](){
        Image pic;
        if (!pic.readFile("input.bmp")) {
            std::cerr << "Could not read input.bmp in job2\n";
            return;
        }
        pic.rotateCounterClockwise();
        if (!pic.writeFile("counterclockwise.bmp")) {
            std::cerr << "Could not save counterclockwise.bmp\n";
        }
    };

    auto job3 = [](){
        Image pic;
        if (!pic.readFile("input.bmp")) {
            std::cerr << "Could not read input.bmp in job3\n";
            return;
        }
        pic.gaussianBlur();
        if (!pic.writeFile("gaussian.bmp")) {
            std::cerr << "Could not save gaussian.bmp\n";
        }
    };

    std::thread t1(job1);
    std::thread t2(job2);
    std::thread t3(job3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
