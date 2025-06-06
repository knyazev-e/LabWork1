/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork 1 */

#include "../Image.h"
#include <iostream>
#include <gtest/gtest.h>
#include <thread>

TEST (ImageTests, ClockwiseRotation) {
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
    job1();
}

TEST (ImageTests, CounterClockwiseRotation) {
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
    job2();
}

TEST (ImageTests, GaussianBlur) {
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
    job3();
}

TEST(ImageTests, ThreadTest) {
    std::thread t1([]() {
        Image pic;
        if (!pic.readFile("input.bmp")) {
            std::cerr << "Could not read input.bmp in job3\n";
            return;
        }
        pic.rotateClockwise();
        if (!pic.writeFile("gaussian.bmp")) {
            std::cerr << "Could not save gaussian.bmp\n";
        }
    });
    t1.join();
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
