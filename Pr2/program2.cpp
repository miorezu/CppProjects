#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

std::map<std::string, std::vector<std::string>> countFileTypes(const std::vector<std::string>& fileNames)
{
    std::map<std::string, std::vector<std::string>> fileGroups;
    for (const auto& file : fileNames)
    {
        size_t dotPos = file.find_last_of('.');
        if (dotPos != std::string::npos)
        {
            std::string extension = file.substr(dotPos + 1);
            fileGroups[extension].push_back(file);
        }
        else
        {
            fileGroups["unknown"].push_back(file);
        }
    }
    return fileGroups;
}

bool runTests()
{
    struct TestCase
    {
        std::vector<std::string> input;
        std::map<std::string, std::vector<std::string>> expectedOutput;
    };
    std::vector<TestCase> testCases = {
        {
            {"fdgdfg.txt", "eewer.doc", "cpp.doc", "uoyouyhjkhu.txt", "tututu.game", "reere.json"},
            {
                {"txt", {"fdgdfg.txt", "uoyouyhjkhu.txt"}},
                {"doc", {"eewer.doc", "cpp.doc"}},
                {"game", {"tututu.game"}},
                {"json", {"reere.json"}}
            }
        },
        {
            {"file1.cpp", "file2.cpp", "file.h", "README", "LICENSE"},
            {
                {"cpp", {"file1.cpp", "file2.cpp"}},
                {"h", {"file.h"}},
                {"unknown", {"README", "LICENSE"}}
            }
        },
        {
            {},
            {}
        }
    };
    bool allTestsPassed = true;
    for (size_t i = 0; i < testCases.size(); ++i)
    {
        const auto& testCase = testCases[i];
        auto result = countFileTypes(testCase.input);

        std::cout << "Test case " << i + 1 << ":\n";
        std::cout << "  Input files: ";
        for (const auto& file : testCase.input)
        {
            std::cout << file << " ";
        }
        std::cout << "\n  Expected groups:\n";

        for (const auto& [extension, files] : testCase.expectedOutput)
        {
            std::cout << "    ." << extension << ": ";
            for (const auto& file : files)
            {
                std::cout << file << " ";
            }
            std::cout << "\n";
        }

        std::cout << "  Actual groups:\n";
        for (const auto& [extension, files] : result)
        {
            std::cout << "    ." << extension << ": ";
            for (const auto& file : files)
            {
                std::cout << file << " ";
            }
            std::cout << "\n";
        }
        bool testPassed = result == testCase.expectedOutput;
        if (testPassed)
        {
            std::cout << "  Result: Test passed!\n\n";
        }
        else
        {
            std::cout << "  Result: Test failed!\n\n";
            allTestsPassed = false;
        }
    }
    return allTestsPassed;
}

void printResults(const std::map<std::string, std::vector<std::string>>& fileGroups)
{
    for (const auto& [extension, files] : fileGroups)
    {
        std::cout << "Files with extension '" << extension << "' (" << files.size() << "):\n";
        for (const auto& file : files)
        {
            std::cout << "  - " << file << '\n';
        }
    }
}

int main(int argc, const char* argv[])
{
    if (runTests())
    {
        std::cout << "All tests passed!\n";
    }
    else
    {
        std::cout << "Some tests failed!\n";
        return 1;
    }

    if (argc < 2)
    {
        std::cout << "No file names provided. Usage: ./program file1.ext file2.ext ...\n";
        return 1;
    }

    std::vector<std::string> fileNames(argv + 1, argv + argc);

    auto fileGroups = countFileTypes(fileNames);

    printResults(fileGroups);
    return 0;
}
