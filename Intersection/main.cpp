#include "StringSet.h"

int main(int argc, char* argv[])
{
	if (argc != 4) {
		std::cout << "Invalid arguments: "<< std::string(argv[0]) << "\t <set A>\t <set B>\t <set C>\n";
		return -1;
	}
	try {
			StringSet* set1 = new StringSet(std::string(argv[1]));
			StringSet* set2 = new StringSet(std::string(argv[2]));
			StringSet* set3 = new StringSet(std::string(argv[3]));

			std::cout << set1->label() << " size: " << set1->size() << std::endl;
			std::cout << set2->label() << " size: " << set2->size() << std::endl;
			std::cout << set3->label() << " size: " << set3->size() << std::endl;

			std::cout << "Intersection:" << set1->label() << " : " << set2->label() << " -> " << set1->intersection(*set2) << std::endl;
			std::cout << "Intersection:" << set1->label() << " : " << set3->label() << " -> " << set1->intersection(*set3) << std::endl;
			std::cout << "Intersection:" << set1->label() << " : " << set2->label() << " : " << set3->label() << " -> " << set1->intersection(*set2, *set3) << std::endl;
			std::cout << "Intersection:" << set2->label() << " : " << set3->label() << " -> " << set2->intersection(*set3) << std::endl;
	
			std::cout << "Unique Elements of:" << set1->label() << " : " << set1->uniqueElements(*set2, *set3) << std::endl;
			std::cout << "Unique Elements of:" << set2->label() << " : " << set2->uniqueElements(*set1, *set3) << std::endl;
			std::cout << "Unique Elements of:" << set3->label() << " : " << set3->uniqueElements(*set1, *set2) << std::endl;
	}
	catch (...)
	{
		std::cout << "failed\n";
		return -1;
	}




	return 0;

}