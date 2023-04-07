#pragma once
#ifndef TABLEPRINTER_H
#define TABLEPRINTER_H

#include <vector>
#include <string>
#include <iomanip>
#include <iostream>

class TablePrinter {
public:
    TablePrinter(const std::vector<std::string>& headers,
        const std::vector<std::vector<std::string>>& data);

    void displayTable() const;

private:
    std::vector<std::string> headers_;
    std::vector<std::vector<std::string>> data_;
    std::vector<size_t> columnWidths_;
};

#endif // TABLEPRINTER_H
