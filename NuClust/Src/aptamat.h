
/********************************************
****       NuClust - AptaMat class       ****
**** (c) 2022-2025 - Alessandro Pedretti ****
********************************************/

#include <iostream>
#include <vector>
#include <stdexcept>


/**** Dotbracket class ****/

class Dotbracket {
  private:

        /**** Properties ****/

        HD_LONG                     gap_penalty_matrix[2];
        HDC_String                  dotbracket;
        HD_LONG                     gap;

        /**** Methods ****/

        HD_VOID                     set_dotbracket(const std::string &MyDotbracket, const std::vector<int> &gap_penalty);

public:

        /**** Methods ****/

                                    HD_FASTCALL  Dotbracket(const std::string &dotbracket, const std::vector<int> &gap_penalty);

private:

};


