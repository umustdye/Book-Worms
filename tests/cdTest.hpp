#ifndef __CD_TEST_HPP__
#define __CD_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/cd.hpp"

TEST(CdTest, posTracks)
{
   Cd cd("", 12);
   EXPECT_EQ(cd.getTracks(), 12);
}

TEST(CdTest, negTracks)
{
    Cd cd("", -12);
    EXPECT_EQ(cd.getTracks(), 0);
}

TEST(CdTest, constructor)
{
    Cd cd("Yo Gabba Gabba", 10);
    EXPECT_EQ(cd.getArtist(), "Yo Gabba Gabba");
    EXPECT_EQ(cd.getTracks(), 10);
}

TEST(CdTest, changeValue)
{
    Cd cd("Yo Gabba Gabba", 10);
    cd.setArtist("Muppets Movie Soundtrack");
    cd.setTracks(11);
    EXPECT_EQ(cd.getArtist(), "Muppets Movie Soundtrack");
    EXPECT_EQ(cd.getTracks(), 11);
}
#endif //__CD_TEST_HPP__
