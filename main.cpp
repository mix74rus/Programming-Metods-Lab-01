#include <iostream>
#include <fstream>
#include "generator.h"
#include "student.h"
#include "sort_and_util_alg.h"


int main() {
    int n = 100;
    int size = 0;
    Generator g;
    Student student;
    std::fstream file("list.txt", std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    std::istream &in = file;
    std::vector<Student> students1;
    std::vector<Student> students2;

    g.generate(n, file);

    in.seekg(0);
    in >> size;
    for (int i = 0; (i < size) && in; i++) {
        in >> student;
        students1.push_back(student);
        students2.push_back(student);
    }
    if (!in) {
        std::cerr << "Error!\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "SelectSort: "
              << util::measureTime(alg::SelectSort<Student>,students1)
              << "\n"
              << "HeapSort: "
              << util::measureTime(alg::HeapSort<Student>, students2)
              << "\n" << std::boolalpha << (students1 == students2) << "\n";


    return 0;
}