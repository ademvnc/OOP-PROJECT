#pragma once

#ifndef RECORD_H
#define RECORD_H

#include "NaoRobotAPI.h"
#include <fstream>
#include <string>

/**
 * @brief The Record class provides functionality for reading and writing data to a file.
 */
class Record {
private:
    std::fstream fileStream; ///< File stream for reading and writing.
    std::string fileName; ///< Name of the file.

public:
    /**
     * @brief Open the file for reading and writing.
     */
    void openFile();

    /**
     * @brief Close the file.
     */
    void closeFile();

    /**
     * @brief Set the name of the file.
     * @param name The name of the file.
     */
    void setFileName(const std::string& name);

    /**
     * @brief Read a line from the file.
     * @return The read line as a string.
     */
    std::string readLine();

    /**
     * @brief Write a line to the file.
     * @param line The line to be written.
     */
    void writeLine(const std::string& line);

    /**
     * @brief Overload the insertion operator to write a line to the file.
     * @param record The Record object.
     * @param line The line to be written.
     * @return A reference to the Record object.
     */
    friend Record& operator<<(Record& record, const std::string& line);

    /**
     * @brief Overload the extraction operator to read a line from the file.
     * @param record The Record object.
     * @param line The string to store the read line.
     * @return A reference to the Record object.
     */
    friend Record& operator>>(Record& record, std::string& line);
};

#endif // RECORD_H
