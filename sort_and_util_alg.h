//
// Created by Миша Лавринович on 12.10.16.
//

#ifndef METH_PROG_LAB_01_SORT_ALG_H
#define METH_PROG_LAB_01_SORT_ALG_H
#include <vector>

namespace alg {

    /**
     * В векторе vector длинны length воссанавливает свойства пирамиды
     * на поддереве с вершиной с индексом index
     * O(log(length))
     */
    template<class T>
    void ShiftDown(std::vector<T>& vector, long index, long length) {
        long biggest_index = index;
        bool done = false;
        while (((2 * index + 1) < length) && !done) {
            if (vector[biggest_index] < vector[2 * index + 1]) {
                biggest_index = 2 * index + 1;
            }
            if (((2 * index + 2) < length) && (vector[biggest_index] < vector[2 * index + 2])) {
                biggest_index = 2 * index + 2;
            }
            if (biggest_index != index) {
                std::swap(vector[index], vector[biggest_index]);
                index = biggest_index;
            } else {
                done = true;
            }
        }
    }

    /**
     * Сортирует вектор vector по возрастанию пирамидальной сортировкой
     * O(vector.size() * log(vector.size()))
     */
    template<class T>
    void HeapSort(std::vector<T>& vector) {
        long length = vector.size();
        for (int i = 0; i <= vector.size() / 2 - 1; i++) {
            ShiftDown(vector, vector.size() / 2 - i - 1, length);
        }
        for (int i = 0; i < vector.size() - 1; i++) {
            std::swap(vector[0], vector[length - i - 1]);
            ShiftDown(vector, 0, length - i - 1);
        }
    }

    /**
     * Сортирует вектор vector по возрастанию сортировкой выбором
     * O(vector.size() * log(vector.size()))
     */
    template<class T>
    void SelectSort(std::vector<T>& vector) {
        unsigned long min_index;
        for(unsigned long i = 0; i < vector.size() - 1; i++) {
            min_index = i;
            for (unsigned long j = i + 1; j < vector.size(); j++) {
                if(vector[j] < vector[min_index]) {
                    min_index = j;
                }
            }
            std::swap(vector[i], vector[min_index]);
        }
    }


}

namespace util {
    /**
     * Возвращает время выполнения функции f с аргументами args
     */
    template <typename R,typename... Args>
    long long measureTime (R (*f)(Args...), Args&&... args) {
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        start = std::chrono::high_resolution_clock::now();
        f(std::forward<Args>(args)...);
        end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    };

    /**
     * Перегруженный оператор << для вывода вектора vector в поток вывода out
     */
    template <class T>
    std::ostream& operator << (std::ostream& out, const std::vector<T>& vector){
        for(T t: vector){
            out << t << "\n";
        }
        return out;
    }
}



#endif //METH_PROG_LAB_01_SORT_ALG_H
