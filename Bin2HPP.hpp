#pragma once
#ifndef BIN2HPP_HPP_
#define BIN2HPP_HPP_

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
//----------------------------
//-----------------------------
const std::string SplitName(const std::string& filename) {
	std::stringstream temp;
	for (const auto& i : filename)
	{
		if (i == '.')break;
		temp << i;
	}
	return temp.str().c_str();
}

const static void	GenerateHPPFile(
	const std::string& Filename) {
	// Open file  as binary
	std::fstream filein;
	filein.open(Filename, std::ios::in | std::ios::binary);

	if (not filein.is_open()) {
		std::cerr << "File Not open" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	//----------------------------------
	const	auto Name = SplitName(Filename);

	filein.seekg(0, filein.end);
	auto size = filein.tellg();
	filein.seekg(0, filein.beg);

	auto load_data = new char[size];
	filein.read(load_data, size);
	filein.close();
	//------------------------
	std::ofstream file_out;
	file_out.open(Name + ".hpp", std::ios::out);
	file_out << "namespace resourcesNS{" << std::endl;
	file_out << "const int " << Name << "size = " << size << ";" << std::endl;
	file_out << " const unsigned char " << Name << "[] ={" << std::endl;
	for (int i = 0; i < size; i++) {
		file_out << "0x" << std::hex << static_cast<int>(load_data[i] & 0xff) << ",";
		if (not (i % 10) and i > 0)file_out << std::endl;
	}
	file_out << "};" << std::endl << "}";
	std::cout << std::endl << "Exit Success" << std::endl;

	delete[] load_data;
}

#endif // !BIN2HPP_HPP_