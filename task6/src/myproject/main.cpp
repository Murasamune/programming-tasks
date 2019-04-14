#include <unordered_map>
#include <unordered_set>
#include <string>
#include <set>
#include <iostream>

namespace My{
    class Account{
    public:
        static int last_id;
        int id;
        std::string firstname;
        std::string lastname;

        Account(std::string _firstname, std::string _lastname){
            last_id++;
            id = last_id;
            firstname = _firstname;
            lastname = _lastname;
        }

        bool operator==(const Account &acc) const{
            return (this->id == acc.id);
        }
        bool operator!=(const Account &acc) const{
            return !(this->id == acc.id);
        }
        bool operator<(const Account &acc) const{
            return (this->id < acc.id);
        }

        ~Account(){}
    };

    class Group{
    public:
        static int last_id;
        int id;
        std::string name;
        std::set<My::Account> accs;

        Group(std::string _name){
            last_id++;
            id = last_id;
            name = _name;
        }

        void newAccount(My::Account acc){
            accs.insert(acc);
        }
        void deleteAccount(My::Account acc){
            accs.erase(acc);
        }

        ~Group(){}
    };

    int Account::last_id = 0;
    int Group::last_id = 0;
}

namespace std {
    template <>
    struct hash<My::Account> {
        size_t operator()(const My::Account &acc) const {
            return static_cast<size_t>(acc.id);
        }
    };

    template <>
    struct hash<My::Group> {
        size_t operator ()(const My::Account &group) const {
            return static_cast <size_t>(group.id);
        }
    };

    template <class T>
    struct Trait;

    template <>
    struct Trait<My::Account> {
        static size_t size(const My::Account &acc) {
            return sizeof(acc.id) + acc.firstname.size() + acc.lastname.size() + sizeof(acc.last_id);
        }
    };

    template <>
    struct Trait<My::Group> {
        static size_t size(const My::Group &group) {
            size_t _size = sizeof(group.id) + group.name.size() + sizeof(group.last_id);
            for (auto iter = group.accs.begin(); iter != group.accs.end(); iter++){
                _size = _size + std::Trait<My::Account>::size(*iter);
            }
            return _size;
        }
    };
}

int main()
{
    My::Account acc1("fn1", "ln1");
    My::Account acc2("fn2", "ln2");

    std::unordered_set<My::Account> usetAcc;
    usetAcc.insert(acc1);
    usetAcc.insert(acc2);

    std::unordered_map<My::Account, int> umapAcc;
    typedef std::unordered_map<My::Account, int> umapType;
    umapAcc.insert(umapType::value_type(acc1, 1));
    umapAcc.insert(umapType::value_type(acc2, 2));

    My::Group grp("group1");
    grp.newAccount(acc1);
    grp.newAccount(acc2);

    std::cout << std::Trait<My::Account>::size(acc1) << "\n";
    std::cout << std::Trait<My::Group>::size(grp) << "\n";

    return 0;
}

