#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void createClassFiles(const std::string& className) {
    std::string upperClassName = className;
    std::transform(upperClassName.begin(), upperClassName.end(), upperClassName.begin(), ::toupper);

    std::string headerContent = 
        "#ifndef " + upperClassName + "_HPP\n" +
        "#define " + upperClassName + "_HPP\n\n" +
        "class " + className + " {\n" +
        "public:\n" +
        "    " + className + "();\n" +
        "    ~" + className + "();\n\n" +
        "    // Add public members and methods here\n\n" +
        "private:\n" +
        "    // Add private members here\n" +
        "};\n\n" +
        "#endif // " + upperClassName + "_HPP\n";

    std::string cppContent = 
        "#include \"" + className + ".hpp\"\n\n" +
        className + "::" + className + "() {\n" +
        "    // Constructor implementation\n" +
        "}\n\n" +
        className + "::~" + className + "() {\n" +
        "    // Destructor implementation\n" +
        "}\n\n" +
        "// Implement other methods here\n";

    std::ofstream headerFile(className + ".hpp");
    if (headerFile.is_open()) {
        headerFile << headerContent;
        headerFile.close();
    } else {
        std::cerr << "Error creating header file." << std::endl;
        return;
    }

    std::ofstream cppFile(className + ".cpp");
    if (cppFile.is_open()) {
        cppFile << cppContent;
        cppFile.close();
    } else {
        std::cerr << "Error creating cpp file." << std::endl;
        return;
    }

    std::cout << "Class files " << className << ".hpp and " << className << ".cpp have been created successfully." << std::endl;
}

int main() {
    std::string className;
    std::cout << "Enter the class name: ";
    std::getline(std::cin, className);

    if (!className.empty()) {
        createClassFiles(className);
    } else {
        std::cerr << "Class name cannot be empty." << std::endl;
    }

    return 0;
}
