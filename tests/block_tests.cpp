#include "../tests/doctest/doctest.h"
#include "block.hpp"

TEST_CASE("B 1.01: Konstruktor parametryczny, metody get_... 1")
{
    double tab[3] = {1, 2, 3};
    std::string s = "sname";
    std::string f = "fname";
    Vector3D vec(tab);
    Block a(s, f, vec);

    CHECK(a.get_sample_name() == "sname");
    CHECK(a.get_final_name() == "fname");
    CHECK(a.get_scale() == vec);
}

TEST_CASE("B 1.02: Konstruktor parametryczny, metody get_... 2")
{
    double tab[3] = {0, 0, 0};
    std::string s = "";
    std::string f = "";
    Vector3D vec(tab);
    Block a(s, f, vec);

    CHECK(a.get_sample_name() == "");
    CHECK(a.get_final_name() == "");
    CHECK(a.get_scale() == vec);
}

TEST_CASE("B 1.03: Konstruktor parametryczny, metody get_... 3")
{
    double tab[3] = {1, 2, 3};
    std::string s = "2323gf21f3g1";
    std::string f = "f221`g431`\n";
    Vector3D vec(tab);
    Block a(s, f, vec);

    CHECK(a.get_sample_name() == "2323gf21f3g1");
    CHECK(a.get_final_name() == "f221`g431`\n");
    CHECK(a.get_scale() == vec);
}

TEST_CASE("B 1.04: Konstruktor bezparametryczny, metody get_... 3")
{
    double tab[3] = {1, 1, 1};
    Vector3D vec(tab);
    Block a;

    CHECK(a.get_sample_name() == "");
    CHECK(a.get_final_name() == "");
    CHECK(a.get_scale() == vec);
}

TEST_CASE("B 1.05: Konstruktor parametryczny 2, metody get_... 1")
{
    std::string s = "2323gf21f3g1";
    std::string f = "f221`g431`\n";
    Block a(s, f);

    double tab[3] = {1, 1, 1};
    Vector3D vec(tab);

    CHECK(a.get_sample_name() == "2323gf21f3g1");
    CHECK(a.get_final_name() == "f221`g431`\n");
    CHECK(a.get_scale() == vec);
}

TEST_CASE("B 1.06: Konstruktor parametryczny 2, metody get_... 2")
{
    std::string s = "2323gf21f3g1";
    std::string f = "f221`g431`\n";
    Block a(s, f);

    double tab[3] = {1, 21, 1};
    Vector3D vec(tab);

    CHECK(a.get_sample_name() == "2323gf21f3g1");
    CHECK(a.get_final_name() == "f221`g431`\n");
    CHECK(!(a.get_scale() == vec));
}

TEST_CASE("B 2.01: Metody set_... i metody get_... 1")
{
    Block a;
    double tab[3] = {1, 2, 3};
    std::string s = "2323gf21f3g1";
    std::string f = "f221`g431`\n";
    Vector3D vec(tab);
    a.set_final_name(f);
    a.set_sample_name(s);
    a.set_scale(vec);

    CHECK(a.get_sample_name() == "2323gf21f3g1");
    CHECK(a.get_final_name() == "f221`g431`\n");
    CHECK(a.get_scale() == vec);
}

TEST_CASE("B 2.02: Metody set_... i metody get_... 2")
{
    Block a;
    double tab[3] = {0, 0, 0};
    std::string s = "abc";
    std::string f = "f221`g431`\n";
    Vector3D vec(tab);
    a.set_final_name(f);
    a.set_sample_name(s);
    a.set_scale(vec);

    CHECK(a.get_sample_name() == "abc");
    CHECK(a.get_final_name() == "f221`g431`\n");
    CHECK(a.get_scale() == vec);
}

TEST_CASE("B 3.01: check_block 1")
{
    std::string s = "2323gf21f3g1";
    std::string f = "f221`g431`\n";

    double tab[3] = {1, 21, 1};
    Vector3D vec(tab);

    Block a(s, f, vec);

    CHECK(a.check_block());
}

TEST_CASE("B 3.02: check_block 2")
{
    std::string s = "";
    std::string f = "f221`g431`\n";

    double tab[3] = {1, 21, 1};
    Vector3D vec(tab);

    Block a(s, f, vec);

    CHECK(!a.check_block());
}

TEST_CASE("B 3.03: check_block 3")
{
    std::string s = "2323gf21f3g1";
    std::string f = "";

    double tab[3] = {1, 21, 1};
    Vector3D vec(tab);

    Block a(s, f, vec);

    CHECK(!a.check_block());
}

TEST_CASE("B 3.04: check_block 4")
{
    std::string s = "s";
    std::string f = "f";

    double tab[3] = {1, 21, -1};
    Vector3D vec(tab);

    Block a(s, f, vec);

    CHECK(!a.check_block());
}

TEST_CASE("B 3.05: check_block 5")
{
    std::string s = "s";
    std::string f = "f";

    double tab[3] = {1, -21, 1};
    Vector3D vec(tab);

    Block a(s, f, vec);

    CHECK(!a.check_block());
}

TEST_CASE("B 3.06: check_block 6")
{
    std::string s = "s";
    std::string f = "f";

    double tab[3] = {-1, 21, -1};
    Vector3D vec(tab);

    Block a(s, f, vec);

    CHECK(!a.check_block());
}

TEST_CASE("B 3.07: check_block 7")
{
    std::string s = "s";
    std::string f = "f";

    double tab[3] = {-1, -21, -1};
    Vector3D vec(tab);

    Block a(s, f, vec);

    CHECK(!a.check_block());
}
TEST_CASE("B 3.08: check_block 8")
{
    std::string s = "s";
    std::string f = "f";

    double tab[3] = {0, 0, 0};
    Vector3D vec(tab);

    Block a(s, f, vec);

    CHECK(!a.check_block());
}