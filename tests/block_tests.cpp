#include "../tests/doctest/doctest.h"
#include "block.hpp"

TEST_CASE("B 1.01: Konstruktor parametryczny, metody get_... 1")
{
    double tab[3] = {1,2,3};
    std::string s = "sname";
    std::string f = "fname";
    Vector3D vec(tab);
    Block a(s,f,vec);

    CHECK (a.get_sample_name() == "sname");
    CHECK (a.get_final_name() == "fname");
    CHECK (a.get_scale() == vec);
}

TEST_CASE("B 1.02: Konstruktor parametryczny, metody get_... 2")
{
    double tab[3] = {0,0,0};
    std::string s = "";
    std::string f = "";
    Vector3D vec(tab);
    Block a(s,f,vec);

    CHECK (a.get_sample_name() == "");
    CHECK (a.get_final_name() == "");
    CHECK (a.get_scale() == vec);
}

TEST_CASE("B 1.03: Konstruktor parametryczny, metody get_... 3")
{
    double tab[3] = {1,2,3};
    std::string s = "2323gf21f3g1";
    std::string f = "f221`g431`\n";
    Vector3D vec(tab);
    Block a(s,f,vec);

    CHECK (a.get_sample_name() == "2323gf21f3g1");
    CHECK (a.get_final_name() == "f221`g431`\n");
    CHECK (a.get_scale() == vec);
}

TEST_CASE("B 1.04: Konstruktor bezparametryczny, metody get_... 3")
{
    double tab[3] = {1,1,1};
    Vector3D vec(tab);
    Block a;

    CHECK (a.get_sample_name() == "");
    CHECK (a.get_final_name() == "");
    CHECK (a.get_scale() == vec);
}

TEST_CASE("B 2.01: Metody set_... i metody get_... 1")
{
    Block a;
    double tab[3] = {1,2,3};
    std::string s = "2323gf21f3g1";
    std::string f = "f221`g431`\n";
    Vector3D vec(tab);
    a.set_final_name(f);
    a.set_sample_name(s);
    a.set_scale(vec);

    CHECK (a.get_sample_name() == "2323gf21f3g1");
    CHECK (a.get_final_name() == "f221`g431`\n");
    CHECK (a.get_scale() == vec);
}

TEST_CASE("B 2.02: Metody set_... i metody get_... 2")
{
    Block a;
    double tab[3] = {0,0,0};
    std::string s = "abc";
    std::string f = "f221`g431`\n";
    Vector3D vec(tab);
    a.set_final_name(f);
    a.set_sample_name(s);
    a.set_scale(vec);

    CHECK (a.get_sample_name() == "abc");
    CHECK (a.get_final_name() == "f221`g431`\n");
    CHECK (a.get_scale() == vec);
}