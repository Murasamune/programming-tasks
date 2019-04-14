#include <ostream>

class Guard
{
private:
    std::ostream& gOut;
    std::ostream::fmtflags gFlag;
    char gFill;
public:
    Guard(std::ostream& out){
        gOut = out;
        gFlag = out.flags();
        gFill = out.fill();
    }
    ~Guard(){
        gOut.flags(gFlag);
        gOut.fill(gFill);
    }

    Guard(const Guard&) = delete;
    Guard& operator=(const Guard&) = delete;
};
