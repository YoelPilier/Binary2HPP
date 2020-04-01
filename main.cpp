#include"Bin2HPP.hpp"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Type: bin2hpp  filename.ext1"\
			"filename.ext2 filename.ext3....  " << std::endl;
	}
	else {
		for (int i = 1; i < argc; i++)
			GenerateHPPFile(argv[i]);
	}

	return EXIT_SUCCESS;
}
//------