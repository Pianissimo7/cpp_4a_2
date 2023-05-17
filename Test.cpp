#include "doctest.h"
#include "Team.hpp"
#include <cmath>

using namespace std;
using namespace ariel;

TEST_CASE("creating each type of class") {
    Point a(0,0);
    Point b(0,1);
    Point c(0,2);
    Point d(0,3);
    CHECK_NOTHROW(Cowboy *tom = new Cowboy("Tom", a));
    CHECK_NOTHROW(YoungNinja *young_sushi = new YoungNinja("young sushi", b));
    CHECK_NOTHROW(TrainedNinja *trained_sushi = new TrainedNinja("trained sushi", c));
    CHECK_NOTHROW(OldNinja *old_sushi = new OldNinja("old sushi", d));
}
TEST_CASE("initializing a team with any character as it's leader is allowed") {
    Point a(0,0);
    Point b(0,1);
    Point c(0,2);
    Point d(0,3);
    
    Cowboy *tom = new Cowboy("Tom", a);
    YoungNinja *young_sushi = new YoungNinja("young sushi", b);
    TrainedNinja *trained_sushi = new TrainedNinja("trained sushi", c);
    OldNinja *old_sushi = new OldNinja("old sushi", d);

    CHECK_NOTHROW(new Team(tom));
    CHECK_NOTHROW(new Team(young_sushi));
    CHECK_NOTHROW(new Team(trained_sushi));
    CHECK_NOTHROW(new Team(old_sushi));
}
TEST_CASE("make sure no character is added twice to a team") {
    Point a(0,0);
    Cowboy *tom = new Cowboy("Tom", a);
    Team team_A(tom);

    CHECK_THROWS(Team(tom));
}

TEST_CASE("point functions check") {
    Point p1 = Point(0, 0);
    Point p2 = Point(0, 1);
    Point p3 = p1.MoveTowards(p1, p2, 0.75);
    double epsilon = 1e-8;

    CHECK(fabs(p1.distance(p3) - 0.75) <= epsilon);
    CHECK(fabs(p3.distance(p1) - 0.75) <= epsilon);
    CHECK(fabs(p2.distance(p3) - 0.25) <= epsilon);
    CHECK(fabs(p3.distance(p2) - 0.25) <= epsilon);
    CHECK(fabs(p2.distance(p1) - 1) <= epsilon);
    CHECK(fabs(p1.distance(p2) - 1) <= epsilon);

    Point p4 = Point(3, 4);
    Point p5 = p1.MoveTowards(p1, p4, 5);
    CHECK(fabs(p4.distance(p5) - 0) <= epsilon);

    Point p6 = p1.MoveTowards(p1, p4, 2.5);
    Point p7 = Point(1.5, 2);
    CHECK(fabs(p6.distance(p7) - 0) <= epsilon);
}
TEST_CASE("Cowboy can only shoot 6 bullets") {
    Point a(0, 0);
    Point b(0, 1);
    
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *target = new OldNinja("dummy", b);
    
    SUBCASE("make sure the cowboy starts out with 6 bullets") {
        for (size_t i = 0 ; i < 6 ; i++) {
            tom->shoot(target);
            CHECK(tom->hasboolets());
        }

        // tom ran out of bullets
        CHECK(!tom->hasboolets());
    }
    SUBCASE("reloading charges 6 bullets") {
        tom->reload();
        CHECK(tom->hasboolets());
        for (size_t i = 0 ; i < 6 ; i++) {
            tom->shoot(target);
            CHECK(tom->hasboolets());
        }

        // tom ran out of bullets
        CHECK(!tom->hasboolets());
    }
}
TEST_CASE("game end") {
    Point a(0,0);
    Point b(0,1);
    Point c(0,2);
    Point d(0,3);
    
    Cowboy *tom = new Cowboy("Tom", a);
    YoungNinja *young_sushi = new YoungNinja("young sushi", b);
    TrainedNinja *trained_sushi = new TrainedNinja("trained sushi", c);
    OldNinja *old_sushi = new OldNinja("old sushi", d);
    
    Team team_A(tom);
    

    SUBCASE("test stillAlive") {
        CHECK_EQ(team_A.stillAlive(), 1);
        team_A.add(young_sushi);
        CHECK_EQ(team_A.stillAlive(), 2);
        team_A.add(trained_sushi);
        CHECK_EQ(team_A.stillAlive(), 3);
        team_A.add(old_sushi);
        CHECK_EQ(team_A.stillAlive(), 4);
    }
    SUBCASE("when the game ends one team must not have any players left alive") {
        Point a(0,0);
        Point b(0,1);
        Point c(0,2);
        Point d(0,3);

        Cowboy *tom1= new Cowboy("Tom", a);
        YoungNinja *young_sushi1 = new YoungNinja("young sushi", b);
        TrainedNinja *trained_sushi1 = new TrainedNinja("trained sushi", c);
        OldNinja *old_sushi1 = new OldNinja("old sushi", d);
        
        Team team_B(tom1);
        
        team_B.add(young_sushi1);
        team_B.add(trained_sushi1);
        team_B.add(old_sushi1);

        size_t counter = 0;
        while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0 && counter < 1000){
            team_A.attack(&team_B);
            team_B.attack(&team_A);
            counter++;
        }
        // a game should end in less than 1000 for sure.
        // this is just to make the program stop incase the game wouldnt normally finish.
        CHECK(!(counter == 1000));
    }
    SUBCASE("check ninja health") {
        Point a(0, 0);
        Point b(0, 0.5);
        Point c(0.5, 0);
        YoungNinja *young_sushi = new YoungNinja("young sushi", a);
        TrainedNinja *trained_sushi = new TrainedNinja("old sushi", b);
        OldNinja *old_sushi = new OldNinja("old sushi", c);

        // young ninja should die after being hit 3 times
        // old ninja should be killed after begin hit 4 times
        CHECK(young_sushi->isAlive());
        trained_sushi->slash(young_sushi);
        trained_sushi->slash(old_sushi);
        CHECK(young_sushi->isAlive());
        trained_sushi->slash(young_sushi);
        trained_sushi->slash(old_sushi);
        CHECK(young_sushi->isAlive());
        trained_sushi->slash(young_sushi);
        trained_sushi->slash(old_sushi);
        CHECK(!young_sushi->isAlive());
        
        trained_sushi->slash(old_sushi);
        CHECK(!old_sushi->isAlive());
    }
}

