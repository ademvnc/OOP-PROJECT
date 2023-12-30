/**
 * @file
 * @brief This file contains the implementation of the Record class.
 */

#include "Record.h"
#include <stdexcept>

 /**
  * @brief Opens the file for reading and writing.
  * @throw std::runtime_error If the file cannot be opened.
  */
void Record::openFile() {
    fileStream.open(fileName, std::ios::in | std::ios::out | std::ios::app);
    if (!fileStream.is_open()) {
        throw std::runtime_error("Failed to open the file: " + fileName);
    }
}

/**
 * @brief Closes the file if it is open.
 */
void Record::closeFile() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

/**
 * @brief Sets the name of the file to work with.
 * @param name The name of the file.
 */
void Record::setFileName(const std::string& name) {
    fileName = name;
}

/**
 * @brief Reads a line from the file.
 * @return The read line.
 * @throw std::runtime_error If the file cannot be read or end of file is reached.
 */
std::string Record::readLine() {
    std::string line;
    if (getline(fileStream, line)) {
        return line;
    }
    throw std::runtime_error("Failed to read the file or reached end of file.");
}

/**
 * @brief Writes a line to the file.
 * @param line The line to write.
 * @throw std::runtime_error If the file is not open for writing.
 */
void Record::writeLine(const std::string& line) {
    if (fileStream.is_open()) {
        fileStream << line << std::endl;
    }
    else {
        throw std::runtime_error("File is not open for writing.");
    }
}

/**
 * @brief Overload of the << operator to write a line to the file.
 * @param record The Record object.
 * @param line The line to write.
 * @return The Record object.
 */
Record& operator<<(Record& record, const std::string& line) {
    record.writeLine(line);
    return record;
}

/**
 * @brief Overload of the >> operator to read a line from the file.
 * @param record The Record object.
 * @param line The line to read into.
 * @return The Record object.
 */
Record& operator>>(Record& record, std::string& line) {
    line = record.readLine();
    return record;
}
