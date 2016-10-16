#ifndef METH_PROG_LAB_01_GENERATOR_H
#define METH_PROG_LAB_01_GENERATOR_H
#include <vector>
#include <ostream>
#include <random>
#include <iomanip>

/**
 * Генератор данных о студентах
 */
class Generator {
public:

    /**
     * Метод генерации n даныых о студентах с выводом в поток out
     */
    void generate(long n, std::ostream& out) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 1);
        out << std::setprecision(2);
        out.seekp(0);

        out << n << "\n";
        for (int i = 0; i < n; i++) {
            out << first_names[trunc(dis(gen)*first_names.size())] << " ";
            out << last_names[trunc(dis(gen)*last_names.size())] << "\n";
            out << faculty[trunc(dis(gen)*faculty.size())] << "\n";
            out << specialization[trunc(dis(gen)*specialization.size())] << "\n";
            out << dis(gen) * 100 << "\n";
        }
    }

private:

    /**
     * Список имён для генерации
     */
    std::vector<std::string> first_names = {
            "Emma",	"Noah",
            "Olivia", "Liam",
            "Sophia",	"Mason",
            "Ava",	"Jacob",
            "Isabella",	"William",
            "Mia",	"Ethan",
            "Abigail",	"James",
            "Emily",	"Alexander",
            "Charlotte",	"Michael",
            "Harper",	"Benjamin",
            "Madison",	"Elijah",
            "Amelia",	"Daniel",
            "Elizabeth",	"Aiden",
            "Sofia",	"Logan",
            "Evelyn",	"Matthew",
            "Avery",	"Lucas",
            "Chloe",	"Jackson",
            "Ella",	"David",
            "Grace",	"Oliver",
            "Victoria",	"Jayden",
            "Aubrey",	"Joseph",
            "Scarlett",	"Gabriel",
            "Zoey",	"Samuel",
            "Addison",	"Carter",
            "Lily",	"Anthony",
            "Lillian",	"John",
            "Natalie",	"Dylan",
            "Hannah",	"Luke",
            "Aria",	"Henry",
            "Layla",	"Andrew",
            "Brooklyn",	"Isaac",
            "Alexa",	"Christopher",
            "Zoe",	"Joshua",
            "Penelope",	"Wyatt",
            "Riley",	"Sebastian",
            "Leah",	"Owen",
            "Audrey",	"Caleb",
            "Savannah",	"Nathan",
            "Allison",	"Ryan",
            "Samantha",	"Jack",
            "Nora",	"Hunter",
            "Skylar",	"Levi",
            "Camila",	"Christian",
            "Anna",	"Jaxon",
            "Paisley",	"Julian",
            "Ariana",	"Landon",
            "Ellie",	"Grayson",
            "Aaliyah",	"Jonathan",
            "Claire",	"Isaiah",
            "Violet",	"Charles"
    };
    /**
     * Список фамилий для генерации
     */
    std::vector<std::string> last_names = {
            "Smith",
            "Johnson",
            "Williams",
            "Jones",
            "Brown",
            "Davis",
            "Miller",
            "Wilson",
            "Moore",
            "Taylor",
            "Anderson",
            "Thomas",
            "Jackson",
            "White",
            "Harris",
            "Martin",
            "Thompson",
            "Garcia",
            "Martinez",
            "Robinson",
            "Clark",
            "Rodriguez",
            "Lewis",
            "Lee",
            "Walker",
            "Hall",
            "Allen",
            "Young",
            "Hernandez",
            "King",
            "Wright",
            "Lopez",
            "Hill",
            "Scott",
            "Green",
            "Adams",
            "Baker",
            "Gonzalez",
            "Nelson",
            "Carter",
            "Mitchell",
            "Perez",
            "Roberts",
            "Turner",
            "Phillips",
            "Campbell",
            "Parker",
            "Evans",
            "Edwards",
            "Collins"
    };
    /**
     * Список факультетов для генерации
     */
    std::vector<std::string> faculty = {
            "ENGINEERING",
            "BIOLOGY",
            "PHYSICS",
            "COMPUTER_SCIENCE",
            "MATHEMATICS",
            "LAW",
            "CHEMISTRY"
    };
    /**
     * Список специальностей для генерации
     */
    std::vector<std::string> specialization = {
        "Office_manager",
        "Sales_Manager",
        "Accountant",
        "Sales_person",
        "Chief_accountant",
        "Economist",
        "Lawyer",
        "PC_operator",
        "Manager_of_work_with_clients",
        "Commercial",
    };
};

#endif //METH_PROG_LAB_01_GENERATOR_H
