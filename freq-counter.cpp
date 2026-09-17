/**
 * Name:  Ali Alwaily
 * Date:  16 September 2026
 * About: A simple frequency counter (ASCII) for text files.
 */

#include <iostream>
#include <fstream>  // Loads fstream
#include <cstdint>
#include <vector>
#include <cctype>   // Loads isalpha() function

/**
 * This function was copy-pasted from cpp documentation. This is why:
 *
 *  "Like all other functions from <cctype>, the behavior of std::isalpha is
 *   undefined if the argument's value is neither representable as unsigned char
 *   nor equal to EOF. To use these functions safely with plain chars (or signed
 *   chars), the argument should first be converted to unsigned char: "
 *
 * Link: https://en.cppreference.com/cpp/string/byte/isalpha
 *
 * @param ch character
 * @return 1 if parameter is a character from the english alphabet.
 */
bool my_isalpha(char ch) {
    return std::isalpha(static_cast<unsigned char>(ch));
}

/**
 * Main Function
 */
int main(int argc, char* argv[]) {
    // Check if program recieved only two inputs (command + file)
    if(argc != 2) {
        std::cout << "Error: Input a (singular) file!" << std::endl;
        return 1;
    }

    if(argc == 2) {
        // Open file for reading
        std::fstream filein(argv[1], std::ios::in);

        // Check if file was opened (i.e., if valid)
        if(!filein.is_open()) {
            std::cerr << "Error: Unable to open file!" << std::endl;
            return 1;
        }

        // Initialize a vector with a size of 26 filled with zeros
        std::vector<uint32_t> letterCounter(26,0);
        uint32_t total = 0;
        char letter;

        // Parse through the file character-by-character
        while(filein.get(letter)) {
            // If letter is a valid character from the english alphabet
            if(my_isalpha(letter)) {
                ++total;
                ++letterCounter[toupper(letter)-'A'];
            }
        }
        // Print table of frequencies
        std::cout << "A: " << letterCounter[0]    << "\tB: " << letterCounter[1]
                  << "\tC: " << letterCounter[2]  << "\tD: " << letterCounter[3]
                  << "\tE: " << letterCounter[4]  << "\tF: " << letterCounter[5]
                  << "\tG: " << letterCounter[6]  << "\tH: " << letterCounter[7]
                  << "\tI: " << letterCounter[8]  << "\tJ: " << letterCounter[9]
                  << std::endl
                  << "K: " << letterCounter[10]   << "\tL: " << letterCounter[11]
                  << "\tM: " << letterCounter[12] << "\tN: " << letterCounter[13]
                  << "\tO: " << letterCounter[14] << "\tP: " << letterCounter[15]
                  << "\tQ: " << letterCounter[16] << "\tR: " << letterCounter[17]
                  << "\tS: " << letterCounter[18] << "\tT: " << letterCounter[19]
                  << std::endl
                  << "U: " << letterCounter[20]   << "\tV: " << letterCounter[21]
                  << "\tW: " << letterCounter[22] << "\tX: " << letterCounter[23]
                  << "\tY: " << letterCounter[24] << "\tZ: " << letterCounter[25]
                  << std::endl
                  << "Total: " << total << std::endl;

        filein.close();
    }
    return 0;   // EOP
}
