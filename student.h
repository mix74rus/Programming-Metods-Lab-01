//
// Created by Миша Лавринович on 11.10.16.
//

#ifndef METH_PROG_LAB_01_STUDENT_H
#define METH_PROG_LAB_01_STUDENT_H

#include <string>

/**
 * Класс с данными о студенте
 */
class Student {
private:
    /**
     * Внутренние private данные класса Student
     */
    std::string full_name;
    std::string faculty;
    std::string specialization;
    double sum;
public:
    Student(){}

    Student(const std::string &full_name, const std::string &faculty, const std::string &specialization, double sum)
            : full_name(full_name), faculty(faculty), specialization(specialization), sum(sum) {}

    /**
     * Перегруженые операторы сравнения
     */
    bool operator < (const Student& other) const {
        return  sum == other.sum ? full_name < other.full_name : sum > other.sum;
    }

    bool  operator == (const Student& other) const {
        return  (sum == other.sum) && (full_name == other.full_name);
    }

    bool operator <= (const Student& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator > (const Student& other) const {
        return  !(*this <= other);
    }

    bool  operator >= (const Student& other) const {
        return !(*this < other);
    }
    /**********************************************/

    /**
     * Сеттеры и геттеры для private данных класса
     */
    const std::string& getFull_name() const {
        return full_name;
    }

    void setFull_name(const std::string &full_name) {
        Student::full_name = full_name;
    }

    const std::string& getFaculty() const {
        return faculty;
    }

    void setFaculty(const std::string &faculty) {
        Student::faculty = faculty;
    }

    const std::string& getSpecialization() const {
        return specialization;
    }

    void setSpecialization(const std::string &specialization) {
        Student::specialization = specialization;
    }

    double getSum() const {
        return sum;
    }

    void setSum(double sum) {
        Student::sum = sum;
    }
    /**********************************************/

};

/**
 * Операторы ввода/вывода экземпляра класса Student в поток
 */
std::ostream& operator << (std::ostream& out, const Student& student) {
    out << student.getFull_name() << "\n"
        << student.getFaculty() << "\n"
        << student.getSpecialization() << "\n"
        << student.getSum() << "\n";
    return out;
}

std::istream& operator >> (std::istream& in, Student& student) {
    std::string first_name;
    std::string last_name;
    std::string faculty;
    std::string specialization;
    double sum;
    in >> first_name >> last_name >> faculty >> specialization >> sum;
    student.setFull_name(first_name + " " + last_name);
    student.setFaculty(faculty);
    student.setSpecialization(specialization);
    student.setSum(sum);
    return in;
}
/**********************************************/

#endif //METH_PROG_LAB_01_STUDENT_H
