#include "serializer.h"
#include <iostream>
#include <fstream>
#include <filesystem>

void SaveToFile(const std::string& filename, const std::string& content) {
	std::ofstream file(filename);
	if (!file) {
		std::cerr << "Error: Unable to open file " << filename << " for writing.\n";
		return;
	}
	file << content;
	file.close();
	std::cout << "File successfully saved to: " << std::filesystem::absolute(filename) << "\n";
}

int main() {
	const auto dataName = "data";
	using MyNode = Node<std::map<Key, std::string>, std::vector<std::string>, std::string>;

	auto data = std::map<Key, MyNode>{
	        {"key_to_map", MyNode{std::map<Key, std::string>{{"key1", "value1"}, {"key2", "value2"}}}},
			{"key_to_vector", MyNode{std::vector<std::string>{"string from vector 1", "string from vector 2"}}},
			{"key_to_string", MyNode{"this is a string"}},
		};

	std::string xmlResult = ToXML(dataName, data);
	std::cout << "Here's how this structure looks in XML:\n" << xmlResult << "\n";
	SaveToFile("data.xml", xmlResult);

	std::string jsonResult = ToJSON(dataName, data, INDENT_STEP);
	std::cout << "\nThis is its representation in JSON:\n{\n" << jsonResult << "}\n";
	SaveToFile("data.json", jsonResult);

	std::string yamlResult = ToYAML(dataName, data);
	std::cout << "\nAnd finally, YAML:\n" << yamlResult << "\n";
	SaveToFile("data.yaml", yamlResult);
	return 0;
}
