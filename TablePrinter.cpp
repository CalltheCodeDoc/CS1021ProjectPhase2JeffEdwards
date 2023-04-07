#include "TablePrinter.h"

TablePrinter::TablePrinter(const std::vector<std::string>& headers,
    const std::vector<std::vector<std::string>>& data)
    : headers_(headers), data_(data) {
    // Calculate column widths based on the longest entry in each column
    for (const auto& header : headers_) {
        columnWidths_.push_back(header.length());
    }

    for (const auto& row : data_) {
        for (size_t i = 0; i < row.size(); ++i) {
            columnWidths_[i] = std::max(columnWidths_[i], row[i].length());
        }
    }
}

void TablePrinter::displayTable() const {
    // Print header row
    for (size_t i = 0; i < headers_.size(); ++i) {
        std::cout << "| " << std::left << std::setw(columnWidths_[i]) << headers_[i] << " ";
    }
    std::cout << "|" << std::endl;

    // Print separator row
    for (const auto& width : columnWidths_) {
        std::cout << "+-" << std::setw(width) << std::setfill('-') << "" << "-";
        std::cout.fill(' ');
    }
    std::cout << "+" << std::endl;

    // Print data rows
    for (const auto& row : data_) {
        for (size_t i = 0; i < row.size(); ++i) {
            std::cout << "| " << std::left << std::setw(columnWidths_[i]) << row[i] << " ";
        }
        std::cout << "|" << std::endl;
    }
}
